#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <cstdlib>

/*function for generate random numbers*/
int random_number()
{
    return 23 + std::rand() % (98 - 23);
}

/*create a new type for return type of the function*/
using my_string_t = std::vector<std::vector<int>>;
my_string_t generate(std::size_t n, std::size_t m) {
  my_string_t matrix_func(n, std::vector<int>(m));

  for (auto& sub_vec : matrix_func)
    for (int& element : sub_vec)
      element = random_number();
  return matrix_func;
}

void output(std::vector<std::vector <int>> const &matrix_func)
{
    for (auto& sub_vec : matrix_func)
    {
        for (const int& element : sub_vec)
            std::cout << element << " ";
        std::cout << std::endl;
    }

}

void buble_sort(std::vector<int> &matrix_string)
{
    /*length_string lenght of the matrix string*/
    int length_string = matrix_string.size();
    for (auto i = 0; i < length_string; i++)
    {
        for(auto j = 0; j < length_string - i; j++)
        {
            if (matrix_string[j] < matrix_string[j + 1])
                std::swap(matrix_string[j], matrix_string[j+1]);
        }
    }
}

void sorting_element(std:: vector<std::vector <int>> &matrix_func)
{
    for (auto& sub_vec : matrix_func)
    {
        /*sub_vec is string of our matrix
         we init cycle for her and sort element in string*/
        buble_sort(sub_vec);

    }
}


int main()
{
    /*init the seed as current time*/
    std::srand(std::time(0));
    /*n and m without signed*/
    unsigned int n, m;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cout << "Введите m: ";
    std::cin >> m;
    /*validation values*/
    if (n < 1 or n > 100)
    {
        std::cout << "Число n должно быть в пределах 1<n<100" << std::endl;
        /*exit from program*/
        return 1;
    }
    else if (m < 1 or m > 50)
    {
        std::cout << "Число n должно быть в пределах 1<m<50" << std::endl;
        /*exit from program*/
        return 1;
    }
    /*construct the matrix of vector type*/
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    matrix = generate(n, m);
    output(matrix);
    sorting_element(matrix);
    std::cout << std::endl;
    output(matrix);
    return 0;
}
