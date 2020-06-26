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

std::vector<int> GnomeSort(std::vector<int> array)
{
    int i = 1;
    int size = array.size();
    while (i < size){
        if (array[i - 1] <= array[i]){
            i++;
        }
        else {
            std::swap(array[i - 1], array[i]);
            if (i > 1){
                i--;
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
    std::vector<int> sort = GnomeSort(array);
    std::cout << "Sorted array: " << std::endl;
    OutputArray(sort);
    return 0;
}
