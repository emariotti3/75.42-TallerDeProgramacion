#include <stdio.h>
#include <stdlib.h>
#define ARCH "fuentes.txt"
#define STAR '*'
#define BAR '/'
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 1
#endif
typedef enum{READING, COPYING, FIRST_BAR, LAST_STAR} state;

void delete_comments(){
	FILE *file = fopen(ARCH, "rb+");
	state current_state = COPYING;
	int reader = ftell(file);
	int writer = reader;
	char character[1];
	int read = 1;
	
	while (!feof(file) && (read > 0)){
		fseek(file, reader, SEEK_SET);
		read = fread(character, sizeof(char), 1, file);
		reader++;
		switch(current_state){
			case READING:
				if (character[0] == STAR){
					current_state = LAST_STAR;
				}
				break;
			case COPYING:
				if (character[0] == BAR){
					current_state = FIRST_BAR;
				}else{
					fseek(file, writer, SEEK_SET);
					fwrite(character, sizeof(char), 1, file);
					writer++;
				}
				break;
			case FIRST_BAR:
				if (character[0] == STAR){
					current_state = READING;
				}else{
					fseek(file, writer, SEEK_SET);
					character[0] = BAR;
					fwrite(character, sizeof(char), 1, file);
					writer++;
				}
				break;
			case LAST_STAR:
				if (character[0] == BAR){
					current_state = COPYING;
				}else{
					current_state = READING;
				}
				break;
		}
	}
	//ftruncate(fileno(file), writer);
	char space[1] = { ' ' };
	for (size_t i = 0; i < (reader - writer); i++){
		fwrite(space, sizeof(char), 1, file);
	}
	fclose(file);
}

int main(int argc, char *argv[]){
	delete_comments();
	return 0;
}

