cmake_minimum_required(VERSION 3.1)
project(cubic_spline)

## Compile as C++11
add_compile_options(-std=c++14)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

#find_package(Python3 COMPONENTS Interpreter Development)
find_package(PythonLibs REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PYTHON_INCLUDE_DIRS}
                    )

add_library(CUBIC_SPLINE SHARED
    src/cubic_spline1d.cpp
    src/cubic_spline2d.cpp
)
add_executable(
    ${PROJECT_NAME} main.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${PYTHON_LIBRARIES}
    CUBIC_SPLINE
)