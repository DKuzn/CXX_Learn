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

std::vector<int> BubbleSort(std::vector<int> array)
{
    int n = array.size();
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (array[j] > array[j + 1]){
                std::swap(array[j], array[j + 1]);
            }
        }
    }
    return array;
}

int main()
{
    std::vector<int> array = ArrayInit(50);
    std::cout << "Unsorted array:" << std::endl;
    OutputArray(array);
    std::vector<int> sort = BubbleSort(array);
    std::cout << "Sorted array: " << std::endl;
    OutputArray(sort);
    return 0;
}

