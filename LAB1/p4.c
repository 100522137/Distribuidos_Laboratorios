#include <stdio.h>
#include <stdlib.h>

void ImprimirArray(int j, char *item);

int main(int argc, char **argv)
{
    char* *vector;
    vector = (char**) malloc(80 * sizeof(char*));

	for (int i = 1; i< argc; i++){
        vector[i] = argv[i];
        ImprimirArray(i, vector[i]);
    }
    
    free(vector);
    vector = NULL;
	return 0;
}

void ImprimirArray(int j, char *item){
    printf("Argumento %d = %s\n", j,item);
}

