# Set up cmake and c++ settings
cmake_minimum_required(VERSION 3.27)
project(sfml_tank_battleroyale LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# Set output directory for the binary and disable shared library building
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Fetch and compile SFML library
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Get all cpp files in the project recursively to a variable
file(GLOB_RECURSE SOURCES "src/*.cpp")
# Add all cpp files to compilation
add_executable(sfml_tank_battleroyale ${SOURCES})

# Link SFML to final binary and set C++ standard for it
target_link_libraries(sfml_tank_battleroyale PRIVATE sfml-graphics)
target_compile_features(sfml_tank_battleroyale PRIVATE cxx_std_20)

# Add header dirs for easier usage
target_include_directories(sfml_tank_battleroyale PRIVATE "src/game" "src/window")

# Compile and link the app
install(TARGETS sfml_tank_battleroyale)
