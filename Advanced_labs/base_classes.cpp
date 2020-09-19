#include <iostream>
#include <cmath>
#include <vector>

class Polinom
{
private:
    double args[3]{};

public: Polinom(double a, double b, double c){
    args[0] = a;
    args[1] = b;
    args[2] = c;
}

private: double * get_args(){
        return args;
    }

public: Polinom addition(Polinom polinom){
        double * to_addition = polinom.get_args();
        to_addition[0] += args[0];
        to_addition[1] += args[1];
        to_addition[2] += args[2];
        return {to_addition[0], to_addition[1], to_addition[2]};
    }

public: Polinom subtraction(Polinom polinom){
        double * to_subtraction = polinom.get_args();
        to_subtraction[0] += -args[0];
        to_subtraction[1] += -args[1];
        to_subtraction[2] += -args[2];
        return {to_subtraction[0], to_subtraction[1], to_subtraction[2]};
    }

public: Polinom multiplication(Polinom polinom){
        double * to_multiplication = polinom.get_args();
        to_multiplication[0] *= args[0];
        to_multiplication[1] *= args[1];
        to_multiplication[2] *= args[2];
        return {to_multiplication[0], to_multiplication[1], to_multiplication[2]};
    }

public: void output(){
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
            out += std::to_string(c);
        }
        else {
            out += " + " + std::to_string(c);
        }


        std::cout << out << std::endl;
    }

};

int main()
{
    Polinom polinom1 = Polinom(1, -70, 600);
    Polinom polinom2 = Polinom(1, -70, 600);
    Polinom addit = polinom1.addition(polinom2);
    Polinom multi = polinom1.multiplication(polinom2);
    Polinom subtr = polinom1.subtraction(polinom2);
    polinom1.output();
    polinom2.output();
    addit.output();
    multi.output();
    subtr.output();
}