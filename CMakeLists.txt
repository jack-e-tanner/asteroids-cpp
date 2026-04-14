cmake_minimum_required(VERSION 3.14)
project(OOP_Survival)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(Game ${GAME_SOURCES})
target_include_directories(Game PRIVATE include)
target_link_libraries(Game PRIVATE sfml-graphics sfml-window sfml-system)
