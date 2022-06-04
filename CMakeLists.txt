cmake_minimum_required(VERSION 3.12)

project(Cerelatis)
set(Project Cerelatis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

message(STATUS "[Compiler version]: " ${CMAKE_CXX_COMPILER_ID} "-" ${CMAKE_CXX_COMPILER_VERSION} )
message(STATUS "[Compiler flags]: " ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} \n )

add_subdirectory(Cerelatis-Core)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/Cerelatis-Core/includes
)

add_executable(${Project} main.cpp)
target_link_libraries(${Project} Cerelatis-core-lib)
