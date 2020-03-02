#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int treagle(int n)
{
   int m = (n + 1) / 2;
   char space = ' ';
   for (int i = 1; i <= m; i++) {
       cout.fill(' ');
       cout << setw(m - i + 1) << space;
       cout.fill('*');
       cout << setw(i + 1) << '\n';
   }
   for (int i = m - 1; i >= 1; i--) {
       cout.fill(' ');
       cout << setw(m - i + 1) << space;
       cout.fill('*');
       cout << setw(i + 1) << '\n';
   }
   return 1;
}

int main()
{
    int n;
    cout << "Введите n: ";
    cin >> n;
    try
    {
        if (n == 0 or n % 2 == 0) {
            throw 1;
        }
    }
    catch (int)
    {
        cout << "Число n должно быть нечетным и больше нуля." << "\n";
        exit(1);
    }
    treagle(n);
    return 0;
}
