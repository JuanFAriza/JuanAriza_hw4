#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define T (double)40
#define rho (double)10
#define L (double)100
#define t_ini (double)0
#define t_fin (double)200
#define num_muestras 100
#define n_puntos 1000 // Cantidad de puntos en que se divide la cuerda

int main(void){
  int i;
  int iter;
  int i_8_10 = (int)(0.8*(n_puntos - 1));
  double delta_x = L/(n_puntos - 1);
  double delta_t = 0.001;
  double c = pow((T/rho),0.5);
  double r = c*delta_t/delta_x;
  int num_iter = (int)(t_fin/delta_t); // Numero de iteraciones que se deben realizar para llegar de t_ini a t_fin
  int inter_muestra = (int)((float)num_iter/(num_muestras - 1)); // Cantidad de iteraciones antes de la siguiente muestra

  double *u_pas;
  double *u_pres;
  double *u_fut;

  u_pas = malloc(n_puntos*sizeof(double));
  u_pres = malloc(n_puntos*sizeof(double));
  u_fut = malloc(n_puntos*sizeof(double));

  for (i=0;i<i_8_10;i++){ // Inicializa la parte creciente de la condicion inicial en el pasado
    u_pas[i] = 1.25*i*delta_x/L;
  }
  for (i=i_8_10;i<n_puntos;i++){ // Inicializa la parte decreciente de la condicion inicial en el pasado
    u_pas[i] = 5 - 5*(i*delta_x)/L;
  }
  u_pas[0] = u_pres[0] = u_fut[0] = 0; // Impone condicion de frontera
  u_pas[n_puntos-1] = u_pres[n_puntos-1] = u_fut[n_puntos-1] = 0; // Impone condicion de frontera

  for (i=0;i<n_puntos;i++){ // Imprime el valor para t = 0
    printf("%f ",u_pas[i]);
  }
  printf("\n");

  for (i=1;i<n_puntos-2;i++){ // Primera iteracion
    u_pres[i] = u_pas[i] + (pow(r,2)/2.0)*(u_pas[i+1] - 2.0*u_pas[i] + u_pas[i-1]);
  }
  
  for (iter=1;iter<num_iter;iter++){ // Iteraciones sucesivas
    for (i=1;i<n_puntos-1;i++){ // Evalúa el futuro
      u_fut[i] = 2.0*(1.0 - pow(r,2))*u_pres[i] - u_pas[i] + pow(r,2)*(u_pres[i+1] + u_pres[i-1]);
    }
    for (i=1;i<n_puntos-1;i++){ // Actualiza el pasado al presente y el presente al futuro
      u_pas[i] = u_pres[i];
      u_pres[i] = u_fut[i];
    }
    if (iter%inter_muestra == 0){ // Si han transcurrido inter_muestra iteracioes se toma una muestra
      for (i=0;i<n_puntos;i++){ // Imprime los valores de la muestra
	printf("%f ",u_pres[i]);
      }
      printf("\n");
    }
  }
  for (iter=0;iter<num_muestras;iter++){ // Imprime los tiempos en que se tomo muestra
    printf("%f ",iter*inter_muestra*delta_t);
  }
  printf("\n");
  
  for (i=0;i<n_puntos;i++){ // Imprime las posiciones de cada punto
    printf("%f ",i*delta_x);
  }
  return 0;
}
