
# C++ CI Project

This project is a simple C++ application that demonstrates Continuous Integration (CI) using GitHub Actions. It includes a basic `add_num` function that adds two integers, along with tests written using the Catch2 framework. The CI pipeline is configured in the `.github/workflows/.ci.yml` file.

## Project Structure

```
├── .github
│   └── workflows
│       └── .ci.yml          # CI configuration file for GitHub Actions
├── CMakeLists.txt           # CMake configuration file (if present)
├── src
│   ├── src
│   │   ├── main.cpp         # Main application entry point
│   │   └── sum.cpp          # Implementation of the `add_num` function
│   └── include
│       └── sum.h            # Header file for the `add_num` function
├── tests
│   └── test_scripts.cpp     # Unit tests for the `add_num` function
└── README.md                # This README file
```

## Getting Started

### Prerequisites

- **C++ Compiler**: Ensure you have a C++ compiler installed, like `g++` or `clang++`.
- **CMake**: The project uses CMake to manage the build process. Install CMake version `3.24.1` or higher.
- **Catch2**: The unit tests are written using the Catch2 framework. Make sure it is available in your environment.

### Building the Project

1. **Clone the repository:**

   ```bash
   git clone https://github.com/Anojyadav/simple_cicd.git
   cd simple_cicd
   ```

2. **Build the project:**

   ```bash
   cmake -B build -S .
   cmake --build build
   ```

### Running the Application

After building the project, you can run the executable:

```bash
./build/your_executable_name
```

Replace `your_executable_name` with the actual name of the generated executable.

### Running Tests

To run the unit tests, use the following command:

```bash
cd build
ctest --output-on-failure
```

This will execute the tests defined in `test_scripts.cpp` and output any failures.

### Continuous Integration

The CI pipeline is configured in the `.github/workflows/.ci.yml` file and will automatically run on each push and pull request to the `main` branch. The pipeline performs the following tasks:

1. **Checkout code**: Retrieves the latest code from the repository.
2. **Set up CMake**: Installs CMake version `3.24.1`.
3. **Configure CMake**: Configures the project with CMake.
4. **Build**: Builds the project.
5. **Run Tests**: Executes the unit tests using `ctest`.
6. **Upload Build Artifacts**: Uploads the build artifacts to the GitHub Actions workspace.

### Adding More Tests

You can add more tests to the `test_scripts.cpp` file using the Catch2 framework. Each test case should be defined with the `TEST_CASE` macro, as shown in the example below:

```cpp
TEST_CASE("Another test case", "[sum]") {
    REQUIRE(add_num(5, 7) == 12);
}
```

### Customizing CI

To customize the CI pipeline, modify the `.github/workflows/.ci.yml` file as needed. You can change the build settings, test configurations, or add new steps according to your requirements.
