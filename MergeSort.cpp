#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void merge(double arr[], int start1, int end1, int start2, int end2, double b[]){
  int n = end2 - start1 + 1;

  int i = start1;
  int j = start2;
  int k = 0;

  while(k < n) {
    if (i > end1) // Used up all of the first half
      b[k++] = arr[j++];
    else if (j > end2)
      b[k++] = arr[i++]; // Used up all of the second half
    else if (arr[i] < arr[j])
      b[k++] = arr[i++];
    else
      b[k++] = arr[j++];
  }

  for(i = start1, j = 0; j < n; i++, j++) {
    arr[i] = b[j];
  }

}

void mergeSort(double arr[], int low, int high, double b[]) {
  if(low >= high)
    return;

  int mid = (low + high)/2;
  mergeSort(arr, low, mid, b);
  mergeSort(arr, mid+1, high, b);
  merge(arr, low, mid, mid+1, high, b);
}

void mergeSort(double arr[], int len) {
  double * b = new double[len];
  mergeSort(arr, 0, len-1, b);
  delete [] b;
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
   mergeSort(arr, n);
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
