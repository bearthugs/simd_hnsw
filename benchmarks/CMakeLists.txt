add_executable(benchmark_hnswlib benchmark_hnswlib.cpp)
#add_executable(benchmark_faiss benchmark_faiss.cpp)
add_executable(benchmark_brute_force benchmark_brute_force.cpp)

# Link libraries if needed (e.g., pthread for FAISS)
find_package(Threads REQUIRED)
#target_link_libraries(benchmark_faiss PRIVATE Threads::Threads)
