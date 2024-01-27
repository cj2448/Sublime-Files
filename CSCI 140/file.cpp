#include <iostream>
#include <fstream>

using namespace std;

int main() {
   string line;
   string fileName;

   ifstream inFile;
   ofstream outFile;

   cout << "Please enter the file name: ";
   cin >> fileName;

   inFile.open("C:\\Users\\kamit\\Desktop\\" + fileName + ".txt");
   if (!inFile)
   {
      cout << "File not found" << endl;
      exit(1);
   }

   outFile.open("C:\\Users\\kamit\\Desktop\\output.txt");
   while (inFile >> line)
   {
      cout << line << endl;
      outFile << line << endl;
   }

   inFile.close();
   outFile.close();

   exit(0);
}