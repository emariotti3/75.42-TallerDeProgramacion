/*Escriba una aplicación C que lea de la línea de comandos un número
y lo imprima en todas las bases entre 2 y 16.*/
#include <stdio.h>
#include <stdlib.h>

#define POS_NUM 1
#define MIN_BASE 2
#define MAX_BASE 16
#define BASE_TEN 10


void print_num_in_base_n(int number, int base){
    int dividend = number;
    int length = 0;
    if (base == BASE_TEN){
        printf("Number %d in base %d is %d", number, base, number);
    }else{
      for (; dividend >= base; ++length){
          dividend = dividend / base;
      }
      int buffer[length + 1];
      dividend = number;
      for (int i = 0; dividend >= base; ++i){
          buffer[length-i] = dividend % base;
          dividend = dividend / base;
      }
      buffer[0] = dividend;
      printf("Number %d in base %d is ", number, base);
      for (int i = 0; i <= length; ++i){
          printf("%d", buffer[i]);
      }
    }
    puts("\n");
}

void print_number_in_bases(int number, int min_base, int max_base){
    for (int i = min_base; i <= max_base; ++i){
        print_num_in_base_n(number, i);
    }
}

int main(int argc, char *argv[]){
    int number = atoi(argv[POS_NUM]);
    print_number_in_bases(number, MIN_BASE, MAX_BASE);
    return 0;
}
