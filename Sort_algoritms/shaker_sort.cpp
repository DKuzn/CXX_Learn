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

std::vector<int> ShakerSort(std::vector<int> array)
{
    int n = array.size();
    int left = 0;
    int right = n - 1;
    while (left <= right){
        for (int i = left; i <= right; i++){
            if (array[i] > array[i + 1]){
                std::swap(array[i], array[i + 1]);
            }
        }
        right -= 1;
        for (int j = right; j >= left; j--){
            if (array[j - 1] > array[j]){
                std::swap(array[j - 1], array[j]);
            }
        }
        left += 1;
    }
    return array;
}

int main()
{
    std::vector<int> array = ArrayInit(50);
    std::cout << "Unsorted array:" << std::endl;
    OutputArray(array);
    std::vector<int> sort = ShakerSort(array);
    std::cout << "Sorted array: " << std::endl;
    OutputArray(sort);
    return 0;
}

