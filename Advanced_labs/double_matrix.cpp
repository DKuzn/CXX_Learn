#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <random>


class MatrixException : public std::exception {
private:
    std::string message_error;

public:
    explicit MatrixException(std::string error) : message_error(std::move(error)) {}

    const char *what() const noexcept override {
        return message_error.c_str();
    }
};


class DoubleMatrix {
private:
    std::vector<std::vector<double>> doubleMatrix;

public:
    int rows;
    int columns;

public:
    DoubleMatrix(int rows_i, int columns_i) {
        rows = rows_i;
        columns = columns_i;
        std::random_device rd;
        std::mt19937 generator(rd());
        std::vector<std::vector<double>> matrix(rows_i, std::vector<double>(columns_i));
        for (int i = 0; i < rows_i; i++) {
            for (int j = 0; j < columns_i; j++) {
                matrix[i][j] = generator() % 10;
            }
        }
        doubleMatrix = matrix;
    }

    explicit DoubleMatrix(std::vector<std::vector<double>> temp) {
        doubleMatrix = std::move(temp);
        rows = doubleMatrix.size();
        columns = doubleMatrix[0].size();
    }

    friend std::ostream &operator<<(std::ostream &out, const DoubleMatrix &dm) {
        for (const std::vector<double> &i : dm.doubleMatrix) {
            for (double j : i) {
                out << std::setw(12) << j << " ";
            }
            out << std::endl;
        }
        return out;
    }

    double determinant() {
        const double EPS = 1E-9;
        double det = 1;
        auto tempMatrix = doubleMatrix;
        if (rows != columns) {
            throw MatrixException("The determinant cannot be calculated. Rows and columns of th matrix are not equal.");
        }
        for (int i = 0; i < rows; i++) {
            int index = i;
            for (int j = i + 1; j < rows; j++) {
                if (std::abs(tempMatrix[j][i]) > std::abs(tempMatrix[index][i]))
                    index = j;
            }
            if (std::abs(tempMatrix[index][i]) < EPS) {
                det = 0;
                break;
            }
            swap(tempMatrix[i], tempMatrix[index]);
            if (i != index) {
                det = -det;
            }
            det *= tempMatrix[i][i];
            for (int j = i + 1; j < rows; j++) {
                tempMatrix[i][j] /= tempMatrix[i][i];
            }
            for (int j = 0; j < rows; j++) {
                if (j != i && std::abs(tempMatrix[j][i]) > EPS) {
                    for (int k = i + 1; k < rows; k++) {
                        tempMatrix[j][k] -= tempMatrix[i][k] * tempMatrix[j][i];
                    }
                }
            }
        }
        return det;
    }

    double normM() {
        double norm = 0;
        double temp = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                temp += std::abs(doubleMatrix[i][j]);
            }
            if (temp >= norm) {
                norm = temp;
            }
            temp = 0;
        }
        return norm;
    }

    double normL() {
        double norm = 0;
        double temp = 0;
        for (int j = 0; j < columns; j++) {
            for (int i = 0; i < rows; i++) {
                temp += std::abs(doubleMatrix[i][j]);
            }
            if (temp >= norm) {
                norm = temp;
            }
            temp = 0;
        }
        return norm;
    }

    double algebraicComplement(int i, int j) {
        DoubleMatrix minor = this->minor(i, j);
        double alComp = pow(-1, i + j) * minor.determinant();
        return alComp;
    }

    DoubleMatrix algebraicComplementsMatrix() {
        auto tempMatrix = doubleMatrix;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                tempMatrix[i][j] = this->algebraicComplement(i, j);
            }
        }
        return DoubleMatrix(tempMatrix);
    }

    DoubleMatrix transpose() {
        std::vector<std::vector<double>> matrix(columns, std::vector<double>(rows));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[j][i] = doubleMatrix[i][j];
            }
        }
        return DoubleMatrix(matrix);
    }

    DoubleMatrix minor(int i, int j) {
        if (i > rows || j > columns) {
            throw MatrixException("One or two indexes is out of matrix boundaries.");
        }
        auto temp = doubleMatrix;
        temp.erase(temp.begin() + i);
        for (std::vector<double> &k : temp) {
            k.erase(k.begin() + j);
        }
        return DoubleMatrix(temp);
    }

    DoubleMatrix inverseMatrix() {
        double det = this->determinant();
        if (det == 0) {
            throw MatrixException("Inverse matrix cannot be calculated. Determinant = 0.");
        }
        DoubleMatrix alMatrix = this->algebraicComplementsMatrix().transpose();
        DoubleMatrix matrix = alMatrix * (1 / det);
        return matrix;
    }

    DoubleMatrix exponentiation(int exp) {
        auto tempMatrix = DoubleMatrix(doubleMatrix);
        for (int i = 0; i < exp; i++) {
            tempMatrix *= tempMatrix;
        }
        return tempMatrix;
    }

    template<typename T>
    friend DoubleMatrix operator*(DoubleMatrix &dm, T value) {
        auto temp = dm.doubleMatrix;
        for (int i = 0; i < dm.rows; i++) {
            for (int j = 0; j < dm.columns; j++) {
                temp[i][j] *= value;
            }
        }
        return DoubleMatrix(temp);
    }

    template<typename T>
    friend void operator*=(DoubleMatrix &dm, T value) {
        for (int i = 0; i < dm.doubleMatrix.size(); i++) {
            for (int j = 0; j < dm.doubleMatrix[0].size(); j++) {
                dm.doubleMatrix[i][j] *= value;
            }
        }
    }

    friend DoubleMatrix operator*(DoubleMatrix &dm1, DoubleMatrix &dm2) {
        if (dm1.columns != dm2.rows) {
            throw MatrixException("Invalid operation. Boundary sizes of matrices are not equal.");
        }
        int i_value = dm1.rows;
        int j_value = dm2.columns;
        int k_value = dm1.columns;
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

    friend void operator*=(DoubleMatrix &dm1, DoubleMatrix &dm2) {
        if (dm1.columns != dm2.rows) {
            throw MatrixException("Invalid operation. Boundary sizes of matrices are not equal.");
        }
        int i_value = dm1.rows;
        int j_value = dm2.columns;
        int k_value = dm1.columns;
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

    template<typename T>
    friend DoubleMatrix operator/(DoubleMatrix &dm, T value) {
        return dm * (1.0 / value);
    }

    template<typename T>
    friend void operator/=(DoubleMatrix &dm, T value) {
        dm *= (1.0 / value);
    }

    friend DoubleMatrix operator/(DoubleMatrix &dm1, DoubleMatrix &dm2) {
        auto dm2inverse = dm2.inverseMatrix();
        return dm1 * dm2inverse;
    }

    friend void operator/=(DoubleMatrix &dm1, DoubleMatrix &dm2) {
        auto dm2inverse = dm2.inverseMatrix();
        dm1 *= dm2inverse;
    }

    std::vector<double> operator[](int index) {
        return doubleMatrix[index];
    }
};


int main() {
    try {
        DoubleMatrix matrix1 = DoubleMatrix(6, 5);
        DoubleMatrix matrix2 = DoubleMatrix(5, 4);
        DoubleMatrix matrix3 = DoubleMatrix(5, 5);
        std::cout << "Matrix1\n" << matrix1;
        std::cout << "Matrix2\n" << matrix2;
        std::cout << "Matrix1 * Matrix2\n" << matrix1 * matrix2;
        matrix1 *= matrix2;
        std::cout << "Matrix1\n" << matrix1;
        matrix2 *= 2;
        std::cout << "Matrix2\n" << matrix2;
        std::cout << matrix1[1][1] << std::endl;
        std::cout << matrix2.normM() << std::endl;
        std::cout << matrix2.normL() << std::endl;
        std::cout << matrix3 << std::endl;
        std::cout << matrix3.transpose() << std::endl;
        std::cout << matrix3.minor(0, 1) << std::endl;
        std::cout << matrix3.minor(0, 1).determinant() << std::endl;
        std::cout << matrix3.algebraicComplement(0, 1) << std::endl;
        std::cout << matrix3.inverseMatrix() << std::endl;
        std::cout << matrix3 << std::endl;
        auto inv3 = matrix3.inverseMatrix();
        std::cout << matrix3 * inv3 << std::endl;
        std::cout << matrix3 / 2 << std::endl;
        DoubleMatrix matrix4 = DoubleMatrix(5, 5);
        matrix3 /= matrix4;
        std::cout << matrix3 << std::endl;
        std::cout << matrix3.exponentiation(5) << std::endl;
    }
    catch (MatrixException &exception) {
        std::cout << exception.what() << std::endl;
    }

}