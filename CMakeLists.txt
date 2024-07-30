cmake_minimum_required(VERSION 3.10)
project(SimpleCIProject)

set(CMAKE_CXX_STANDARD 17)

# Define the library target
add_library(Library STATIC src/src/sum.cpp)

# Specify the include directories for the library
target_include_directories(Library PUBLIC "${PROJECT_SOURCE_DIR}/src/include")

# Define the executable target
add_executable(${PROJECT_NAME} src/src/main.cpp)

# Link the executable with the library
target_link_libraries(${PROJECT_NAME} PRIVATE Library)

# find_package(Catch2 3 REQUIRED)
# if(NOT TARGET Catch2::Catch2)
#     include_directories("/home/anoj/Catch2/src/catch2") # Update to your Catch2 path
# endif()

add_executable(TestSum tests/test_script.cpp)
target_link_libraries(TestSum PRIVATE Library)

# Include Catch2 for testing

include_directories(${PROJECT_SOURCE_DIR}/tests) # Adjust if Catch2 is in a different location

# Add tests
enable_testing()
add_test(NAME TestSum COMMAND TestSum)

