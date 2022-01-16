#pragma once

#include <atomic>
#include <condition_variable>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <vector>

class ThreadPool
{
public:
    ThreadPool();
    ~ThreadPool();

    template <typename Func, typename... Args>
    auto enqueue(Func&& func, Args&&... args) -> std::future<decltype(func(args...))>
    {
        using return_type = std::future<decltype(func(args...))>;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(func), std::forward<Args>(args...)));
        std::future<return_type> result = task->get_future();

        {
            std::unique_lock<std::mutex>(m_mutex);
            
            m_tasks.emplace([task]() {
                (*task)();
            });
        }

        m_eventNewTask.notify_one();

        return result;
    }

private:
    std::vector<std::thread>          m_threads;
    std::queue<std::function<void()>> m_tasks;

    std::mutex              m_mutex;
    std::condition_variable m_eventNewTask;

    std::atomic<bool> m_stop;
};

extern ThreadPool g_threadPool;