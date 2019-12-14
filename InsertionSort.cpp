#include <iostream>
#include <fstream>
using namespace std;

void insertionSort(double arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
  insertionSort(arr, n);
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
