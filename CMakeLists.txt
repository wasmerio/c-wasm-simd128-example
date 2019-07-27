cmake_minimum_required(VERSION 2.8.12)

project(particle-repl)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

message(STATUS "Building in ${CMAKE_BUILD_TYPE} mode")
message(STATUS "Building with ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION} on ${CMAKE_SYSTEM}")

set(CMAKE_CXX_FLAGS "$ENV{CFLAGS} -O2")

add_executable(particle-repel-simd.wasm
    particle-repel.cc
)
set_target_properties(particle-repel-simd.wasm PROPERTIES COMPILE_FLAGS "-msimd128")

add_executable(particle-repel.wasm
    particle-repel.cc
)
