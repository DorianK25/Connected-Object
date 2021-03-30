#include "bdd.h"


void connection(){
     mysql_init(&mysql);
    //Options de connexion
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    //Si la connexion réussie...
    if(!mysql_real_connect(&mysql,"127.0.0.1","root","root","roll_call_tab",8889,NULL,0))
    {
        printf("Une erreur s'est produite lors de la connexion a la BDD!");
    }

}

void execQuery(char * query){
    mysql_query(&mysql, query);
}


void deconnection(){
    mysql_close(&mysql);
}