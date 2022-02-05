set(INCROOT ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME})
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME})

set(SRC
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

    ${INCROOT}/Camera.hpp
    ${SRCROOT}/Camera.cpp
    ${INCROOT}/TileMap.hpp
    ${SRCROOT}/TileMap.cpp
)

add_library(${PROJECT_NAME} STATIC ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCROOT})

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-system sfml-window sfml-graphics sfml-audio sfml-network)