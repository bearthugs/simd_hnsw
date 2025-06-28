add_executable(benchmark benchmark.cpp)

# Link the local hnswlib folder
target_include_directories(benchmark PRIVATE ${CMAKE_SOURCE_DIR}/hnswlib)
