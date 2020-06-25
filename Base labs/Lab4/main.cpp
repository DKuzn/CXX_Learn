#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <vector>

using namespace std;

vector<vector<int>> InitMatrix(int n, int m)
{
    random_device rd;
    mt19937 generator(rd());
    vector <vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = generator() % 100;
        }
    return matrix;
}

vector<vector<string>> InitMatrix(const string& n, const string& m)
{
    int p = stoi(n);
    int q = stoi(m);
    random_device rd;
    mt19937 generator(rd());
    vector <vector<string>> matrix(p, vector<string>(q));
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
        {
            matrix[i][j] = generator() % 100;
        }
    return matrix;
}

void OutputMatrix(vector<vector<int>> matrix)
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

void programme(int n, int m)
{
    vector <vector<int>> matrix(n, vector<int>(m));
    matrix = InitMatrix(n, m);
    cout << "Unsorted integer matrix: " << endl;
    OutputMatrix(matrix);
    vector <vector<int>> sort(n, vector<int>(m));
    sort = SortMatrix(matrix);
    cout << "Sorted integer matrix: " << endl;
    OutputMatrix(sort);
}

void programme(const string& n, const string& m)
{
    int p = stoi(n);
    int q = stoi(m);
    vector <vector<string>> matrix(p, vector<string>(q));
    matrix = InitMatrix(n, m);
    cout << "Unsorted string matrix: " << endl;
    OutputMatrix(matrix);
    vector <vector<string>> sort(p, vector<string>(q));
    sort = SortMatrix(matrix);
    cout << "Sorted string matrix: " << endl;
    OutputMatrix(sort);
}

int main()
{
    programme(6, 7);
    programme("6", "7");
    return 0;
}
