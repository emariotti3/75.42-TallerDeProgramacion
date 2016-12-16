#ifndef FECHA_H
#define FECHA_H

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        Fecha(Fecha &fecha);
        bool operator<(Fecha &fecha);
        bool operator==(Fecha &fecha);
        void operator=(Fecha &fecha);
        /*int operator int();*/
        friend std::ostream& operator<<(std::ostream &os, Fecha &fecha);
        void operator++();
};

#endif
