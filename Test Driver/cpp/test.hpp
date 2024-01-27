#pragma once
#ifndef RANDOM_HPP
#define RANDOM_HPP

// #include <bits/stdc++.h>
#include <cstdlib>
#include <cstdint>

class Random {
private:
    uint32_t seed;

public:
    setSeed(const uint32_t& seed);
    generate_random_int(const int& min, const int& max);
    generate_random_float(const double& min, const double& max);

    Random(const uint32_t& seed = time(0));
    ~Random();
};

Random::Random(const uint32_t& seed) : seed(seed) {  }
Random::~Random() = default;

#endif