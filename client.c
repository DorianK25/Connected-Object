// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "libs/libs.h"
#define PORT 8080



int main(int argc, char const *argv[])
{
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char *obj="cc";
	char buffer[1024] = {0};
	data d;
	//c.idCours =23;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = PORT;
	
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	d.typeData=1;
	d.personne.idNFC="AFC432";
	obj=serialize(d);
	write(sock, obj, 2048*sizeof(char));
	read(sock,buffer,2048*sizeof(char));
	d=deserialize(buffer);
	printf("Bonjour %s %s \n",d.personne.prenom,d.personne.nom);
	return 0;
}
