#include <iostream>

int main() {
    const int a = 10;
    const int *ptr = &a;  // ptr is a pointer to constant int 
    // *ptr = 5; // wrong
    ptr++;    // right

    int b = 10;
    int *const ptr = &b;  // ptr is a constant pointer to int
    *ptr = 5; // right
    // constptr++;    // wrong
}
