#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mysql/mysql.h>


int main(int argc, char **argv){
    MYSQL mysql;
    mysql_init(&mysql);
            //Options de connexion
            mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
             int etat_activee = "etat_activee";
            //Si la connexion réussie...
            if(mysql_real_connect(&mysql,"localhost","root","password","composant_live",0,NULL,0))
            {
                //On déclare un tableau de char pour y stocker la requete
                char requete[150] = "";
 
                //On stock la requete dans notre tableau de char
                sprintf(requete, "INSERT INTO classe VALUES('1', 'LA1')", etat_activee);
 
 
                //On execute la requete
                mysql_query(&mysql, requete);

 
                //Fermeture de MySQL
                mysql_close(&mysql);
            }
            else
            {
                printf("Une erreur s'est produite lors de la connexion a la BDD!");
            }
 
    return 0;
}