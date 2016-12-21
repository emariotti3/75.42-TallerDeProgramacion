/*
El símbolo de precompilación __LINE__ se expande como el número de
línea donde se encuentra.Demuestre mediante un ejemplo su utilidad.
*/

/*El simbolo __LINE__ es una macro predefinida por el compilador que, a pesar
de estar predefinida, posee un valor variable: al expandirse, es reemplazada
por el numero de linea donde fue invocada. Es muy utilizada para el manejo de
excepciones y la deteccion de errores, ya que nos permite saber en que linea de
codigo se origina un error. Veamos el siguiente ejemplo:*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <exception>
#define DIVIDEND 5

class ZeroDivisionError: public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Zero division error!";
        }
} ZeroDivErr;

void print_division(int dividend){
    for (int i = dividend; i >= 0; --i){
        if (i == 0) throw ZeroDivErr;
        std::cout << dividend / i << "\n";
    }
}

int main(int argc, char *argv[]){
    try{
        print_division(DIVIDEND);
    }catch(ZeroDivisionError &e){
        std::cout << e.what() << "at line" << __LINE__ << "\n";
    }
    return 0;
}
