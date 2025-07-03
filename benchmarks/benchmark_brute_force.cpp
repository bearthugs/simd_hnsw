#include <iostream>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <queue>
#include "../utils.h"

float l2_distance(const float* a, const float* b, int dim) {
    float sum = 0;
    for (int i = 0; i < dim; ++i)
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    return sum;
}

int main() {
    const int dim = 128;
    const int num_elements = 10000;
    const int k = 10;

    auto data = generate_data(num_elements, dim);

    // (Optional) Time data preparation/construction — here trivial, so just 0s
    auto start_construction = std::chrono::high_resolution_clock::now();
    // For brute-force, no index construction is needed
    auto end_construction = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> construction_time = end_construction - start_construction;
    std::cout << "Brute-force construction time: " << construction_time.count() << " s" << std::endl;

    // Time querying
    auto start = std::chrono::high_resolution_clock::now();

    for (int q = 0; q < 100; ++q) {
        std::priority_queue<std::pair<float, int>> topk;
        for (int i = 0; i < num_elements; ++i) {
            float dist = l2_distance(data[q].data(), data[i].data(), dim);
            if ((int)topk.size() < k) {
                topk.push({dist, i});
            } else if (dist < topk.top().first) {
                topk.pop();
                topk.push({dist, i});
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> query_time = end - start;

    std::cout << "Brute-force average query time: " << (query_time.count() / 100) * 1e3 << " ms" << std::endl;
}
