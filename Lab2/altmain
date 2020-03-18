#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;

void SortMatrix(int n, int m)
{
    random_device rd;
    mt19937 mersenne(rd());
    float ** matrix = new float * [n];
        for (int i(0); i < n; i++) {
            matrix[i] = new float[m];
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
                        float buffer = matrix[i][j];
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
    int n, m;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите m: ";
    cin >> m;
    try
    {
        if (!(n > 1 and n <= 100)) {
            throw 1;
        }
        else if (!(m > 1 and m <= 50)) {
            throw 1.2;
        }
    }
    catch (int)
    {
        cout << "Значение n должно лежать в пределах 1 < n <= 100" << "\n";
        exit(1);
    }
    catch (double)
    {
        cout << "Значение m должно лежать в пределах 1 < m <= 50" << "\n";
        exit(1);
    }

    SortMatrix(n, m);
    return 0;
}
