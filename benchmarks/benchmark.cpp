#include "hnswlib/hnswlib.h"
#include <chrono>
#include <iostream>

int main() {
    size_t dim = 128;               // Dimension of vectors
    size_t num_elements = 10000;    // Dataset size

    // Create space (L2 distance)
    hnswlib::L2Space l2space(dim);
    hnswlib::HierarchicalNSW<float> index(&l2space, num_elements);

    // Generate random vectors
    std::vector<std::vector<float>> data(num_elements, std::vector<float>(dim));
    for (auto& vec : data) {
        for (float& x : vec) {
            x = static_cast<float>(rand()) / RAND_MAX;
        }
    }

    // Timing insertion
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < num_elements; i++) {
        index.addPoint(data[i].data(), i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Insertion time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    // Timing a query
    start = std::chrono::high_resolution_clock::now();
    auto result = index.searchKnn(data[0].data(), 10);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Query time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " μs\n";

    return 0;
}
