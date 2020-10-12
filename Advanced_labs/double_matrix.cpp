#include <iostream>
#include <iomanip>
#include <vector>
#include <random>


class DoubleMatrix
{
private:
    std::vector<std::vector<double>> doubleMatrix;

public:
    DoubleMatrix(int rows, int columns) {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::vector <std::vector<double>> matrix(rows, std::vector<double>(columns));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = generator() % 100;
            }
        doubleMatrix = matrix;
    }
};


int main()
{
    DoubleMatrix matrix = DoubleMatrix(5, 6);
}