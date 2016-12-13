#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FNAME_POS 1
#define ADDR_POS 2
#define NBYTES_POS 3
#define CHARS_PER_LINE 16

void print_hd_format(char *fname, int addr, int nbytes){
    FILE *file = fopen(fname, "r");
    char buffer[nbytes + 1];
    fseek(file, addr, SEEK_SET);
    fread(buffer, sizeof(char), nbytes, file);
    fclose(file);
    int div_resu = nbytes/CHARS_PER_LINE;
    int rows = ((nbytes%CHARS_PER_LINE) != 0)? div_resu + 1 : div_resu; //ceil not working!!!(?)
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < CHARS_PER_LINE; j++){
        int code = (int)buffer[i*CHARS_PER_LINE + j];
        printf("%x ", code);
      }

      for (int j = 0; j < CHARS_PER_LINE; j++){
          printf("%c", buffer[i*CHARS_PER_LINE + j]);
      }
      puts("\n");
    }
}

int main(int argc, char *argv[]){
    char *fname = argv[FNAME_POS];
    int addr = atoi(argv[ADDR_POS]);
    int nbytes = atoi(argv[NBYTES_POS]);
    print_hd_format(fname, addr, nbytes);
    return 0;
}
