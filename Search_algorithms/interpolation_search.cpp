#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

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

int InterpolationSearch(std::vector<int> array, int key)
{
    int n = array.size();
    int min = 0;
    int max = n - 1;
    int search = 0;
    while (array[min] < key < array[max]){
        int dist = int(min + (max - min) * (key - array[min]) / (array[max] - array[min]));
        if (array[dist] == key){
            search = dist;
            break;
        }
        else if (array[dist] > key){
            max = dist -1;
        }
        else {
            min = dist + 1;
        }
    }
    if (array[min] == key){
        search = min;
    }
    else if (array[max] == key){
        search = max;
    }
    while (search > 0 and array[search - 1] == key){
        search -= 1;
    }
    if (array[search] == key){
        return search;
    }
    return -1;
}

int main()
{
    int key = 25;
    std::vector<int> array = ArrayInit(50);
    std::sort(array.begin(), array.end());
    std::cout << "Array:" << std::endl;
    OutputArray(array);
    int found = InterpolationSearch(array, key);
    std::cout << "Key: " << key << std::endl;
    std::cout << "Found key index: " << found << std::endl;
    std::cout << "Check: " << array[found] << std::endl;
    return 0;
}

