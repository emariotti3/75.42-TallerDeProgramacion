#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FILE_NAME "in.txt"
#define BUFF_SZ 2
#define BYTES 1

bool is_digit(char *character){
    bool is_num = ((*character) == '0') || ((*character) == '1') || ((*character) == '2');
    is_num = is_num || ((*character) == '3') || ((*character) == '4') || ((*character) == '5');
    is_num = is_num || ((*character) == '6') || ((*character) == '7') || ((*character) == '8');
    is_num = is_num || ((*character) == '9');
    return is_num;
}

void eliminar_numeros(char *file_name){
    FILE *file = fopen(file_name, "r+");
    int reader = ftell(file), writer = ftell(file);
    char letter[BUFF_SZ];
    while (fgetc(file) != EOF){
        fseek(file, reader, SEEK_SET);
        bool is_number = true;
        int letters_seen = 0;
        fread(letter,BYTES,1,file);
        while ((letter[0]!=' ') && (!feof(file))){
            letters_seen++;
            is_number = is_number && is_digit(letter);
            fread(letter,BYTES,1,file);
        }
        letters_seen++;
        reader = ftell(file);
        if (is_number){
            fseek(file, writer, SEEK_SET);
            fwrite(letter, BYTES, 1, file);
        }else{
            fseek(file,reader-letters_seen,SEEK_SET);
            char word[letters_seen + 1];
            fread(word, BYTES, letters_seen, file);
            fseek(file, writer, SEEK_SET);
            fwrite(word, BYTES, letters_seen, file);
        }
        writer = ftell(file);
        fseek(file, reader, SEEK_SET);
    }
    char buffer[reader-writer];
    memset(buffer,'\0',reader-writer);
    fseek(file, writer, SEEK_SET);
    fwrite(buffer, BYTES, reader-writer, file);
    fclose(file);
}

int main(int arcg, char *argv[]){
    eliminar_numeros(FILE_NAME);
    return 0;
}
