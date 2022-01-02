project(Game)

set(INCROOT ${CMAKE_SOURCE_DIR}/include/Game)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/Game)

set(SRC 
    ${SRCROOT}/Main.cpp
    
    ${INCROOT}/Game.hpp
    ${SRCROOT}/Game.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCROOT})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
