#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>

void imprimeArreglo(int*,int);
int* crearArregloAleatorio(int);

int main(int argc, char **argv)
{
    
    int i;
    int* arr;
    //para tener excel con quicksort recursivo habilitar la linea 21 y comentar '//' linea 22
    //ademas habilitar linea 35 y comentar '//' linea 36
    int file = open("quicksort_recursivo.csv", O_WRONLY | O_CREAT | O_TRUNC);
	//int file = open("quicksort_iterativo.csv", O_WRONLY | O_CREAT | O_TRUNC);
    char str[50];
    struct timeval t1, t2;
    double tiempo;
    
    int n = 100;
    //para mas datos en lugar de i<100 poner ejm i < 1000
    for(i = 0; i < 6000; i++){
        sprintf(str, "%d;", n);
        write(file, str, strlen(str));
        arr = crearArregloAleatorio(n);
        
        gettimeofday(&t1, NULL);
        quicksort_recursivo(arr,0,n-1);
        //quicksort_iterativo(arr,n);
		gettimeofday(&t2, NULL);
        
        tiempo = (t2.tv_sec - t1.tv_sec)*1000 + (t2.tv_usec - t1.tv_usec)/1000.0;
        sprintf(str, "%f\n", tiempo);
        write(file, str, strlen(str));
        
        free(arr);
        n += 100;
    }
    
    close(file);
    return 0;
    
}

void imprimeArreglo(int* arr, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int* crearArregloAleatorio(int n){
    int* aux = (int*) malloc(sizeof(int) * n);
    int i;
    srand(time(0));
    for(i = 0; i < n; i++){
        aux[i] = rand();
    }
    return aux;
}
