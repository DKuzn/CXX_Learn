#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

std::vector<int> ArrayInit(int n)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::vector<int> array = {};
    array.reserve(n);
    for (int i = 0; i < n; i++) {
        array.push_back(generator() % 100);
    }
    return array;
}

void OutputArray(std::vector<int> array)
{
    int n = array.size();
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(3) << array[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> MergeSort(std::vector<int> array)
{
    if (array.size() > 1){
        int mid = int(array.size() / 2);
        std::vector<int> L(array.begin(), array.begin() + mid);
        std::vector<int> R(array.begin() + mid, array.end());
        std::vector<int> sort_L = MergeSort(L);
        std::vector<int> sort_R = MergeSort(R);
        int i = 0, j = 0, k = 0;
        while (i < L.size() and j < R.size()){
            if (sort_L[i] < sort_R[j]){
                array[k] = sort_L[i];
                i += 1;
            }
            else {
                array[k] = sort_R[j];
                j += 1;
            }
            k += 1;
        }
        while (i < L.size()){
            array[k] = sort_L[i];
            i += 1;
            k += 1;
        }
        while (j < R.size()){
            array[k] = sort_R[j];
            j += 1;
            k += 1;
        }
    }
    return array;
}

int main()
{
    std::vector<int> array = ArrayInit(50);
    std::cout << "Unsorted array:" << std::endl;
    OutputArray(array);
    std::vector<int> sort = MergeSort(array);
    std::cout << "Sorted array: " << std::endl;
    OutputArray(sort);
    return 0;
}
