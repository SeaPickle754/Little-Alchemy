cmake_minimum_required(VERSION 3.16)
project(LittleAlchemy)

set(CMAKE_CXX_STANDARD 17)
# Default to Debug build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

find_package(SFML 3 REQUIRED COMPONENTS Graphics Network Window Audio System)

# Gather all .cpp files in current directory
file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Gather all .cpp files in ui/ directory
file(GLOB UI_FILES "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.cpp")

# Combine them
set(ALL_SOURCES ${SRC_FILES} ${UI_FILES})

add_executable(little-alchemy ${ALL_SOURCES})
set_target_properties(little-alchemy PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/Debug"
)
target_link_libraries(little-alchemy SFML::Graphics SFML::Network SFML::Window SFML::Audio SFML::System)