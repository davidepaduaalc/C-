#ifndef PONTO2D_H
#define PONTO2D_H

#include<cmath>

struct Ponto2D{
    double _x,_y;
    Ponto2D();
    Ponto2D(double,double);//Construtor
    double calcular_distancia(Ponto2D*); 
};
#endif