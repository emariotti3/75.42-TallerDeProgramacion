#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

template<class T = char>
class Array{
    private:
        T *_buffer;
        size_t _len;
    public:
        Array(size_t length = 64);
        ~Array();
};

template<class T>
Array<T>::Array(size_t length):_len(length){
    this->_buffer = (T*)malloc(sizeof(T)*length);
}

template<class T>
Array<T>::~Array(){
    free(this->_buffer);
}

int main(int argc, char *argv[]){
    Array<> ch_array();
    Array<int> int_array(32);
    return 0;
}
