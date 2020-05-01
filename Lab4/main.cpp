#include <iostream>
#include <iomanip>
#include <string>
#include <random>

using namespace std;

void SortMatrix(int n, int m)
{
    random_device rd;
    mt19937 mersenne(rd());
    int ** matrix = new int * [n];
    for (int i(0); i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 1 + mersenne() % 100;
        }
    }
    cout << "Исходная матрица: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            for (int j = 0; j < m - k; j++) {
                if (matrix[i][j] < matrix[i][j + 1]) {
                    int buffer = matrix[i][j];
                    matrix[i][j] = matrix[i][j + 1];
                    matrix[i][j + 1] = buffer;
                }
            }
        }
    }
    cout << "Сортированная матрица: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i(0); i < n; i++)
        delete matrix[i];
    delete[] matrix;
}

void SortMatrix(char n1, char m1)
{
    random_device rd;
    mt19937 mersenne(rd());
    int n = int(n1);
    int m = int(m1);
    char ** matrix = new char * [n];
    for (int i(0); i < n; i++) {
        matrix[i] = new char [m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 1 + mersenne() % 100;
        }
    }
    cout << "Исходная матрица: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            for (int j = 0; j < m - k; j++) {
                if (matrix[i][j] < matrix[i][j + 1]) {
                    char buffer = matrix[i][j];
                    matrix[i][j] = matrix[i][j + 1];
                    matrix[i][j + 1] = buffer;
                }
            }
        }
    }
    cout << "Сортированная матрица: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i(0); i < n; i++)
        delete matrix[i];
    delete[] matrix;
}

int main()
{
    char n = 6;
    char m = 7;
    int j = 6;
    int k = 7;
    SortMatrix(n, m);
    SortMatrix(j, k);
}
