#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <random>
#include <vector>

template<typename T>
std::vector<T> slice(std::vector<T> &v, unsigned long m, unsigned long n)
{
    std::vector<T> vec;
    std::copy(v.begin() + m, v.begin() + n, std::back_inserter(vec));
    return vec;
}

std::vector<unsigned long> ArrayInit(int n)
{
    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::vector<unsigned long> array = {};
    for (int i = 0; i < n; i++) {
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

std::vector<unsigned long> Merge(std::vector<unsigned long> array)
{
    unsigned long n = array.size();
    unsigned long m = n / 2;
    std::vector<unsigned long> full = {};
    std::vector<unsigned long> L = {};
    std::vector<unsigned long> R = {};
    for (unsigned long j = 0; j < n; j += 2){
        L.push_back(array[j]);
    }
    for (unsigned long k = 1; k < n; k += 2){
        R.push_back(array[k]);
    }
    unsigned long i = 0;
    while (i < m){
        if (L[i] < R[i]){
            full.push_back(L[i]);
            full.push_back(R[i]);
        }
        else if (L[i] >= R[i]){
            full.push_back(R[i]);
            full.push_back(L[i]);
        }
        i++;
        }
    if (L.size() < R.size()){
        full.push_back(R[m]);
    }
    return full;
}

std::vector<unsigned long> MergeSort(std::vector<unsigned long> array)
{
    std::vector<unsigned long> sarr = Merge(array);
    return sarr;
}

int main()
{
    int n;
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
