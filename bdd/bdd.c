#include "bdd.h"


void connection(){
     mysql_init(&mysql);
    //Options de connexion
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    //Si la connexion réussie...
    if(!mysql_real_connect(&mysql,"127.0.0.1","root","root","roll_call_tab",3306,NULL,0))
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

int main(int argc, char **argv){
    mysql_init(&mysql);
            //Options de connexion
            mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
            //Si la connexion réussie...
            if(mysql_real_connect(&mysql,"127.0.0.1","root","root","roll_call_tab",3306,NULL,0))
            {
                //On déclare un tableau de char pour y stocker la requete
                //char requete[150] = "INSERT INTO classe VALUES('1', 'LA1')";
                char requete[150] = "Select * from classe";

 
                //On execute la requete
                mysql_query(&mysql, requete);
                MYSQL_RES *result = mysql_store_result(&mysql);
                MYSQL_ROW row;
                MYSQL_FIELD *field;
                int num_fields = mysql_num_fields(result);

                while ((row = mysql_fetch_row(result)))
                {
                    for(int i = 0; i < num_fields; i++)
                    {
                        if (i == 0)
                        {
                            while(field = mysql_fetch_field(result))
                            {
                                printf("%s ", field->name);
                            }

                            printf("\n");
                        }
                        printf("%s ", row[i] ? row[i] : "NULL");
                    }

                    printf("\n");
                }

 
                //Fermeture de MySQL
                
            }
            else
            {
                
            }
 
    return 0;
}