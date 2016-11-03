#include <stdio.h>
#include <math.h>

#define T (double)40
#define rho (double)10
#define L (double)100
#define t_ini (double)0
#define t_fin (double)200
#define n_puntos 1000 // Cantidad de puntos en que se divide la cuerda

int main(void){
  int i;
  int iter;
  int num_muestras = 100;
  int intervalo_muestra = (int)((float)n_puntos/num_muestras)
  int i_8_10 = (int)(0.8*(n_puntos - 1))

  double *u_pas;
  double *u_pres;
  double *u_fut;
  double delta_x = L/(n_puntos - 1);
  double delta_t = 0.001;
  double c = pow((T/rho),0.5);
  double r = c*delta_t/delta_x;

  int num_iter = (int)(t_fin/delta_t);

  u_pas = malloc(n_puntos*sizeof(double));
  u_pres = malloc(n_puntos*sizeof(double));
  u_fut = malloc(n_puntos*sizeof(double));

  for (i=0;i<i_8_10;i++){ // Inicializa la parte creciente de la condicion inicial en el pasado
    u_pas[i] = 1.25*i*delta_x/L;
  }
  for (i=i_8_10;i<n_puntos;i++){ // Inicializa la parte decreciente de la condicion inicial en el pasado
    u_pas[i] = 5 - 5*(i*delta_x)/L
  }
  u_pas[0] = u_pres[0] = u_fut[0] = 0; // Impone condicion de frontera
  u_pas[n_puntos-1] = u_pres[n_puntos-1] = u_fut[n_puntos-1] = 0; // Impone condicion de frontera

  for (i=1;i<n_puntos-2;i++){ // Primera iteracion
    u_pres[i] = u_pas[i] + (pow(r,2)/2.0)*(u_pas[i+1] - 2.0*u_pas[i] + u_pas[i-1]);
  }
  for (iter=1;iter<num_iter;iter++){

  }
  return 0;
}
