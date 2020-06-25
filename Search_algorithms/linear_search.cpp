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

int LinearSearch(std::vector<int> array, int key)
{
    int n = array.size();
    for (int i = 0; i < n; i++){
        if (array[i] == key){
            return i;
        }
    }
    return -1;
}

int main()
{
    int key = 6;
    std::vector<int> array = ArrayInit(50);
    std::cout << "Array:" << std::endl;
    OutputArray(array);
    int found = LinearSearch(array, key);
    std::cout << "Key: " << key << std::endl;
    std::cout << "Found key index: " << found << std::endl;
    std::cout << "Check: " << array[found] << std::endl;
    return 0;
}