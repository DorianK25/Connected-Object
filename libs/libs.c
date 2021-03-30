#include "libs.h"

void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}

void itoa(int n, char s[])
 {
     int i, sign;
     if ((sign = n) < 0) 
         n = -n;          
     i = 0;
     do {       
         s[i++] = n % 10 + '0'; 
     } while ((n /= 10) > 0);     
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
}

void afficherClasse(){
    char query[250]="SELECT nomClasse FROM classe";
    execQuery(query);
    result = mysql_store_result(&mysql);
    int num_fields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result)))
    {
        for(int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

}

void ajouterClasse(classe c){
    char query[1024]="";
    strcat(query,"INSERT INTO `classe` (`idClasse`, `nomClasse`) VALUES(NULL,'");
    strcat(query,c.nom);
    strcat(query,"')");
    execQuery(query);
}

void afficherGroupe(classe c){
    char id[20];
    itoa(c.idClasse,id);
    char query[1024]="SELECT nomGroupe FROM groupe WHERE idClasse=";
    strcat(query,id);
    execQuery(query);
    result = mysql_store_result(&mysql);
    int num_fields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result)))
    {
        for(int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

}


void ajouterGroupe(groupe g){
    char id[20];
    itoa(g.classe.idClasse,id);
    char query[1024]="";
    strcat(query,"INSERT INTO `groupe` (`idGroupe`, `nomGroupe`, `idClasse`) VALUES(NULL,'");
    strcat(query,g.nom);
    strcat(query,"',");
    strcat(query,id);
    strcat(query,")");
    execQuery(query);
}


void ajouterPersonne(personne p){
    char idgroupe[20];
    itoa(p.groupe.idGroupe,idgroupe);
    char idAdmin[20];
    itoa(p.isAdmin,idAdmin);
    char idNFC[20];
    itoa(p.idNFC,idNFC);
    char query[1024]="";
    strcat(query,"INSERT INTO `personne` (`idPersonne`, `nomPersonne`, `prenomPersonne`, `isAdmin`, `idNFC`, `idGroupe`) VALUES(NULL,'");
    strcat(query,p.nom);
    strcat(query,"','");
    strcat(query,p.prenom);
    strcat(query,"',");
    strcat(query,idAdmin);
    strcat(query,",");
    strcat(query,idNFC);
    strcat(query,",");
    strcat(query,idgroupe);
    strcat(query,")");
    execQuery(query);
}

int main(){
    classe c;
    c.nom = "LA2";
    groupe g;
    g.nom = "TDB";
    c.idClasse=3;
    g.classe=c;
    personne p;
    p.nom = "Branlant";
    p.prenom = "Theodorine";
    p.isAdmin = 0;
    p.idNFC = 1;
    g.idGroupe = 1;
    p.groupe = g;
    connection();
    ajouterClasse(c);
    afficherClasse();
    ajouterGroupe(g);
    afficherGroupe(c);
    ajouterPersonne(p);
}