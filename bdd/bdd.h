#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mysql/mysql.h>

MYSQL mysql;
MYSQL_RES *result;
MYSQL_ROW row;
MYSQL_FIELD *field;
int state;

void connection();

int execQuery(char *);

void deconnection();