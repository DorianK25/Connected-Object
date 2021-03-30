#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mysql/mysql.h>

MYSQL mysql;
MYSQL_RES *result;
MYSQL_ROW row;
MYSQL_FIELD *field;

void connection();

void execQuery(char *);

void deconnection();