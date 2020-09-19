#include <iostream>
#include <cmath>
#include <vector>


std::vector<double> SolveEquation(double alpha)
{
    std::vector<double> answers = {};
    double z1 = (sin(M_PI / 2 + 3 * alpha)) / (1 - sin(3 * alpha - M_PI));
    double z2 = (cos(1.25 * M_PI + 1.5 * alpha)) / (sin(1.25 * M_PI + 1.5 * alpha));
    answers.push_back(z1);
    answers.push_back(z2);
    return answers;
}

int main()
{
    double alpha;
    std::cout << "Input alpha: ";
    std::cin >> alpha;
    std::vector<double> answers = SolveEquation(alpha);
    double z1 = answers[0];
    double z2 = answers[1];
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
}

