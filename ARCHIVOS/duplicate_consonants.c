#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define FNAME "palabras.txt"
#define MAX_CONS 2
#define SEPARATOR " "
#define BUFF_SZ 2

typedef enum {DUPLICATE, WRITE} state_t;

bool end_char(char c){
    return (c == EOF) || (c == ' ')|| (c == '\n') || (c == '\0');
}

bool is_consonant(char c){
    return ((c != 'a') && (c != 'e') && (c != 'i') && (c != 'o') && (c != 'u'));
}

int chars_to_add(char *buff, int max_cons){
    int consonants = 0;
    for(int i = 0; buff[i]; i++){
        consonants += (is_consonant(buff[i]) && (buff[i] != '\0'))? 1 : 0;
    }
    if (consonants > max_cons) return strlen(buff);
    return 0;
}

int write_word(FILE *writer, char *buffer, int word_sz, char *separator, int count){
    for (int i = 1; i <= count; i++){
      fseek(writer,-word_sz*i,SEEK_CUR);
      fwrite(buffer,sizeof(char),word_sz,writer);
    }
    if (strlen(separator) > 0){
      fseek(writer, -(word_sz + strlen(separator)),SEEK_CUR);
      fwrite(separator,sizeof(char),strlen(separator),writer);
    }
    return count*word_sz + strlen(separator);
}

void rewrite_file(FILE *file, int reader){
    int pos_reader = reader;
    int pos_writer = ftell(file);
    char buffer[BUFF_SZ];
    buffer[BUFF_SZ-1] = '\0';
    int consonants = 0, word_sz = 0;
    fseek(file,reader,SEEK_SET);
    while(pos_writer > 0){
        fseek(file, pos_reader-1, SEEK_SET);
        pos_reader = ftell(file);
        buffer[0] = fgetc(file);
        if(!end_char(buffer[0]) && (pos_reader > 0)){
            consonants += is_consonant(buffer[0])? 1 : 0;
            word_sz++;
        }else{
            char word[word_sz + 1];
            word[word_sz] = '\0';
            fread(word, sizeof(char), word_sz, file);
            fseek(file, pos_writer, SEEK_SET);
            if (consonants > MAX_CONS){
                pos_writer -= write_word(file, word, word_sz, buffer ,2);
            }else{
                pos_writer -= write_word(file, word, word_sz, buffer,1);
            }
            word_sz = 0;
            consonants = 0;
        }
    }
}

bool at_eof(FILE *file){
    int pos = ftell(file);
    bool at_end = (getc(file) == EOF);
    fseek(file, pos, SEEK_SET);
    return at_end;
}

int resize_file(FILE *file, int max_cons){
    int extra_chars = 0;
    int reader = ftell(file), pos_rdr = 0;
    while(!at_eof(file)){
        int i = 0;
        fseek(file, reader, SEEK_SET);
        for (;!end_char(getc(file));++i){}
        pos_rdr = ftell(file);
        fseek(file, reader, SEEK_SET);
        char buffer[i+1];
        buffer[i] = '\0';
        fread(buffer, sizeof(char), i, file);
        extra_chars += chars_to_add(buffer, max_cons);
        reader = pos_rdr;
    }
    reader = reader - 1; /*don't count eof line*/
    char placeholder[extra_chars];
    memset(&placeholder,'X',extra_chars*sizeof(char));
    fseek(file, reader, SEEK_SET);
    fwrite(placeholder, sizeof(char), extra_chars, file);
    return reader;
}

void duplicate_words(char *fname){
    FILE *file = fopen(FNAME, "r+");
    int reader = resize_file(file, MAX_CONS);
    rewrite_file(file, reader);
    fclose(file);
}

int main(int argc, char *argv[]){
    duplicate_words(FNAME);
    return 0;
}
