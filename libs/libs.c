#include "libs.h"

void afficherClasse(){
    char query[250]="Select *from classe";
    execQuery(query);
    result = mysql_store_result(&mysql);
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

}
void ajouterClasse(){
    char query[250]="INSERT INTO `classe` (`idClasse`, `nomClasse`) VALUES(NULL,'prof')";
    execQuery(query);
}

int main(){
    connection();
    afficherClasse();
    ajouterClasse();
}