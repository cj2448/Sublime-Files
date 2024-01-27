#include <iostream>

namespace first {
    int num = 10;
}

namespace second {
    int num = 20;
}

int main() {
    std::cout << first::num;
    std::cout << second::num;
}