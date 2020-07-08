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

std::vector<int> SelectionSort(std::vector<int> array)
{
    int n = array.size();
    for (int i = 0; i < n - 1; i++){
        int m = i;
        int j = i + 1;
        while (j < n){
            if (array[j] < array[m]){
                m = j;
            }
            j += 1;
        }
        std::swap(array[i], array[m]);
    }
    return array;
}

int main()
{
    std::vector<int> array = ArrayInit(50);
    std::cout << "Unsorted array:" << std::endl;
    OutputArray(array);
    std::vector<int> sort = SelectionSort(array);
    std::cout << "Sorted array: " << std::endl;
    OutputArray(sort);
    return 0;
}
