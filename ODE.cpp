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
float derivadax(float t,float velocidadx,float velocidady,float x);
float derivadax2(float t,float velocidadx,float velocidady,float x);
float derivaday(float t,float velocidadx,float velocidady,float y);
float derivaday2(float t,float velocidadx,float velocidady,float y);


//velocidad
float derivadax(float velocidadx){
    return velocidadx;
}
//Aceleracion
float derivadax2(float velocidadx,float velocidady,float x){
    return (((-c)/m)*((velocidady*velocidady)+(velocidadx*velocidadx))*velocidadx)/sqrt((velocidady*velocidady)+(velocidadx*velocidadx));
}
float derivaday(float velocidady){
    return velocidady;
}
float derivaday2(float velocidadx,float velocidady,float y){
    return -g-(c/m)*((velocidady*velocidady)+(velocidadx*velocidadx))*velocidady/sqrt((velocidady*velocidady)+(velocidadx*velocidadx));
}


int main(){

    float dt=0.00085;
    int N=4000;
    float v_0=300;
    float angulo[]={45,10,20,30,40,50,60,70};
    float radianes;
for(int j=0;j<9;j++){
    float k11,k12,k21,k22,k31,k32,k41,k42;
    float l11,l12,l21,l22,l31,l32,l41,l42;
    float x[N];
    float y[N];
    float velocidadx[N];
    float velocidady[N];
    x[0]=0;
    y[0]=0;
    radianes=(angulo[j]*pi)/180.0;
    velocidadx[0]=cos(radianes)*v_0;
    velocidady[0]=sin(radianes)*v_0;

for(int i=0; i<N;i++){
    k11=dt*derivadax(velocidadx[i]);
    l11=dt*derivadax2(velocidadx[i],velocidady[i],x[i]);
    k12=dt*derivaday(velocidady[i]);
    l12=dt*derivaday2(velocidadx[i],velocidady[i],y[i]);


    k21=dt*derivadax(velocidadx[i]+0.5*l11*dt);
    l21=dt*derivadax2(velocidadx[i]+0.5*l11*dt,velocidady[i]+0.5*l12*dt,x[i]+0.5*k11*dt);
    k22=dt*derivaday(velocidady[i]+0.5*l12*dt);
    l22=dt*derivaday2(velocidadx[i]+0.5*l11*dt,velocidady[i]+0.5*l12*dt,y[i]+0.5*k12*dt);

        
    k31=dt*derivadax(velocidadx[i]+l21*0.5*dt);
    l31=dt*derivadax2(velocidadx[i]+0.5*l21*dt,velocidady[i]+0.5*l22*dt,x[i]+0.5*k21*dt);
    k32=dt*derivaday(velocidady[i]+l22*0.5*dt); 
    l32=dt*derivadax2(velocidadx[i]+0.5*l21*dt,velocidady[i]+0.5*l22*dt,y[i]+0.5*k22*dt);

    k41=dt*derivadax(velocidadx[i]+l31*0.5*dt);
    l41=dt*derivadax2(velocidadx[i]+0.5*l31*dt,velocidady[i]+0.5*l32*dt,x[i]+0.5*k31*dt);
    k42=dt*derivadax(velocidadx[i]+l32*0.5*dt);
    l42=dt*derivadax2(velocidadx[i]+0.5*l31*dt,velocidady[i]+0.5*l32*dt,y[i]+0.5*k32*dt);

    x[i+1]=dt*i;
    velocidadx[i+1]=(1.0/6)*(l11+2*l21+2*l31+l41)+velocidadx[i];
    y[i+1]=(1.0/6)*(k12+2*k22+2*k32+k42)+y[i];
    velocidady[i+1]=(1.0/6)*(l12+2*l22+2*l32+l42)+velocidady[i];
  
}
if(j==0){
   /* Creando archivo a partir de los repositorios de las clases*/ 
    ofstream file;
    file.open("ODE.txt");
    for(int i=0;i<N;i++){
    	file << x[i] <<" " << y[i] << " "<< velocidadx[i]<<" "<<velocidady[i]<< endl;
    
    }
file.close();  
}
else{
     ofstream file;
    file.open("ODESANGULOS.txt",ios::app);
    for(int i=0;i<N;i++){
    	file << x[i] <<" " << y[i] << " "<< velocidadx[i]<<" "<<velocidady[i]<< endl;
    
    }
   file.close();
}

} 
    return 0;
}


