#include <iostream>
#include <fstream>
using namespace std;

void swap(double *xp, double *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(double arr[], int n)
{
    int i;
    int j;
    for (i = 0; i < n-1; i++)
      for (j = 0; j < n-i-1; j++)
          if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
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
    bubbleSort(arr, n);
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
