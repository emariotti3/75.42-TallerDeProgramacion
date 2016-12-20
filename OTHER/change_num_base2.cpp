/*Escriba una aplicación ANSI C++ que lea de consola un número octal
y una base (entre 2 y 16), e imprima el número leido en la base especificada.*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include <sstream>

#define DEC_BASE 10
#define BASE 8
#define POS_NUM 1
#define POS_BASE 2

//Only works from decimal to any other base.
void change_num_base(long number, long base){
    long dividend = number;
    long rmndr = 0;
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


int main(int argc, char *argv[]){
    char *number = argv[POS_NUM];
    char *base = argv[POS_BASE];
    long dec_num = strtol(number, NULL, BASE);

    change_num_base(dec_num, atoi(base));

    return 0;
}
