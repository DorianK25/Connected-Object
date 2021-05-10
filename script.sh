#!/bin/sh

export LIBRARY_PATH=$LIBRARY_PATH:/usr/local/opt/openssl/lib/

gcc -c bdd/bdd.c $(mysql_config --libs) $(mysql_config --cflags)

gcc libs/libs.c -o libtest.exe bdd.o $(mysql_config --libs) $(mysql_config --cflags)

gcc client.c -o client $(mysql_config --libs) $(mysql_config --cflags)

gcc server.c -o server $(mysql_config --libs) $(mysql_config --cflags)