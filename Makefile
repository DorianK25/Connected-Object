test: bdd.o client server
	rm bdd.o
client: client.c
	gcc client.c -o client
server: server.c
	gcc server.c -o server
clean:
	rm client server