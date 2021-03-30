test: libs/libs.c main.c
	gcc libs/libs.c -o libtest.exe
	gcc main.c -o main.exe
	