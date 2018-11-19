#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
using namespace std;
float pi=3.1416;
float g=10;
float m=0.2;
float c=0.2;
/* Son necesarias 4 derivdas, la primera y segunda derivada en x
y la primera y segunda derivada en y
*/
double derivadax(double t,double velocidadx,double velocidady,double x);
double derivadax2(double t,double velocidadx,double velocidady,double x);
double derivaday(double t,double velocidadx,double velocidady,double y);
double derivaday2(double t,double velocidadx,double velocidady,double y);


//velocidad
double derivadax(double t,double velocidadx,double velocidady,double x){
    return velocidadx;
}
//Aceleracion
double derivadax2(double t,double velocidadx,double velocidady,double x){
    return (((-c)/m)*velocidadx*((velocidady*velocidady)+(velocidadx*velocidadx))*velocidadx)/sqrt((velocidady*velocidady)+(velocidadx*velocidadx));
}
double derivaday(double t,double velocidadx,double velocidady,double y){
    return velocidady;
}
double derivaday2(double t,double velocidadx,double velocidady,double y){
    return -g-(((c)/m)*velocidadx*((velocidady*velocidady)+(velocidadx*velocidadx))*velocidady)/sqrt((velocidady*velocidady)+(velocidadx*velocidadx));
}


int main(){
    float dt=0.001;
    int N=2000;
    float x_0=0;
    float y_0=0;
    float v_0=300;
    float t_0=0;
    float radianes=(45.0*pi)/180.0;










    return 0;
}

