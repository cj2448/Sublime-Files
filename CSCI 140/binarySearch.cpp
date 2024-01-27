#include <bits/stdc++.h>

using std::vector;
using std::cout;

int binarySearch(vector<int> v, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (v[m] == x)
            return m;

        if (v[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }
  
    return -1;
}
  
int main(void)
{
    vector<int> v = { 2, 3, 4, 10, 40 };
    int result = binarySearch(v, 0, v.size()-1, 10);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}