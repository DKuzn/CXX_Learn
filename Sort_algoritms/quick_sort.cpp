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

int Partition(std::vector<int> &array, int low, int high)
{
    int i = low - 1;
    int pivot = array[high];
    for (int j = low; j < high; j++){
        if (array[j] < pivot){
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return i + 1;
}

void QuickSortLegacy(std::vector<int> &array, int low, int high)
{
    if (low < high) {
        int part_index = Partition(array, low, high);
        QuickSortLegacy(array, low, part_index - 1);
        QuickSortLegacy(array, part_index + 1, high);
    }
}

std::vector<int> QuickSort(std::vector<int> array)
{
    int n = array.size();
    QuickSortLegacy(array, 0, n - 1);
    return array;
}

int main()
{
    std::vector<int> array = ArrayInit(50);
    std::cout << "Unsorted array:" << std::endl;
    OutputArray(array);
    std::vector<int> sort = QuickSort(array);
    std::cout << "Sorted array: " << std::endl;
    OutputArray(sort);
    return 0;
}

