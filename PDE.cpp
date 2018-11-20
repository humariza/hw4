#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
/* 
Condiciones iniciales
*/
float k=1.62;
float cp=820;
float rho=2.71;
float radio=5;
float v;
float tvarilla=100;
float tcalcita=10;

int main(){
v=k/(cp*rho);

ofstream file;
file.open("PDE.txt");   
file <<"Holi";    
file.close();  
    return 0;
}
