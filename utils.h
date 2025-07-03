// utils.h
#pragma once
#include <vector>
#include <random>

// Generate `num` random vectors, each of dimension `dim`
// Values are in the range [0.0, 1.0)
inline std::vector<std::vector<float>> generate_data(int num, int dim) {
    std::vector<std::vector<float>> data(num, std::vector<float>(dim));
    std::mt19937 rng(42);  // fixed seed for reproducibility
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    for (auto& vec : data)
        for (auto& val : vec)
            val = dist(rng);

    return data;
}
