#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int quicksort_recursivo(int arr[],int ini,int fin){
    int _ini_,_fin_,pos,aux,band;
    _ini_=ini;
    _fin_=fin;
    pos=ini;
    band=1;
    while (band==1){
        band=0;
        while((arr[pos]<=arr[_fin_])&&(pos!=_fin_)){
            _fin_--;
        }
        if (pos!=_fin_){
        	aux=arr[pos];arr[pos]=arr[_fin_];
        	arr[_fin_]=aux;
            pos=_fin_;
            while ((arr[pos]>=arr[_ini_])&&(pos!=_ini_)){
                _ini_++;
            }
            if(pos!=_ini_){
        		band=1;
                aux=arr[pos];
                arr[pos]=arr[_ini_];
                arr[_ini_]=aux;
                pos=_ini_;
            }
        }
	}
    if ((pos-1)>ini){
        quicksort_recursivo(arr,ini,pos-1);
    }
    if (fin>(pos+1)){
        quicksort_recursivo(arr,pos+1,fin);
        }
    return 0;
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int *arr, int der, int izq)
{
	int x = arr[izq];
	int i = (der - 1);
	int j;
	for ( j = der; j <= izq - 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}

	Swap(&arr[i + 1], &arr[izq]);

	return (i + 1);
}

void quicksort_iterativo(int *data, int count) {
	int startIndex = 0;
	int endIndex = count - 1;
	int top = -1;
	int* stack = (int*)malloc(sizeof(int) * count);

	stack[++top] = startIndex;
	stack[++top] = endIndex;

	while (top >= 0)
	{
		endIndex = stack[top--];
		startIndex = stack[top--];

		int p = Partition(data, startIndex, endIndex);

		if (p - 1 > startIndex)
		{
			stack[++top] = startIndex;
			stack[++top] = p - 1;
		}

		if (p + 1 < endIndex)
		{
			stack[++top] = p + 1;
			stack[++top] = endIndex;
		}
	}

	free(stack);
}

