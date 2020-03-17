cmake_minimum_required(VERSION 2.8)

project(ImacGL)

add_definitions(-std=c++17)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# require Eigen
find_package(Eigen3 REQUIRED)
if(${EIGEN3_FOUND})
    message(STATUS "lib EIGEN3 found")
    message(STATUS "  version " ${EIGEN3_VERSION_STRING})
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
endif()

# require lib c3ga
find_package(C3GA)
if(${C3GA_FOUND})
    message(STATUS "lib C3GA found")
    message(STATUS "  include " ${C3GA_INCLUDE_DIRS})
    message(STATUS "  lib     " ${C3GA_LIBRARIES})
else()
    message(STATUS "lib C3GA should be set manually, please uncomment the commented lines in the CMakeLists.txt file")
    #set(C3GA_INCLUDE_DIRS "[path to]/garamon_c3ga/src/")
    set(C3GA_INCLUDE_DIRS "/usr/local/include/c3ga/")
    #set(C3GA_LIBRARIES "[path to]/garamon_c3ga/build/libc3ga.dylib")
    set(C3GA_LIBRARIES "/usr/local/lib/libc3ga.so")

    # for manual setting, check if valid
    if(EXISTS "${C3GA_INCLUDE_DIRS}")
        message(STATUS "include for lib c3ga found: ${C3GA_INCLUDE_DIRS}" )
    else()
        message(FATAL_ERROR "include for lib c3ga invalid or not found: ${C3GA_INCLUDE_DIRS}" )
    endif()

    # for manual setting, check if valid
    if(EXISTS "${C3GA_LIBRARIES}")
        message(STATUS "library c3ga found: ${C3GA_LIBRARIES}" )
    else()
        message(FATAL_ERROR "library c3ga not found: ${C3GA_LIBRARIES}" )
    endif()
endif()

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include third-party/include)
include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${C3GA_INCLUDE_DIRS})

set(ALL_LIBRARIES glimac ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})

add_subdirectory(glimac)

file(GLOB TP_DIRECTORIES "Main")

foreach(TP ${TP_DIRECTORIES})
    add_subdirectory(${TP})
endforeach()
