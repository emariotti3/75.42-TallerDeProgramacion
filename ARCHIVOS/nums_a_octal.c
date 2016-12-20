/*Escriba un programa ISO C que procese el archivo de números datos.txt sobre
sí mismo. El procesamiento consite en convertir los números encontrados (de 1 o
más cifras decimales) a octal.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN_DEC_LENGTH 1
#define FNAME "datos.txt"
#define DECIMAL_CH ","
#define SEPARATOR " "
#define OCTAL 8
#define BUFF_SZ 2

typedef enum {RESIZE, REPLACE} state_t;

/*void change_decimal_base(float number, int *buffer, int size, int base = OCTAL){
    double whole = floor((double)number);
    double dec = (double)number - whole;

    *size = 0;
    double result = dec;
    while (result != 0){
        result = result*base - floor((double)result);
        buffer[*size] = floor((double)result);
        (*size)++;
    }
    (*size)++;
}

void change_number_base(float number, int *buffer, int size, int base = OCTAL){
    double dividend = floor((double)number);
    int digit = 1; /*for the last digit*/
    /*while (dividend >= base){
        dividend = floor(dividend / base);
        digit++;
    }
    dividend = floor((double)number);
    int buf[digit];
    for (int i = 0; i < digit; i++){
        buf[digit-i-1] = dividend % base;
        dividend = floor(dividend / base);
    }
    *buffer = *buf;
}*/

bool end_char(char c){
    return (c == EOF) || (c == ' ') || (c == '\n');
}

void change_number_base(char *fname){
    FILE *file = fopen(fname, "r+");
    int reader = ftell(file);
    while (getc(file) != EOF){
        int i = 0;
        for (;!end_char(getc(file)); i++){}
        char buffer[i + 1];
        fseek(file, reader, SEEK_SET);
        fread(buffer, sizeof(char), i, file);
        reader += i;
        long number = strtol(buffer, NULL, 10);
    }
    fclose(file);
}

int main(int argc, char *argv[]){
    change_numbers_base(FNAME);
    return 0;
}
