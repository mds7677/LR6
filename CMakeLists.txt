
cmake_minimum_required(VERSION 3.28)
project(MyProject)
set(CMAKE_CXX_STANDART 20)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

#output app name and input .cpp name
add_executable(tests_app tests_app.cpp)
target_link_libraries(tests_app ${GTEST_LIBRARIES})
enable_testing()
add_test(add Google)