cmake_minimum_required(VERSION 3.10)

project(ogamalBreakout)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Use pkg-config to find SDL2 and SDL2_mixer
include(FindPkgConfig)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)

set(CMAKE_CXX_FLAGS "-g -Wall")

include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${SDL2_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})

file(GLOB ogamalBreakout_SRC
    "*.h"
    "*.cpp"
)

add_executable(ogamalBreakout ${ogamalBreakout_SRC})

target_link_libraries(ogamalBreakout 
    ${OPENGL_LIBRARIES} 
    ${GLUT_LIBRARIES} 
    ${SDL2_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
)