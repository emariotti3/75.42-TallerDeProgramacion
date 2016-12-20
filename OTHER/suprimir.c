/*Defina la función SUPRIMIR sin utilizar funciones de bibliotecas. La función
debe suprimir del primer parámetro todas las ocurrencias del segundo.
char *Suprimir(char * C1,char *C2) {......}*/

#include <stdio.h>
#include <stdlib.h>
#define POS_STRING1 1
#define POS_STRING2 2


char *suprimir(char *c1, char *c2){
    char *reader = c1, *writer = c1;
    while ((*reader) != '\0'){
        while (((*reader) == *c2) && ((*reader) != '\0')){
            reader++;
        }
        *writer = *reader;
        writer++;
        reader++;
    }
    (*writer) = '\0';
    return c1;
}

int main(int argc, char *argv[]){
    char *string1 = argv[POS_STRING1];
    char *character = argv[POS_STRING2];
    char *result = suprimir(string1, character);
    printf("%s\n",result);
    return 0;
}
