#include <iostream>

using std::cout;

int main() {
    int Array1[] = {1, 2, 3, 4, 5};
    int Array2[] = {6, 7, 8, 9, 10, 11, 12};
    int *mergePointer = NULL;
    size_t s1 = sizeof(Array1)/sizeof(Array1[0]);
    size_t s2 = sizeof(Array2)/sizeof(Array2[0]);
    mergePointer = new int[s1+s2];

    for (size_t i = 0; i < s1; ++i)
        *(mergePointer + i) = Array1[i];

    for (size_t i = 0; i < s2; ++i)
        *((mergePointer+s1) + i) = Array2[i];

    for (size_t i = 0; i < s1+s2; ++i)
        cout << *(mergePointer + i) << " ";
}

int main() {
    int Array1[] = {1, 2, 3, 4, 5};
    int Array2[] = {6, 7, 8, 9, 10, 11, 12};
    int *mergePointer = NULL;
    size_t size1 = sizeof(Array1)/sizeof(Array1[0]);
    size_t size2 = sizeof(Array2)/sizeof(Array2[0]);
    mergePointer = new int[size1+size2];

    for (size_t i = 0, j = 0; i < size1+size2; ++i)
        if (i < size1)
            *(mergePointer + i) = Array1[i];

        else {
            *(mergePointer + i) = Array2[j];
            ++j;
        }

    for (size_t i = 0; i < size1+size2; ++i)
        cout << *(mergePointer + i) << " ";
}