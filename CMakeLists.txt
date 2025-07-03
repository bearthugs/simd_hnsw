cmake_minimum_required(VERSION 3.10)
project(simd_hnsw)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Base include dir (optional if utils.h is directly in source tree)
include_directories(${CMAKE_SOURCE_DIR})

# --- Include HNSWLIB ---
# e.g., #include "libraries/hnswlib/hnswlib.h"
include_directories(${CMAKE_SOURCE_DIR}/libraries/hnswlib)

# --- Include FAISS ---
# e.g., #include "libraries/faiss/IndexFlat.h"
#include_directories(${CMAKE_SOURCE_DIR}/libraries/faiss) # Some headers live in faiss/faiss

# --- Include ScaNN ---
# e.g., #include "libraries/scann/scann/base/search_parameters.h"
include_directories(${CMAKE_SOURCE_DIR}/libraries/scann)

# Add benchmarks subdirectory
add_subdirectory(benchmarks)
