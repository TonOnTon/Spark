#include "ThreadPool.hpp"

static ThreadPool g_threadPool;

ThreadPool::ThreadPool()
{
    m_stop = false;

    for (std::size_t i = 0; i < std::thread::hardware_concurrency(); i++)
    {
        m_threads.emplace_back([this]() {
            while (true)
            {
                std::function<void()> task;

                {
                    std::unique_lock<std::mutex> lock(m_mutex);

                    m_eventNewTask.wait(lock, [this]() {
                        return m_stop || !m_tasks.empty();
                    });

                    if (m_stop && m_tasks.empty())
                        return;

                    task = std::move(m_tasks.front());
                    m_tasks.pop();
                }

                task();
            }
        });
    }
}

ThreadPool::~ThreadPool()
{
    m_stop = true;

    m_eventNewTask.notify_all();

    for (auto& thread : m_threads)
    {
        thread.join();
    }
}