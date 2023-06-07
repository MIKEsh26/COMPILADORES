#include <mpi.h> 		//llamada de la libreria
#include <stdio.h>      //llamada de la libreria
#include <math.h>       //llamada de la libreria     
#include <string.h>     //llamada de la libreria

double fabs(double);		//declara argumento de tipo double 

double f(double a) {		//devuelve una funcion de tipo double 
    return (4.0 / (1.0 + a * a)); 		//retona un valor de a como double ya que la  funcion dobe f y esta devuelve el valor como un double entoces se utiliza para la formula 
}

int main(int argc, char *argv[]) {		//Comienza la ejecucion del main
    int n, myid, numprocs, i;		//se declaran las variables de tipo entero
    double PI25DT = 3.141592653589793238462643;		//se le da los valores de PI25DT en pi
    double mypi, pi, h, sum, x;		 //se declaran las variables de tipo double 
    int source, dest, tag = 100;		//se declaran las variables de tipo int 
    MPI_Status status;		//se utuliza como estructura para reprecentar el mensaje que resive 

    MPI_Init(&argc,&argv);		//es para que se ejecute una vez y lanze o inicia los nuevos procesos
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);		//indica el numero de procesos que se haran en la aplicacion 
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);		//es para que cada proceso de myid conozca su direccion
    printf("\nProcess %d of %d" , myid, numprocs);		//manda a imprimir un mensaje con los procesos y el rango en el que estamos es decir una de 4 o asi sucesivamente 
    if(myid == 0) {		// igualdad  a 0
        n = 100; 		// se le asigna un valor a n 
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);		//Hace que la variable de datos se envie a todos los procesos restantes 
    h = 1.0 / (double) n; 		// divide uno entre el valor doble por n numeros 
    sum = 0.0;		//da el valor de suma 
    for (i = myid + 1; i <= n; i += numprocs) {		//suma de intervalos 
        x = h * ((double)i - 0.5);
        sum += f(x);		//operacion suma 
    }
    mypi = h * sum;		//hace la operacion de h por la variable sum
    printf("\nProceso: %d, mypi: %.16f\n", myid, mypi);		//manda a imprimir el proceso con dos datos si es o este o este y luego manada el proceso de el cual viene y el mpi que se genero 

    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);		// se utiliza para una operacion de reduccion e
    if (myid == 0) 		//condicion si nuestro id es igual a cero va a ejecutar la siguiente linea
        printf("\npi es aproximadamente %,16f, el error cometido es %.16f", pi, fabs(pi - PI25DT));		//manda a imprimir el error de ppi 

    MPI_Finalize();		//Finalizacion del proceso  MPI
}
