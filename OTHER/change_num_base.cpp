/*Escriba una aplicación ANSI C++ que lea de consola un número octal
y una base (entre 2 y 16), e imprima el número leido en la base especificada.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include <sstream>

#define BASE 8
#define DEC_BASE 10

//Only works from decimal to any other base.
void change_num_base(int number, int base){
    int dividend = number;
    int rmndr = 0;
    std::stack<int> my_new_number;
    while (dividend >= base){
        rmndr = dividend % base;
        dividend = dividend / base;
        my_new_number.push(rmndr);
    }
    my_new_number.push(dividend);
    while (!my_new_number.empty()){
        std::cout << my_new_number.top();
        my_new_number.pop();
    }
    std::cout << "\n";
}

//From any base to decimal.
int to_decimal(int number, int base = BASE){
    int decimalNumber = 0, i = 0, rmndr = 0;
    while (number != 0){
        rmndr = number % DEC_BASE;
        number /= DEC_BASE;
        decimalNumber += rmndr * pow(base, i);
        ++i;
    }
    return decimalNumber;
}

int main(int argc, char *argv[]){
    int number = 0, base = 0;
    std::cout << "Introduzca un numero y una base";
    std::cin >> number >> base;
    int dec_num = to_decimal(number);
    std::cout << "To decimal " << dec_num << "\n";
    change_num_base(dec_num, base);
    return 0;
}
