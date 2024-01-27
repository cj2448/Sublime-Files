#include <iostream>
#include "vector/vector.h"
// #include <vector>
// #include <cmath>

int main() {
    std::vector<int> s{1, 2, 3, 4, 5};
    for (auto i = 0; i < s.size(); ++i)
        std::cout << s[i] << ' ';
}