#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTENCE_POS 1
#define WORDS 2

void search_and_replace(int argc, char *argv[], 
						char *word_to_replace, char *replacement){
	int len = strlen(replacement);

	for (int i = SENTENCE_POS; i < argc - 2; i++){	
		if (strncmp(argv[i], word_to_replace, len) == 0){
			printf("%s ", replacement);
		}else{
			printf("%s ", argv[i]);
		}
	}
}

int main(int argc, char *argv[]){
	char *replacement = argv[argc-1];
	char *word_to_replace = argv[argc-2];
	search_and_replace(argc, argv, word_to_replace, replacement);
	return 0;
}
