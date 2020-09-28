#include <iostream>
#include <cmath>

class Polynomial
{
private:
    double args[3]{};
    double roots[2]{};

public: Polynomial(double a, double b, double c){
    args[0] = a;
    args[1] = b;
    args[2] = c;
}

private: double * get_args(){
        return args;
    }

public: double * get_roots(){
        calculate();
        return roots;
    }

public: double value(double x){
        // Calculating polynomial value
        double a = args[0];
        double b = args[1];
        double c = args[2];
        double value = a * pow(x, 2) + b * x + c;
        return value;
    }

private: void calculate(){
        // Calculating argument when polynomial value equal to zero (quadratic equation)
        double a = args[0];
        double b = args[1];
        double c = args[2];
        double d = pow(b, 2) - 4 * a * c;
        roots[0] = (-b + sqrt(d)) / (2 * a);
        roots[1] = (-b - sqrt(d)) / (2 * a);
    }

public: void calculation(){
        // Output roots of quadratic equation
        calculate();
        std::cout << "x1 = " << roots[0] << ", " << "x2 = " << roots[1] <<std::endl;
    }

public: Polynomial addition(Polynomial polynom){
        // Addition operation for two Polynomial instance
        double * to_addition = polynom.get_args();
        to_addition[0] += args[0];
        to_addition[1] += args[1];
        to_addition[2] += args[2];
        return {to_addition[0], to_addition[1], to_addition[2]};
    }

public: Polynomial subtraction(Polynomial polynom){
        // Subtraction operation for two Polynomial instance
        double * to_subtraction = polynom.get_args();
        to_subtraction[0] = args[0] - to_subtraction[0];
        to_subtraction[1] = args[1] - to_subtraction[1];
        to_subtraction[2] = args[2] - to_subtraction[2];
        return {to_subtraction[0], to_subtraction[1], to_subtraction[2]};
    }

public: Polynomial multiplication(Polynomial polynom){
        // Multiplication operation for two Polynomial instance
        double * to_multiplication = polynom.get_args();
        to_multiplication[0] *= args[0];
        to_multiplication[1] *= args[1];
        to_multiplication[2] *= args[2];
        return {to_multiplication[0], to_multiplication[1], to_multiplication[2]};
    }

public: void output(){
        // Output polynomial description
        double a = args[0];
        double b = args[1];
        double c = args[2];

        std::string out;
        out += std::to_string(a) + "x^2";

        if (b < 0){
            out += " - " + std::to_string(-b) + "x";
        }
        else {
            out += " + " + std::to_string(b) + "x";
        }

        if (c < 0){
            out += " - " + std::to_string(-c);
        }
        else {
            out += " + " + std::to_string(c);
        }

        std::cout << out << std::endl;
    }

};

int main()
{
    Polynomial polynom1 = Polynomial(1, -70, 600);
    Polynomial polynom2 = Polynomial(1, -70, 500);
    Polynomial addit = polynom1.addition(polynom2);
    Polynomial multi = polynom1.multiplication(polynom2);
    Polynomial subtr = polynom1.subtraction(polynom2);
    std::cout << "First polynomial:" << std::endl;
    polynom1.output();
    std::cout << "Second polynomial:" << std::endl;
    polynom2.output();
    std::cout << "Addition first with second:" << std::endl;
    addit.output();
    std::cout << "Multiplication first with second:" << std::endl;
    multi.output();
    std::cout << "Subtraction second from first:" << std::endl;
    subtr.output();
    std::cout << "Roots of first polynomial:" << std::endl;
    polynom1.calculation();
    std::cout << "Roots of second polynomial:" << std::endl;
    polynom2.calculation();
    double value1 = polynom1.value(5);
    double value2 = polynom2.value(5);
    std::cout << "Value of first polynomial when x = 5:" << std::endl;
    std::cout << value1 << std::endl;
    std::cout << "Value of second polynomial when x = 5:" << std::endl;
    std::cout << value2 << std::endl;
}