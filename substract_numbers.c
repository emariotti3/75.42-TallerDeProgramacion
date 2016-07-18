#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	FILE *file = fopen("enteros.txt", "rb+");
	int reader = 0;
	int writer = 0;
	unsigned int entero1 = 0, entero2 = 0;
	int resu = 0;
	fseek(file, reader, SEEK_SET);
	while (!feof(file)){
		fread(&entero1, sizeof(int), 1, file);
		fread(&entero2, sizeof(int), 1, file);
		reader = ftell(file);
		resu = entero1 - entero2;
		fseek(file, writer, SEEK_SET);
		fwrite((const void*)&resu, sizeof(int), 1, file);
		writer = ftell(file);
		fseek(file, reader, SEEK_SET);
	}
	
	ftruncate(fileno(file), writer);
	fclose(file);
	return 0;
}
