/*Escribir un programa C que procese el archivo texto.txt sobre sí mismo.
El proceso consiste en triplicar las palabras que tengan todas las vocales.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CHECK 'c'
#define PLACEHOLDER 'X'
#define FNAME "texto.txt"
#define TRIPLE 3

bool is_eof(FILE *file){
    int pos = ftell(file);
    bool end = (getc(file) == EOF);
    fseek(file, pos, SEEK_SET);
    return end;
}

bool is_end_char(char c){
    return ((c == ' ') || (c == '\n'));
}

bool word_has_vocals(char *word){
    char vocals[] = {'a', 'e', 'i', 'o', 'u', '\0'};
    bool has_vocals = true;
    for (int i = 0; word[i]; ++i){
        for (int j = 0; vocals[j]; ++j){
            if (vocals[j] == word[i]){
                vocals[j] = CHECK;
            }
        }
    }
    for (int i = 0; vocals[i]; ++i){
        has_vocals = has_vocals && (vocals[i] == CHECK);
    }
    return has_vocals;
}

int word_len(FILE *file){
    //Calculates previous word's length
    //leaves file ptr at beginning of that word.
    int len = 0;
    int pos = ftell(file);
    for (;!is_end_char(getc(file));++len){}
    fseek(file, pos, SEEK_SET);
    return len;
}

int word_len_back(FILE *file){
    //Calculates previous word's length
    //leaves file ptr at beginning of that word.
    int len = 0;
    int pos = ftell(file);
    for (;!is_end_char(getc(file)) && (ftell(file)>1);len++){
        fseek(file, pos-(len+1), SEEK_SET);
    }
    if (ftell(file)==1) len++;
    return len;
}

void triple_words(FILE *file, int reader_pos){
    fseek(file, 0, SEEK_END);
    int reader = reader_pos, writer = ftell(file);
    int times = 0;
    char character[2];
    while (writer > 0){
        fseek(file, reader - 1, SEEK_SET);
        fread(character, sizeof(char), 1, file);
        if(is_end_char(*character)){
            fseek(file, writer, SEEK_SET);
            fwrite(character, sizeof(char), 1, file);
            writer--;
            reader--;
        }else{
            fseek(file, reader - 1, SEEK_SET);
            int len = word_len_back(file);
            char word[len + 1];
            word[len] = '\0';
            fread(word, sizeof(char), len, file);
            times = word_has_vocals(word) ? TRIPLE : 1;
            writer = writer - (times*len-1);
            fseek(file, writer, SEEK_SET);
            for (int i = 0; i < times; ++i){
                fwrite(word, sizeof(char), len, file);
            }
            reader = reader - len;
            writer--;
        }
    }
}

int resize_file(FILE *file){
    int to_add = 0;
    int flen = 0;
    while (!is_eof(file)){
        if(!is_end_char(fgetc(file))){
            fseek(file, -1, SEEK_CUR);
            int len = word_len(file);
            char word[len + 1];
            word[len] = '\0';
            fread(word, sizeof(char), len, file);
            if (word_has_vocals(word)){
                to_add += len*2;
            }
        }
    }
    fseek(file, -1, SEEK_END);
    flen = ftell(file);
    char ph[] = {PLACEHOLDER};
    for (int i = 0; i < to_add; ++i){
      fwrite(ph, sizeof(char), 1, file);
    }
    return flen;
}

void triple_words_with_all_vocals(char *fname){
    FILE *file = fopen(fname, "r+");
    int old_flen = resize_file(file);
    triple_words(file, old_flen);
    fclose(file);
}

int main(int argc, char *argv[]){
    triple_words_with_all_vocals(FNAME);
    return 0;
}
