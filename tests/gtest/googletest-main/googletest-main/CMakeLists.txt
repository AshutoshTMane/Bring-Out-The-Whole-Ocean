cmake_minimum_required(VERSION 3.10)
project(StudentProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add Google Test
add_subdirectory(tests/gtest/googletest-main)

# Include directories
include_directories(tests/gtest/googletest-main/googletest-main/include)

# Include your source directory
include_directories(include)

# Add the test executable
add_executable(StudentTests tests/student_class_test.cpp)

# Link Google Test libraries to the test executable
target_link_libraries(StudentTests gtest gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME StudentTests COMMAND StudentTests)
