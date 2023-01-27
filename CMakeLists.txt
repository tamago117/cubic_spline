cmake_minimum_required(VERSION 3.1)
project(cubic_spline)

## Compile as C++11
add_compile_options(-std=c++14)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

#find_package(Python3 COMPONENTS Interpreter Development)
find_package(PythonLibs REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PYTHON_INCLUDE_DIRS}
)

add_library(CUBIC_SPLINE SHARED
    src/cubic_spline1d.cpp
    src/cubic_spline2d.cpp
)
target_link_libraries(CUBIC_SPLINE
    Eigen3::Eigen
)

add_executable(${PROJECT_NAME}
    main.cpp
)
target_link_libraries(${PROJECT_NAME}
    ${PYTHON_LIBRARIES}
    CUBIC_SPLINE
)

# Testing
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Test
    test/cubicspline_test.cpp
)
target_link_libraries(Test
    gtest_main
    CUBIC_SPLINE
)
add_test(NAME MyTest COMMAND Test)
enable_testing()