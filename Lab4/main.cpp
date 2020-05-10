#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <vector>

using namespace std;

vector<vector<int>> InitMatrix(int n, int m)
{
    random_device rd;
    mt19937 mersenne(rd());
    vector <vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 1 + mersenne() % 100;
        }
    return matrix;
}

vector<vector<string>> InitMatrix(string n, string m)
{
    int p = stoi(n);
    int q = stoi(m);
    random_device rd;
    mt19937 mersenne(rd());
    vector <vector<string>> matrix(p, vector<string>(q));
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
        {
            matrix[i][j] = 1 + mersenne() % 100;
        }
    return matrix;
}

void OutputMatrix(vector<vector<int>> matrix)
{
    unsigned long n = matrix.size();
    unsigned long m = matrix[0].size();
    for (unsigned long i = 0; i < n; i++) {
        for (unsigned long j = 0; j < m; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void OutputMatrix(vector<vector<string>> matrix)
{
    unsigned long n = matrix.size();
    unsigned long m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> SortMatrix(vector<vector<int>> matrix)
{
    unsigned long n = matrix.size();
    unsigned long m = matrix[0].size() - 1;
    for(int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            for (int j = 0; j < m - k; j++) {
                if (matrix[i][j] < matrix[i][j + 1]) {
                    swap(matrix[i][j], matrix[i][j + 1]);
                }
            }
        }
    }
    return matrix;
}

vector<vector<string>> SortMatrix(vector<vector<string>> matrix)
{
    unsigned long n = matrix.size();
    unsigned long m = matrix[0].size() - 1;
    for(unsigned long i = 0; i < n; i++) {
        for (unsigned long k = 0; k < m; k++) {
            for (unsigned long j = 0; j < m - k; j++) {
                if (matrix[i][j] < matrix[i][j + 1]) {
                    swap(matrix[i][j], matrix[i][j + 1]);
                }
            }
        }
    }
    return matrix;
}

void prog(int n, int m)
{
    vector <vector<int>> smat(n, vector<int>(m));
    smat = InitMatrix(n, m);
    cout << "Исходная целочисленная матрица: " << endl;
    OutputMatrix(smat);
    vector <vector<int>> ssmat(n, vector<int>(m));
    ssmat = SortMatrix(smat);
    cout << "Отсортированная целочисленная матрица: " << endl;
    OutputMatrix(ssmat);
}

void prog(string n, string m)
{
    int p = stoi(n);
    int q = stoi(m);
    vector <vector<string>> smat(p, vector<string>(q));
    smat = InitMatrix(n, m);
    cout << "Исходная матрица строк: " << endl;
    OutputMatrix(smat);
    vector <vector<string>> ssmat(p, vector<string>(q));
    ssmat = SortMatrix(smat);
    cout << "Отсортированная матрица строк: " << endl;
    OutputMatrix(ssmat);
}

int main()
{
    prog(6, 7);
    prog("6", "7");
    return 0;
}
