cmake_minimum_required(VERSION 3.10)

project(ogamalBreakout)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Find SDL2 and SDL2_mixer
find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)

set(CMAKE_CXX_FLAGS "-g -Wall")

include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${SDL2_INCLUDE_DIRS})

file(GLOB ogamalBreakout_SRC
    "*.h"
    "*.cpp"
)

add_executable(ogamalBreakout ${ogamalBreakout_SRC})

target_link_libraries(ogamalBreakout 
    ${OPENGL_LIBRARIES} 
    ${GLUT_LIBRARIES} 
    ${SDL2_LIBRARIES}
    SDL2_mixer
)
