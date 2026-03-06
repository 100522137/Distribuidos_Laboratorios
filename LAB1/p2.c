#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	for (int i = 1; i< argc; i++){
        char *end;
        strtol(argv[i], &end, 10);
        if (*end != '\0'){
            fprintf(stderr, "Argumento %d = Error de conversión.\n", i);
            return 1;
    	} 
        printf("Argumento %d = %s\n", i,argv[i]);  
    }

	return 0;
}
