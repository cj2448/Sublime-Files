#include <iostream>
#include <algorithm>

using namespace std;

// Global variables
int qsTime = 0;
int qsSpace = 0;
int ssTime = 0;
int ssSpace = 0;
const int SIZE = 10;

// Function prototypes
void selectionSort(int array[], int size);
void showArray(const int array[], int size);
void quickSort(int [], int, int);
int partition(int [], int, int);

int main()
{
   int qArr[SIZE] = {17, 53, 9, 2, 30, 1, 82, 64, 26, 5};
   int sArr[SIZE] = {17, 53, 9, 2, 30, 1, 82, 64, 26, 5};

   showArray(qArr, SIZE);
   showArray(sArr, SIZE);

   quickSort(qArr, 0, SIZE-1);
   selectionSort(sArr, SIZE);

   showArray(qArr, SIZE);
   showArray(sArr, SIZE);

   // cout << "\nThis is the time complexity of quickSort: " << qsTime << " operations.\n";
   // cout << "This is the time complexity of selectionSort: " << ssTime << " operations.\n";

   // cout << "This is the space complexity of quickSort: " << qsSpace << " bytes.\n";
   // cout << "This is the space complexity of selectionSort: " << ssSpace << " bytes.\n";

   return 0;
}

void quickSort(int arr[], int start, int end)
{
   qsSpace += 4*10 + 4 +4;

   qsTime++;
   if (start < end)
   {
     qsSpace += 4;
     qsTime++;
     int p = partition(arr, start, end);

     quickSort(arr, start, p - 1);
     quickSort(arr, p + 1, end);
   }
}


int partition(int arr[], int start, int end)
{
   qsSpace += 4*10 + 4 +4;
   qsSpace += 8;

   qsTime++;
   int pivotValue = arr[start];

   qsTime++;
   int pivotPosition = start;

   qsSpace += 4;
   qsTime++;
   for (int pos = start + 1; pos <= end; pos++)
   {
      qsTime++;
      qsTime++;
      if (arr[pos] < pivotValue)
      {  
         swap(arr[pivotPosition + 1], arr[pos]);
         swap(arr[pivotPosition], arr[pivotPosition + 1]);

         qsTime++;
         pivotPosition ++;
     }

     qsTime++;
  }
  qsTime++;

  return pivotPosition;
}

void selectionSort(int array[], int size)
{
   ssSpace += 4*SIZE + 4;
   int startScan, minIndex, minValue;
   ssSpace += 12;
   ssSpace += 4 ;

   ++ssTime;
   for (startScan = 0; startScan < (size - 1); startScan++) {
      ++ssTime;
      ++ssTime;
      minIndex = startScan;
      ++ssTime;
      minValue = array[startScan];
      ++ssTime;
      for(int index = startScan + 1; index < size; index++) {
         ++ssTime;
         ++ssTime;
         if (array[index] < minValue)
         {
            ++ssTime;
            minValue = array[index];
            ++ssTime;
            minIndex = index;
         }
         ++ssTime;
      }
      ++ssTime;
      ++ssTime;
      array[minIndex] = array[startScan];
      ++ssTime;
      array[startScan] = minValue;
   }
   ++ssTime;
}

void showArray(const int array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
}