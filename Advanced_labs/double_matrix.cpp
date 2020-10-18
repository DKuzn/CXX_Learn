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
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = generator() % 100;
            }
        }
        doubleMatrix = matrix;
    }

    explicit DoubleMatrix(std::vector<std::vector<double>> temp) {
        doubleMatrix = std::move(temp);
    }

    friend std::ostream& operator<< (std::ostream &out, const DoubleMatrix &dm) {
        for (const std::vector<double>& i : dm.doubleMatrix) {
            for (double j : i) {
                out << std::setw(5) << j << " ";
            }
            out << std::endl;
        }
        return out;
    }

    template<typename T>
    friend DoubleMatrix operator* (DoubleMatrix &dm, T value) {
        for (int i = 0; i < dm.doubleMatrix.size(); i++) {
            for (int j = 0; j < dm.doubleMatrix[0].size(); j++) {
                dm.doubleMatrix[i][j] *= value;
            }
        }
        return DoubleMatrix(dm.doubleMatrix);
    }

    template<typename T>
    friend void operator*= (DoubleMatrix &dm1, T value) {
        for (int i = 0; i < dm1.doubleMatrix.size(); i++) {
            for (int j = 0; j < dm1.doubleMatrix[0].size(); j++) {
                dm1.doubleMatrix[i][j] *= value;
            }
        }
    }

    friend DoubleMatrix operator* (DoubleMatrix &dm1, DoubleMatrix &dm2) {
        int i_value = dm1.doubleMatrix.size();
        int j_value = dm2.doubleMatrix[0].size();
        int k_value = dm1.doubleMatrix[0].size();
        double temp = 0;
        std::vector<std::vector<double>> result(i_value, std::vector<double>(j_value));
            for (int i = 0; i < i_value; i++) {
                for (int j = 0; j < j_value; j++) {
                    for (int k = 0; k < k_value; k++) {
                        temp += dm1.doubleMatrix[i][k] * dm2.doubleMatrix[k][j];
                    }
                    result[i][j] = temp;
                    temp = 0;
                }
            }
        return DoubleMatrix(result);
    }

    friend void operator*= (DoubleMatrix &dm1, DoubleMatrix &dm2) {
        int i_value = dm1.doubleMatrix.size();
        int j_value = dm2.doubleMatrix[0].size();
        int k_value = dm1.doubleMatrix[0].size();
        double temp = 0;
        std::vector<std::vector<double>> result(i_value, std::vector<double>(j_value));
        for (int i = 0; i < i_value; i++) {
            for (int j = 0; j < j_value; j++) {
                for (int k = 0; k < k_value; k++) {
                    temp += dm1.doubleMatrix[i][k] * dm2.doubleMatrix[k][j];
                }
                result[i][j] = temp;
                temp = 0;
            }
        }
        dm1.doubleMatrix = result;
    }
};


int main()
{
    DoubleMatrix matrix1 = DoubleMatrix(5, 6);
    DoubleMatrix matrix2 = DoubleMatrix(6, 4);
    std::cout << "Matrix1\n" << matrix1;
    std::cout << "Matrix2\n" << matrix2;
    std::cout << "Matrix1 * Matrix2\n" << matrix1 * matrix2;
    matrix1 *= matrix2;
    std::cout << "Matrix1\n" << matrix1;
    matrix2 *= 2;
    std::cout << "Matrix2\n" << matrix2;

}