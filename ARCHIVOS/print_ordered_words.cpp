#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <list>
#include <tuple>

typedef std::tuple<size_t, char*> Word;
typedef std::list<Word>::iterator WordIt;

#define LENGTH 0
#define WORD_PTR 1

bool compare_words(Word &word1, Word &word2){
    return (std::get<LENGTH>(word1) > std::get<LENGTH>(word2));
}

void print_words(char **words){
    std::list<Word> word_list;
    while ((*words) != '\0'){
        Word word(strlen(*words),*words);
        word_list.push_back(word);
        words++;
    }
    word_list.sort(compare_words);
    for (WordIt it = word_list.begin(); it != word_list.end(); it++){
        printf("%s,", std::get<WORD_PTR>(*it));
    }
}

int main(int argc, char *argv[]){
    print_words(argv +1);
    return 0;
}
