#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

void n_Permuation_Complexity(string s = "test", string subset = "");     // O(n!) aka Factorial time
int int_Squared_n_Complexity(int n);                 // O(2^n) aka Exponential time
void n_Squared_Complexity(int n);                    // O(n^2) aka Quadratic time 
void n_Logn_Complexity(int n);                       // O(n log n) aka Linearithmic time     
void n_Complexity(int n);                            // O(n) aka linear time
void logn_Complexity(int n);                         // O(log n) aka Logarithmic time
void constant_time_Complexity();                     // O(1) aka Constant and the fastest possible algorithm

int main() {
   n_Permuation_Complexity();
   // cout << int_Squared_n_Complexity(3) << '\n';
   // n_Squared_Complexity(4);
   // n_Logn_Complexity(4);
   // n_Complexity(10);
   exit(EXIT_SUCCESS);
}

void n_Permuation_Complexity(string s, string subset) {
   // Example: Finding every single permutation of a word
    if(s.length() == 0)
    {
        cout<<subset<<"\n";
        return;
    }
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0,i);
        string right_substr = s.substr(i+1);
        string rest = left_substr + right_substr;
        n_Permuation_Complexity(rest , subset+ch);
    }
}

int int_Squared_n_Complexity(int n) {
   // Example: Fibonacci Sequence (1, 1, 2, 3, 5, 8, 13, 21, 34, 55)
   if (n <= 1)
      return n;

   else
      return int_Squared_n_Complexity(n - 1) + int_Squared_n_Complexity(n - 2);

//     t(n-1)       +   t(n-2)        2^1=2
//       |                |  
// t(n-2)+t(n-3)  t(n-3)+t(n-4)       2^2=4  
//       .               .            2^3=8
//       .               .              .
}

void n_Squared_Complexity(int n) {
   // Example: Traversing a 2-d array to find the min value
   int v[n][n];
   int min = v[0][0];
   srand((unsigned) time(0));

   for (int i = 0; i < n; ++i) { // fills the array with random values
      for (int j = 0; j < n; ++j) {
         v[i][j] = (rand() % 99);
         cout << setw(4) << v[i][j];
      }
      cout << '\n';
   }

   for (auto& arr : v)
      for (auto& num : arr)
         if (num < min)
            min = num;

   cout << "\nMin is " << min << "\n";
}

void n_Logn_Complexity(int n) {
   // Example: Quick Sort Algorithm
}

void n_Complexity(int n) {
   // Example: Finding max value in an array
   int v[n];
   int max = 0;
   srand((unsigned) time(0));

   for (int i = 0; i < n; ++i) { // fills the array with random values
      v[i] = (rand() % 100);
      cout << v[i] << '\n';
   }

   for (int i : v)
      if (i > max)
         max = i;

   cout << "Max is " << max << '\n';
}

void logn_Complexity(int n) {
   // Example: Binary Search Algorithm
}

void constant_time_Complexity() {
   // Example: Accessing the index of an array
   // More useful O(1) algorithms will be taught in Data Structures
   vector<int> vec = {20, 18, 5, 16, 13, 4, 8, 9, 14, 12};
   cout << vec[3];
}

