cmake_minimum_required(VERSION 3.10)
project(simd_hnsw)

# Include hnswlib headers
include_directories(${CMAKE_SOURCE_DIR}/hnswlib)

# Add the benchmarks subdirectory
add_subdirectory(benchmarks)
clang++ --version
