#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#def MAX_THREADS 8

pasos largos estáticos = 10000000000;
doble paso;

int main (int argc, const char *argv[]) {

    int i,j;
    doble x;
    doble pi, suma = 0,0;
    doble arranque, delta;

 paso = 1.0/(doble) pasos;

    // Calcular tiempos de cómputo paralelos para 1-MAX_THREADS
    para (j=1; j<= MAX_THREADS; j++) {

        printf(" ejecutándose en %d threads: ", j);

        // Este es el comienzo de un solo cálculo de PI 
        omp_set_num_threads j);

 suma = 0,0;
        inicio doble = omp_get_wtime();

#pragma omp paralelo para reducción(+:suma) privado(x)
        for (i=0; i < pasos; i++) {
 x = (i+0,5)*paso;
 suma += 4.0 / (1.0+x*x); 
        }

        // Fuera de la región paralela, finializar el cálculo
        pi = paso * suma;
 delta = omp_get_wtime() - inicio;
        printf("PI = %.16g calculado en %.4g segundos\n", pi, delta);

    }
    

}
