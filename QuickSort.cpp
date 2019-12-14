#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;


void swap(double arr[], int i, int j)
{
  double temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
  }


int partition (double arr[], int startIndex, int endIndex)
{
   double pivot = arr[endIndex];
   int i = (startIndex);
   int j = endIndex-1;
   do {
     while(arr[i] < pivot) {i++;}
     while(j > startIndex && arr[j] > pivot) {j--;}
     if(i < j) {swap(arr, i, j);  ++i; --j; }

   } while (i < j);

  swap(arr, i, endIndex);

  return i;

}

void quickSort(double arr[], int startIndex, int endIndex)
{
   if (startIndex < endIndex)
   {
       int pi = partition(arr, startIndex, endIndex);
       quickSort(arr, startIndex, pi - 1);
       quickSort(arr, pi + 1, endIndex);
   }
}

int main(int argc, char * argv[])
{
   if(argc == 1) {
     cout << "Usage requires file as command line argument 1" << endl;
     return 0;
   }

   string file = argv[1];
   ifstream fin(file);

   if(!fin) {
     cout << "Unable to open file\n";
     return 0;
   }
   int n;
   fin >> n;
   double * arr  = new double[n]; /// set to those values^
   int i = 0;
   while(fin >> arr[i++]) {}

   clock_t start = clock();
   quickSort(arr, 0, n - 1);
   clock_t end = clock();
   clock_t diff = end - start;
   cout << "Sorted array size " << n <<" \n";

   for (i = 0; i < n; i++)
       cout << arr[i] << " ";
   cout << endl;
   cout << "It took " << (float)diff/CLOCKS_PER_SEC << " seconds." << endl;

   delete [] arr;
   return 0;
}
