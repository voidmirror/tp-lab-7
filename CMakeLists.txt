cmake_minimum_required(VERSION 2.8)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME task1) 
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

#----------------------------------------------------------------------------
# Define project sources and includes
#----------------------------------------------------------------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

set(SRC_FILES ${PROJECT_SOURCE_DIR}/src/ocean.cpp
              ${PROJECT_SOURCE_DIR}/src/stone.cpp
              ${PROJECT_SOURCE_DIR}/src/prey.cpp
              ${PROJECT_SOURCE_DIR}/src/predator.cpp
              ${PROJECT_SOURCE_DIR}/src/cell.cpp
              ${PROJECT_SOURCE_DIR}/src/main.cpp
              ${PROJECT_SOURCE_DIR}/src/object.cpp)

set(CMAKE_CXX_STANDARD 14)

add_library(task1_lib ${SRC_FILES})
add_executable(task1 ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(task1 task1_lib)