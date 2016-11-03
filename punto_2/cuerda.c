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
  int i_8_10 = (int)(0.8*(n_puntos - 1))

  double *u_pas;
  double *u_pres;
  double *u_fut;
  double delta_x = L/(n_puntos - 1);
  double delta_t;
  double c = pow((T/rho),0.5);

  u_pas = malloc(n_puntos*sizeof(double));
  u_pres = malloc(n_puntos*sizeof(double));
  u_fut = malloc(n_puntos*sizeof(double));

  for (i=0;i<i_8_10;i++){
    u_pres[i] = 1.25*i*delta_x/L;
  }
  for (i=i_8_10;i<n_puntos;i++){
    u_pres[i] = 5 - 5*(i*delta_x)/L
  }
  return 0;
}
