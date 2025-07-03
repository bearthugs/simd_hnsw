#include <iostream>
#include <chrono>
#include <faiss/IndexFlat.h>
#include "../utils.h"

int main() {
    const int dim = 128;
    const int num_elements = 10000;
    const int k = 10;

    auto data = generate_data(num_elements, dim);
    std::vector<float> flat_data;
    for (const auto& vec : data)
        flat_data.insert(flat_data.end(), vec.begin(), vec.end());

    faiss::IndexFlatL2 index(dim);
    index.add(num_elements, flat_data.data());

    std::vector<faiss::idx_t> indices(100 * k);
    std::vector<float> distances(100 * k);

    std::vector<float> query;
    for (int i = 0; i < 100; ++i)
        query.insert(query.end(), data[i].begin(), data[i].end());

    auto start = std::chrono::high_resolution_clock::now();

    index.search(100, query.data(), k, distances.data(), indices.data());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "FAISS average query time: " << (diff.count() / 100) * 1e3 << " ms" << std::endl;
}
