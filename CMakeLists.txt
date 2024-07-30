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

include(FetchContent)
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.x # Use a specific version or branch
)
FetchContent_MakeAvailable(catch)

add_executable(TestSum tests/test_script.cpp)
target_link_libraries(TestSum PRIVATE Library Catch2::Catch2)

# Include Catch2 for testing

include_directories(${PROJECT_SOURCE_DIR}/tests) # Adjust if Catch2 is in a different location

# Add tests
enable_testing()
add_test(NAME TestSum COMMAND TestSum)

