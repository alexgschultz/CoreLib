# CoreLib

**Version 1.0**

[Português](README.pt-BR.md)

CoreLib is a reusable C++ library developed as a study and portfolio project.

Its goal is to provide simple and reusable functionality for other C++ projects while keeping the architecture small and avoiding unnecessary complexity.

## Features

### Logger

Simple logging system with multiple levels:

- `Debug`
- `Info`
- `Warning`
- `Error`

It supports minimum log level filtering and timestamps.

### File

File and directory utilities based on `std::filesystem`.

- Check whether a path exists
- Check whether a path is a file
- Check whether a path is a directory
- Create files
- Create directories
- Remove files
- Remove directories

### Config

Simple configuration system using files in the following format:

```text
key=value
```

Features:

- Set values
- Retrieve values
- Check whether a key exists
- Load configuration files
- Save configuration files
- Ignore empty lines
- Support comments starting with `#`
- Trim unnecessary whitespace

Example:

```text
name=CoreLib
author=Alex
version=1.0
```

## Technologies

- C++20
- CMake
- CTest
- STL
- `std::filesystem`
- `std::map`
- `std::optional`
- `std::string_view`
- `std::error_code`
- Git

## Project Structure

```text
CoreLib/
├── CMake/
├── include/
│   └── core/
│       ├── Config.hpp
│       ├── File.hpp
│       ├── Logger.hpp
│       └── core.hpp
├── src/
│   ├── Config.cpp
│   ├── File.cpp
│   ├── Logger.cpp
│   └── core.cpp
├── tests/
│   └── CoreLibTest.cpp
├── config.txt
├── CMakeLists.txt
└── .gitignore
```

## Build

The project uses CMake.

Configure the project:

```bash
cmake -S . -B build
```

Build the Debug configuration:

```bash
cmake --build build --config Debug
```

## Tests

CoreLib uses CTest to execute its test program.

Run:

```bash
ctest --test-dir build -C Debug --output-on-failure
```

A successful execution should report:

```text
100% tests passed out of 1
```

The test executable also uses an internal helper to compare actual and expected results:

```cpp
check(config.has("missing"), false, "Config::has (chave inexistente)");
```

## Project Goals

CoreLib was developed to practice and consolidate C++ development concepts such as:

- Library organization
- Separation between headers and implementation files
- CMake
- CTest
- STL
- File handling
- Error handling
- Testing
- Code organization
- Reusable components

The library may evolve when real reusable needs appear in future projects.