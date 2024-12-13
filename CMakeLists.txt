# This is the CMakeLists for my graphics library test to try and get glut to work

cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_CXX_STANDARD 14)
project(graphicLibTest)

include(CTest)
enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include) # include header files

# Dependencies
find_package(OpenGL REQUIRED)
include(FetchContent)
FetchContent_Declare(
glfw
GIT_REPOSITORY https://github.com/glfw/glfw
)
FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
FetchContent_Populate(glfw)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example
programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test
programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()
FetchContent_Declare(
glew
GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
)
FetchContent_MakeAvailable(glew)

# Our Project
set(SOURCE_FILES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw libglew_static)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${CMAKE_PROJECT_NAME}
"${CMAKE_SOURCE_DIR}/lib/freeglut.lib")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})