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

int FibonaccianSearch(std::vector<int> array, int key)
{
    int n = array.size();
    int fib_nm2 = 0;
    int fib_nm1 = 1;
    int fib_n = fib_nm2 + fib_nm1;
    while (fib_n < n) {
        fib_nm2 = fib_nm1;
        fib_nm1 = fib_n;
        fib_n = fib_nm2 + fib_nm1;
    }
    int offset = -1;
    while (fib_n > 1){
        int i = std::min(offset + fib_nm2, n - 1);
        if (array[i] < key){
            fib_n = fib_nm1;
            fib_nm1 = fib_nm2;
            fib_nm2 = fib_n - fib_nm1;
            offset = i;
        }
        else if (array[i] > key){
            fib_n = fib_nm2;
            fib_nm1 = fib_nm1 - fib_nm2;
            fib_nm2 = fib_n - fib_nm1;
        }
        else {
            return i;
        }
    }
    if (fib_nm1 and array[offset] == key){
        return offset;
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
    int found = FibonaccianSearch(array, key);
    std::cout << "Key: " << key << std::endl;
    std::cout << "Found key index: " << found << std::endl;
    std::cout << "Check: " << array[found] << std::endl;
    return 0;
}
