#include <iostream>

using std::cout;

template <class T>
void swap(T& x,T& y)
{
     T temp;
     temp=x;
     x=y;
     y=temp;
}
 
int main() {
    int i = 1, j = 2;
    swap(i, j);
    cout << 
}