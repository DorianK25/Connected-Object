test: libs/libs.c bdd.o
	gcc libs/libs.c -o libtest.exe bdd.o $(mysql_config --libs) $(mysql_config --cflags)
	rm bdd.o
bdd.o: bdd/bdd.c
	gcc -c bdd/bdd.c $(mysql_config --libs) $(mysql_config --cflags)
