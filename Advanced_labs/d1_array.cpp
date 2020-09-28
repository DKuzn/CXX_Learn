#include <iostream>
#include <iomanip>
#include <vector>
#include <random>


class D1Array
{
public:
    std::vector<int> array = {};

public: explicit D1Array(int n){
        std::random_device rd;
        std::mt19937 generator(rd());
        array.reserve(n);
        for (int i = 0; i < n; i++) {
            array.push_back(generator() % 200 - 100);
        }
    }

public: void output(){
        for (int i : array) {
            std::cout << std::setw(3) << i << " ";
        }
        std::cout << std::endl;
    }

    int findMinAbs(){
        int min = 1000;
        for (int i : array){
            if (abs(i) < min){
                min = i;
            }
        }
        return min;
    }
};

int main()
{
    D1Array array = D1Array(10);
    array.output();
    auto min = array.findMinAbs();
    std::cout << min << std::endl;
    return 0;
}
