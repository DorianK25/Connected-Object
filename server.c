#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "libs/libs.h"
#define PORT 8080



int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("\n\n ./script.sh <nb_de_connecion> \n\n");
        return -1;
    }

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    seance s;
    s.idSeance=1;
    s.nbPresences=0;
    presence p;
    int opt = 1;
    int addrlen = sizeof(address);
    char *buffer=malloc(sizeof(char)*2048);
    data d;
    char *obj=malloc(sizeof(char)*2048);
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

        for(int i=0;i<atoi(argv[1]);i++){
        /* code */
            new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen);
        //int pid = fork();
        
            //programme
           // classe c = getClasse("LA2");
           // groupe g= getGroupe(c,"TDB");
             read(new_socket,buffer,sizeof(buffer)*1024);
             d = deserialize(buffer);
             p = ajouterPresence(d.personne,s);
             s.listePresence[s.nbPresences] = p;
             s.nbPresences++;
             d.typeData=2;
             obj = serialize(d);
             write(new_socket , obj , sizeof(obj)*1024);

        }
             afficherPresence(s);
    
    
        
    
   
  
    return 0;
}
