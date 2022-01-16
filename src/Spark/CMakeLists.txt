set(INCROOT ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME})
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME})

set(SRC
    ${SRCROOT}/Main.cpp

    ${INCROOT}/Engine.hpp
    ${SRCROOT}/Engine.cpp

    ${INCROOT}/ThreadPool.hpp 
    ${SRCROOT}/ThreadPool.cpp

    ${INCROOT}/Object.hpp 
    ${SRCROOT}/Object.cpp
    ${INCROOT}/World.hpp 
    ${SRCROOT}/World.cpp
    ${INCROOT}/Level.hpp 
    ${SRCROOT}/Level.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCROOT})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)