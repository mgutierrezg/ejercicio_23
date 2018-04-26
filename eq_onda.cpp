#include <iostream>
#include <math.h>
using namespace std;

double seno(double x);
void primer_momento(double *u1, double* u_viejo, double delta_x, double delta_t, double c,int n);
void u_in(double* u, double delta_x, double x_min, int n, double x);

double seno(double x)
{
  return sin(2*3.1459*x);
}

void u_in(double* u, double delta_x, double x_min, int n, double x){
  for (int i=0; i<n; i++){
    x = x_min + i*delta_x;
    u[i] = seno(x);
    }
}

void primer_momento(double *u_presente, double* u_viejo, double delta_x, double delta_t, double c,int n){
  double delta_x_cuadrado = delta_x * delta_x;
  double delta_t_cuadrado = delta_t * delta_t;
  double c_cuadrado = c*c;
  double k = (delta_t_cuadrado/delta_x_cuadrado)*c_cuadrado;
  for(int i=1;i<n-1;i++)
  {
    u_presente[i]=0.5*((k*(u_viejo[i+1]-2*u_viejo[i]+u_viejo[i-1]))+2*u_viejo[i]);
  }  
}

void evoluciona(double *u_nuevo, double *u_presente, double *u_viejo, int n, double delta_x, double delta_t, double c){
  double delta_x_cuadrado = delta_x * delta_x;
  double delta_t_cuadrado = delta_t * delta_t;
  double c_cuadrado = c*c;
  double k = (delta_t_cuadrado/delta_x_cuadrado)*c_cuadrado;
  for(int i=1;i<n-1;i++){
    u_nuevo[i] = (k*(u_viejo[i+1]-2* u_viejo[i]+u_viejo[i-1])) + 2*u_viejo[i] - u_presente[i];
  }
}

   
int main(){
  double delta_x = 0.03, delta_t = 0.00001;
  double x_min = 0.0, x_max = 1.0;
  double c =1.0;
  double x=0;
  int nx = (x_max-x_min)/delta_x + 1 ; 
  double *u_nuevo;
  double *u_viejo;
  double *u_ini;
  double *u_presente;
  u_nuevo = new double[nx];
  u_viejo = new double[nx];
  u_ini = new double[nx];
  u_presente = new double[nx];
  u_in(u_ini,delta_x,x_min, nx,x);
  u_in(u_viejo,delta_x,x_min, nx,x);
  u_in(u_presente,delta_x,x_min, nx,x);
  x=0;
  for(double j=0.51;j>-1;j-=0.5){
    u_nuevo[0]=0;
    u_presente[0] =0;
    u_nuevo[nx-1]=0;
    u_presente[nx-1] =0;
    primer_momento(u_presente,u_viejo,delta_x,delta_t, c,nx); 
    evoluciona(u_nuevo, u_presente, u_viejo, nx,delta_x, delta_t,c);
    for(int i=0;i<nx;i++)
      {
	u_viejo[i]=u_presente[i];
	u_presente[i] = u_nuevo[i];
      }
    }
  

  for(int i=0;i<nx;i++)
    {
      x= x_min + i*delta_x;
      cout<< x <<" "<< u_ini[i]<<" " << u_nuevo[i]<< endl;
    }
  return 0;
}
