#include "Triangulo.hpp"

    Triangulo::Triangulo(Ponto2D p_1, Ponto2D p_2, Ponto2D p_3) {
        p1 = p_1;
        p2 = p_2;
        p3 = p_3;
    }
    
double Triangulo::calcular_area(){
    double p=(calcular_perimetro()/2);
    return sqrt(p*(p-(p1.calcular_distancia(&p2)))*(p-(p1.calcular_distancia(&p3)))*(p-(p2.calcular_distancia(&p3))));
}
double Triangulo::calcular_perimetro(){
    return ((p1.calcular_distancia(&p2))+(p1.calcular_distancia(&p3))+(p2.calcular_distancia(&p3)));
}
int Triangulo::comparar_area(Triangulo *triangulo){
    double area=calcular_area();
    if(area<triangulo->calcular_area())
        return -1;
    else{
        if(area==triangulo->calcular_area())
            return 0;
        else
            return 1;
        } 
}