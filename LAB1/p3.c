#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long minmax[2] = {INFINITY, 0} ;
void ObtenerMinMax(int n, long *vec);


int main(int argc, char **argv)
{
    long *vector;
    vector = (long*) malloc(80 * sizeof(long));

	for (int i = 1; i< argc; i++){
        char *end;
        vector[i] = strtol(argv[i], &end, 10);
        if (*end != '\0'){
            fprintf(stderr, "Argumento %d = Error de conversión.\n", i);
            return 1;
    	}
    }
    ObtenerMinMax(argc, vector);
    printf("Valor mínimo = %ld\nValor máximo = %ld\n", minmax[0],minmax[1]);

    free(vector);
    vector = NULL;

	return 0;
}

void ObtenerMinMax(int n, long *vec){
    for (int j = 1; j < n; j++){
        if(vec[j] < minmax[0]){
            minmax[0] = vec[j];
        }
        if(vec[j] > minmax[1]){
            minmax[1] = vec[j];
        } 
    }
}

