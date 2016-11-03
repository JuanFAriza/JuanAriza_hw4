#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L 0.05 // Longitud lateral del cuadro
#define l 0.02 // Longitud de la placa
#define d 0.01 // Separacion entre placas
#define V0 (float)(100) // Diferencia de potencial entre placas
#define h 0.0002 // Longitud de cada celda de la rejilla
#define N (int)(2*pow((L/h),2)) // Numero de iteraciones

int main(void){
  int i,j,iter;
  int n = (int)(L/h); // Numero de celdas
  int j0Placa, jfPlaca, iPlaca1, iPlaca2; // Posicion de las placas
  
  j0Placa = (int)(((L/2) - (l/2))/h);
  jfPlaca = (n-1) - j0Placa;
  iPlaca1 = (int)(((L/2) - (d/2))/h);
  iPlaca2 = (n-1) - iPlaca1;

  double *V; // Matriz de potencial electrico presente
  double *Vfuturo; // Matriz de potencial electrico futuro

  V = malloc(n*n*sizeof(double));
  Vfuturo = malloc(n*n*sizeof(double));

  for (i=0;i<n;i++){ // Inicializa en 0 las columnas en el borde pres. y fut.
    Vfuturo[n*i+0] = V[n*i+0] = 0;
    Vfuturo[n*i+n-1] = V[n*i+n-1] = 0;
  }
  for (j=0;j<n;j++){ // Inicializa en 0 las filas en el borde
    Vfuturo[n*0+j] = V[n*0+j] = 0;
    Vfuturo[n*(n-1)+j] = V[n*(n-1)+j] = 0;
  }

  for (i=1;i<n-1;i++){ // Inicializa TODO el interior en 1
    for (j=1;j<n-1;j++){
      V[n*i+j] = 1;
    }
  }

  for (j=j0Placa;j<jfPlaca+1;j++){ // Fija el voltaje en las placas
    Vfuturo[n*iPlaca1+j] = V[n*iPlaca1+j] = -V0/2;
    Vfuturo[n*iPlaca2+j] = V[n*iPlaca2+j] = V0/2;
  }

  for (iter=0;iter<N;iter++){
    for (i=1;i<n-1;i++){ // Actualiza el futuro de acuerdo al presente
      for (j=1;j<n-1;j++){
	Vfuturo[n*i+j] = (0.25)*(V[n*i+j+1]+V[n*(i+1)+j]+V[n*i+j-1]+V[n*(i-1)+j]);
      }
    }
    for (i=1;i<n-1;i++){ // Actualiza el presente al futuro
      for (j=1;j<n-1;j++){
	V[n*i+j] = Vfuturo[n*i+j];
      }
    }
    for (j=j0Placa;j<jfPlaca+1;j++){ // Fija el voltaje en las placas
      Vfuturo[n*iPlaca1+j] = V[n*iPlaca1+j] = -V0/2;
      Vfuturo[n*iPlaca2+j] = V[n*iPlaca2+j] = V0/2;
    }
  }

  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      printf("%.2f ",V[n*i+j]);
    }
    printf("\n");
  }
  return 0;
}
