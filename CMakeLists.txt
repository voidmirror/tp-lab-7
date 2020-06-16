cmake_minimum_required(VERSION 2.8)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME ocean) 
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
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)


set(SRC_FILES ${PROJECT_SOURCE_DIR}/src/Ocean.cpp
              ${PROJECT_SOURCE_DIR}/src/Cell.cpp
              ${PROJECT_SOURCE_DIR}/src/Prey.cpp
              ${PROJECT_SOURCE_DIR}/src/Predator.cpp
              ${PROJECT_SOURCE_DIR}/src/Factory.cpp)

set(CMAKE_CXX_STANDARD 11)

add_library(ocean_lib ${SRC_FILES})
add_executable(ocean ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(ocean ocean_lib)