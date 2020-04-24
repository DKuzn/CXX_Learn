#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;

int *ArrayInit(int n)
{
    random_device rd;
    mt19937 mersenne(rd());
    int * array = new int [n];
    for (int i = 0; i < n; i++) {
        array[i] = 1 + mersenne() % 100;
    }
    return array;
}

void OutputArray(int *array, int n)
{
    for (int i = 0; i < n; i++) {
        cout << setw(3) << array[i] << " ";
    }
    cout << endl;
}

int *Merge(int *array, int n)
{
    int *full = new int[n];
    int m = n / 2;
    int *L = new int[m];
    int *R = new int[m];
    for (int i = 0; i < m; i++){
        L[i] = array[i];
    }
    for (int j = m; j < n; j++){
        R[j] = array[j];
    }
    int i = 0;
    int j = m;
    int k = 0;
    while (i < m && j < n){
        if (L[i] < R[j]){
            full[k] = L[i];
            full[k + 1] = R[j];
            i++;
            j++;
            k = k + 2;
        }
        else {
            full[k] = R[j];
            full[k + 1] = L[i];
            i++;
            j++;
            k = k + 2;
        }
        }
    return full;
}

int *MergeSort(int *array, int n)
{
    int *sarr = Merge(array, n);
    return sarr;
}

int main()
{
    int n = 12;
    int *array;
    array = ArrayInit(n);
    cout << "Unsorted array:" << "\n";
    OutputArray(array, n);
    int *sarray = MergeSort(array, n);
    cout << "Sorted array:" << "\n";
    OutputArray(sarray, n);
    return 0;

}
