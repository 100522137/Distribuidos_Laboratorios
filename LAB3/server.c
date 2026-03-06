#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lines.h"

#define MAX_LINE 	256
int main(int argc, char *argv[])
{
        int sd, sc;
	int val;
	int err;
        struct sockaddr_in server_addr,  client_addr;
        
        sd =  socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sd < 0) {
                perror("Error in socket");
                exit(1);
        }

        val = 1;
        err = setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (char *) &val,
                sizeof(int));
        if (err < 0) {
                perror("Error in opction");
                exit(1);
        }


	// Complete .....
        bzero((char *)&server_addr, sizeof(server_addr));
    	server_addr.sin_family      = AF_INET;
    	server_addr.sin_addr.s_addr = INADDR_ANY;
    	server_addr.sin_port        = htons(atoi(argv[1]));

    	err = bind(sd, (const struct sockaddr *)&server_addr,
			sizeof(server_addr));
	if (err == -1) {
		printf("Error en bind\n");
		return -1;
	}
        
        err = listen(sd, SOMAXCONN);
	if (err == -1) {
		printf("Error en listen\n");
		return -1;
	}

        size_t size = sizeof(client_addr);
        char buffer[MAX_LINE];
        int n;

        while(1){
                printf("esperando conexion\n");
                sc = accept(sd, (struct sockaddr *)&client_addr, (socklen_t *)&size);        
                if (sc == -1) {
                                printf("Error en accept\n");
                                return -1;
                        }
                        printf("conexión aceptada de IP: %d   Puerto: %d\n",
                                        inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));


                
                

                while(1){
                        n = readLine(sc, buffer, 256);
                        if(n == -1){
                                printf("Error en readLine\n");
                                break;
                        }

                        err = sendMessage(sc, buffer, strlen(buffer)+1); // Envía la cadena y '\0'
                        if(err == -1){
                                printf("Error en envío\n");
                                break;
                        }

                        printf("Recibido: %s\n", buffer);
                        if(strcmp(buffer, "EXIT") == 0){
                                close (sc);
                                break;
                        }
                }
        }
        return(0);
}

