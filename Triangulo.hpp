#ifndef TRIANGULO_H
#define TRIANGULO_H

#include<cmath>
#include "Ponto2D.hpp"

struct Triangulo{
    Ponto2D p1,p2,p3;
    Triangulo(Ponto2D,Ponto2D,Ponto2D);
    double calcular_area();
    double calcular_perimetro();
    int comparar_area(Triangulo*);

};
#endif