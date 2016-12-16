#include <sstream>
#include <iostream>
#include "Fecha.h"

Fecha::Fecha():dia(1), mes(1), anio(1){}

Fecha::Fecha(int dia, int mes, int anio){
    if ((dia > 0) && (mes > 0) && (anio > 0)){
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }else{
        throw "Invalid date parameters!";
    }
}

Fecha::Fecha(Fecha &fecha){
    this->dia = fecha.dia;
    this->mes = fecha.mes;
    this->anio = fecha.anio;
}

bool Fecha::operator<(Fecha &fecha){
    if (this->anio < fecha.anio){
        return true;
    }else{
        if(this->anio > fecha.anio){
            return false;
        }
    }
    if (this->mes < fecha.mes){
        return true;
    }else{
        if(this->mes > fecha.mes){
            return false;
        }
    }
    return this->dia < fecha.dia;
}

bool Fecha::operator==(Fecha &fecha){
    return ((this->anio == fecha.anio) && (this->mes == fecha.mes) && (this->dia == fecha.dia));
}

void Fecha::operator=(Fecha &fecha){
    this->dia = fecha.dia;
    this->mes = fecha.mes;
    this->anio = fecha.anio;
}
/*
int Fecha::operator int(){
    int dia = this->dia*1000000;
    int mes = this->mes*10000;
    return dia + mes + this->anio;
}*/

std::ostream& operator<<(std::ostream &os, Fecha &fecha){
    std::stringstream ss;
    ss << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
    os << ss.str();
    return os;
}

void Fecha::operator++(){
    this->dia++;
}
