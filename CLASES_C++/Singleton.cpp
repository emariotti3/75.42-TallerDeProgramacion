#include <stdio.h>
#include <stdlib.h>
#include "Singleton.h"

Singleton* Singleton::instance = NULL;

Singleton* Singleton::get_instance(){
    if(instance != NULL){
        return instance;
    }
    instance = new Singleton();
    return instance;
}

int main(int argc, char *argv[]){
    Singleton *s = Singleton::get_instance();
    return 0;
}
