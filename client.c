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
	char *hello = "Hello from client";
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

    printf("%d",serv_addr.sin_port);

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	classe c = getClasse("LA2");
	groupe g = getGroupe(c,"TDB");
	personne p = getPersonne(1,g);
	d.typeData = 1;
	d.personne = p;
	send(sock, (void *)&d, sizeof(d), 0 );
/*	printf("Hello message sent\n");
	valread = read(sock, buffer, 1024);
	printf("%s\n", buffer );*/
	return 0;
}
