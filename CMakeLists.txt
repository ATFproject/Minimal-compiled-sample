# Set up cmake and c++ settings
cmake_minimum_required(VERSION 3.8)
project(sfml_tank_battleroyale LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directory for the binary and disable shared library building
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Include tools for content fetching
include(ExternalProject REQUIRED)
include(FetchContent REQUIRED)

# Fetch and compile SFML library
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Fetch and compile Box2D library
FetchContent_Declare(box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v2.4.1)
FetchContent_MakeAvailable(box2d)

# Get all cpp files in the project recursively to a variable
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add all cpp files to compilation and add prefix
set(OUT_FILE_NAME ${PROJECT_NAME}-${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML and Box2D to final binary and set C++ standard for it
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics PRIVATE box2d)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${OUT_FILE_NAME})

# Add header dirs for easier usage
target_include_directories(${PROJECT_NAME} PRIVATE "src/game" "src/window")

# Compile and link the app
install(TARGETS ${PROJECT_NAME})
