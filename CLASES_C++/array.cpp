#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

template<class T = char, size_t length = 32>
class Array{
    private:
        T buffer[length];
    public:
        bool set(size_t pos, T element);
        T get(size_t pos);
};

template<class T, size_t length>
bool Array<T,length>::set(size_t pos, T element){
    if (pos >= length){
        return false;
    }
    this->buffer[pos] = element;
    return true;
}

template<class T, size_t length>
T Array<T,length>::get(size_t pos){
    return this->buffer[pos];
}

int main(int argc, char *argv[]){
    return 0;
}
