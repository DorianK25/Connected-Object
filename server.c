#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "libs/libs.h"
#define PORT 8080

void loadData(data data){
    switch (data.typeData)
    {
        // emargement 
    case 1:
        printf("Bonjour %s %s",data.personne.nom, data.personne.prenom);
        break;

   /* case "":
        break;*/
    
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *buffer;
    char *hello;
    connection();
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = PORT;
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
        /* code */
            new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen);
        //int pid = fork();
        
            //programme
            classe c = getClasse("LA2");
            groupe g= getGroupe(c,"TDB");
            read(new_socket,buffer,sizeof(buffer));
            personne p=getPersonne(buffer,g);
            strcpy(hello,"Bonjour ");
            strcat(hello,p.nom);
            strcat(hello," ");
            strcat(hello,p.prenom);
            strcat(hello," et bienvenue sur la roll call tab\n");
            write(new_socket , hello , strlen(hello));
    
    
        
    
   
  
    return 0;
}