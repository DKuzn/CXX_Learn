#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <random>
#include <vector>

std::vector<unsigned long> ArrayInit(unsigned long n)
{
    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::vector<unsigned long> array = {};
    for (unsigned long i = 0; i < n; i++) {
        array.push_back(1 + mersenne() % 100);
    }
    return array;
}

void OutputArray(std::vector<unsigned long> array)
{
    unsigned long n = array.size();
    for (unsigned long i = 0; i < n; i++) {
        std::cout << std::setw(3) << array[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<unsigned long> MergeSort(std::vector<unsigned long> array)
{
    unsigned long n = array.size();
    unsigned long step = 1;
    std::vector<unsigned long> temp = {};
    for (unsigned long i = 0; i < n; i++){
        temp.push_back(0);
    }
    while (step < n){
        unsigned long index = 0;
        unsigned long l = 0;
        unsigned long m = l + step;
        unsigned long r = l + step * 2;
        while (l < n){
            if (m >= n){
                m = n;
            }
            if (r >= n){
                r = n;
            }
            unsigned long i1 = l, i2 = m;
            while (i1 < m && i2 < r){
                if (array[i1] < array[i2]){
                    temp[index++] = array[i1++];
                }
                else {
                temp[index++] = array[i2++];
                }
            }
            while (i1 < m){
                temp[index++] = array[i1++];
                }
            while (i2 < r){
                temp[index++] = array[i2++];
                }
            l += step * 2;
            m += step * 2;
            r += step * 2;
        }
        for (unsigned long i = 0; i < n; i++){
            array[i] = temp[i];
        }
        step *= 2;
        }
    return array;
}

int main()
{
    unsigned long n;
    std::cout << "Введите длину массива: " << "\n";
    std::cin >> n;
    std::vector<unsigned long> array = ArrayInit(n);
    std::cout << "Unsorted array:" << "\n";
    OutputArray(array);
    std::vector<unsigned long> sarray = MergeSort(array);
    std::cout << "Sorted array:" << "\n";
    OutputArray(sarray);
    return 0;
}
