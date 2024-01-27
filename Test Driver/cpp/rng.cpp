#include <iostream>
#include <random>
#include <chrono>

int main() {
    auto inclusive_min = -69.420;
    auto inclusive_max = 420.69;

    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> dist(inclusive_min, inclusive_max);
    for (int i = 0; i < 30; ++i) 
        std::cout << dist(gen) << '\n';
}