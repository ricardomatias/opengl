# Default C++ in vscode

## Conan

* `conan search "imgui*" --remote=conan-center`
* `cd build && conan install ..` or `conan install --build imgui`
* `conan inspect glm/0.9.9.4@g-truc/stable`

### Add to `conanfile.txt`

```
[requires]
glm/0.9.9.4@g-truc/stable
```

## CMake configuration

### Add library from `/usr/local`

```cmake
# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

target_link_libraries(
    ${APP_TARGET}
    CONAN_PKG::glfw
    CONAN_PKG::glm
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
)
``` 

### Add external library to be compiled

```cmake
# include directory before executable
add_subdirectory(vendor)

add_executable(${APP_TARGET} src/main.cpp ${source_files})

target_link_libraries(${APP_TARGET} stb_image)
``` 

#### Add to the vendor CMakeLists.txt

```cmake
add_library(stb_image INTERFACE)

target_include_directories(stb_image INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
```

### Include external resources

```cmake
file(COPY res DESTINATION ${CMAKE_BINARY_DIR}/bin)

target_include_directories(${APP_TARGET} PRIVATE res)
```

