/*Escriba una aplicación C que modifique el archivo a.dat eliminando
los bytes mayores a 0xC3.*/
#include <stdio.h>
#include <stdlib.h>

#define FNAME "a.dat"
#define NUMBER 0XC3

bool is_eof(FILE *file){
    int pos = ftell(file);
    bool end = (getc(file) == EOF);
    fseek(file, pos, SEEK_SET);
    return end;
}

void delete_bytes_greater_than(char *fname, int number){
    FILE *file = fopen(fname, "rb+");
    int reader = 0, writer = 0;
    int buffer[1];
    while(!is_eof(file)){
        fread(buffer, sizeof(char),1,file);
        reader = ftell(file);
        if (buffer[0] <= number){
            fseek(file,writer,SEEK_SET);
            fwrite(buffer,sizeof(char),1,file);
            writer = ftell(file);
        }
        fseek(file,reader,SEEK_SET);
    }
}

int main(int argc, char *argv[]){
    delete_bytes_greater_than(FNAME, NUMBER);
    return 0;
}
