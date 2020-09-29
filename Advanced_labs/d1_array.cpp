#include <iostream>
#include <iomanip>
#include <vector>
#include <random>


class Array1D
{
private:
    std::vector<int> array = {};

    int linearSearch() {
        int key = 0;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] == key) {
                return i;
            }
        }
        return -1;
    }

public:
    explicit Array1D(int n) {
        std::random_device rd;
        std::mt19937 generator(rd());
        array.reserve(n);
        for (int i = 0; i < n; i++) {
            array.push_back(generator() % 200 - 100);
        }
    }

    friend std::ostream& operator<< (std::ostream &out, const Array1D &point) {
        for (int i : point.array) {
            out << std::setw(3) << i << " ";
        }
        return out;
    }

    int sumAbsAfterZero() {
        int zeroItem = linearSearch();
        int sum = 0;
        if (zeroItem == -1) {
            return sum;
        }
        else {
            for (int i = zeroItem; i < array.size(); i++) {
                sum += abs(array[i]);
            }
        }
        return sum;
    }

    void transform() {
        std::vector<int> temp = {};
        for (int i = 0; i < array.size(); i += 2) {
            temp.push_back(array[i]);
        }
        for (int j = 1; j < array.size(); j += 2) {
            temp.push_back(array[j]);
        }
        array = temp;
    }

    int findMinAbs() {
        int min = 1000;
        for (int i : array) {
            if (abs(i) < min) {
                min = abs(i);
            }
        }
        return min;
    }
};

int main()
{
    Array1D array = Array1D(15);
    std::cout << "Source array:\n" << array << std::endl;
    std::cout << "Minimal absolute value: " << array.findMinAbs() << std::endl;
    std::cout << "Sum of absolute values after first zero element: " << array.sumAbsAfterZero() << std::endl;
    array.transform();
    std::cout << "Transformed array:\n" << array << std::endl;
    return 0;
}
