#include <iostream>
#include <chrono>
#include "libraries/hnswlib/hnswlib/hnswlib.h"
#include "../utils.h"

int main() {
    const int dim = 128;
    const int num_elements = 10000;
    const int k = 10;

    auto data = generate_data(num_elements, dim);
    hnswlib::L2Space space(dim);

    // Time construction
    auto start_construction = std::chrono::high_resolution_clock::now();
    hnswlib::HierarchicalNSW<float> index(&space, num_elements);

    for (int i = 0; i < num_elements; ++i)
        index.addPoint(data[i].data(), i);
    auto end_construction = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> construction_time = end_construction - start_construction;
    std::cout << "HNSWLib index construction time: " << construction_time.count() << " s" << std::endl;

    // Time querying
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; ++i) {
        auto result = index.searchKnn(data[i].data(), k);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> query_time = end - start;
    std::cout << "HNSWLib average query time: " << (query_time.count() / 100) * 1e3 << " ms" << std::endl;
}
