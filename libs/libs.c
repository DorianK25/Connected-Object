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


classe getClasse(char* nom){
    classe c;
    int retval=0;
    char query[1024]="";
    strcat(query,"SELECT EXISTS(SELECT * from classe WHERE nomClasse='");
    strcat(query,nom);
    strcat(query,"')");
    execQuery(query);
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(atoi(row[0])>0){
        strcpy(query,"");
        strcat(query,"SELECT * from classe WHERE nomClasse='");
        strcat(query,nom);
        strcat(query,"'");
        execQuery(query);
        result = mysql_store_result(&mysql);
        int num_fields = mysql_num_fields(result);
        row = mysql_fetch_row(result);
        c.idClasse=atoi(row[0]);
        c.nom=row[1];
    }else{
        c.idClasse=-1;
        c.nom="Undefined";
    }
    
    
    return c;
    
    
}
/*
groupe getGroupeById(int id){
    groupe g;
    
    char query[250]="SELECT EXISTS(SELECT * from groupe WHERE idGroupe=";
    char idS[20];
    itoa(id,idS);
    strcat(query,idS);
    strcat(query,")");
    execQuery(query);
    result = mysql_store_result(&mysql);
    int num_fields = mysql_num_fields(result);
    row = mysql_fetch_row(result);
    if(atoi(row[0])>0){
        char query[250]="SELECT EXISTS(SELECT * from groupe WHERE idGroupe=";
        char idS[20];
        itoa(id,idS);
        strcat(query,idS);
        execQuery(query);
        result = mysql_store_result(&mysql);
        int num_fields = mysql_num_fields(result);
        row = mysql_fetch_row(result);
        g.idGroupe=atoi(row[0]);
        g.classe=getClasseById();
        g.nom=nom;
    }else{
        g.idGroupe=-1;
    }
    return g;
}*/

groupe getGroupe(classe c,char* nom){
    groupe g;
    g.classe=c;
    g.nom=nom;
    char query[250]="SELECT EXISTS(SELECT * from groupe WHERE idClasse=";
    char id[20];
    itoa(c.idClasse,id);
    strcat(query,id);
    strcat(query," AND nomGroupe='");
    strcat(query,nom);
    strcat(query,"')");
    execQuery(query);
    result = mysql_store_result(&mysql);
    int num_fields = mysql_num_fields(result);
    row = mysql_fetch_row(result);
    if(atoi(row[0])>0){
        strcpy(query,"SELECT * from groupe WHERE idClasse=");
        strcat(query,id);
        strcat(query," AND nomGroupe='");
        strcat(query,nom);
        strcat(query,"'");
        execQuery(query);
        result = mysql_store_result(&mysql);
        int num_fields = mysql_num_fields(result);
        row = mysql_fetch_row(result);
        g.idGroupe=atoi(row[0]);
    }else{
        g.idGroupe=-1;
    }
    return g;
}

personne getPersonne(char * idNFC){
    personne p;
    p.idNFC=idNFC;
    char query[250]="SELECT EXISTS(SELECT * from personne WHERE idNFC='";
    char id[20];
    char idG[20];
    strcat(query,p.idNFC);
    strcat(query,"')");
    execQuery(query);
    result = mysql_store_result(&mysql);
    int num_fields = mysql_num_fields(result);
    row = mysql_fetch_row(result);
    if(atoi(row[0])>0){
        strcpy(query,"SELECT * from personne WHERE idNFC='");
        strcat(query,p.idNFC);
        strcat(query,"'");
        execQuery(query);
        result = mysql_store_result(&mysql);
        row = mysql_fetch_row(result);
        p.idPersonne=atoi(row[0]);
        p.nom=row[1];
        p.prenom=row[2];
        p.isAdmin=atoi(row[3]);
        //p.groupe=getGroupeById()
    }else{
        p.idPersonne=-1;
        p.nom="Undefined";
        p.prenom="Undefined";
        p.isAdmin=0;
    }
    return p;
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
    char query[1024]="";
    strcat(query,"INSERT INTO `personne` (`idPersonne`, `nomPersonne`, `prenomPersonne`, `isAdmin`, `idNFC`, `idGroupe`) VALUES(NULL,'");
    strcat(query,p.nom);
    strcat(query,"','");
    strcat(query,p.prenom);
    strcat(query,"',");
    strcat(query,idAdmin);
    strcat(query,",");
    strcat(query,p.idNFC);
    strcat(query,",");
    strcat(query,idgroupe);
    strcat(query,")");
    execQuery(query);
}



data deserialize(char *obj){
    
   char **champ;
    int i=0;

    char * strToken =strtok(obj,";");
    champ = malloc(sizeof(char*) * 10);
    while ( strToken != NULL ) {
        champ[i]=malloc(sizeof(char)*1024);
        champ[i]=strToken;
        // On demande le token suivant.
        strToken = strtok ( NULL, ";" );
        i++;
    }

    data d;
    d.typeData=atoi(champ[0]);


    switch (d.typeData)
    {
        // get personne by id
    case 1:
            
                d.personne = getPersonne(champ[1]);
        break;
        //get personne
   case 2:
            
                d.personne.idNFC = champ[1];
                d.personne.idPersonne = atoi(champ[2]);
                d.personne.isAdmin = atoi(champ[3]);
                d.personne.nom = champ[4];
                d.personne.prenom = champ[5];
                //d.personne.groupe = getGroupeById(champ[6]);
            
        break;
    
    default:
        break;
    }
    
    return d;

}

char *serialize(data d){
    
    char* champ;
    champ = malloc(sizeof(char)*2048);
    itoa(d.typeData,champ);
    switch (d.typeData)
    {
        // get personne by id
    case 1:
        strcat(champ,";");
        strcat(champ,d.personne.idNFC);
        break;
        //get personne
   case 2:
        strcat(champ,";");
        strcat(champ,d.personne.idNFC);
        strcat(champ,";");
        char * idP;
        itoa(d.personne.idPersonne,idP);
        strcat(champ,idP);
        strcat(champ,";");
        char isAdmin[2];
        itoa(d.personne.isAdmin,isAdmin);
        strcat(champ,isAdmin);
        strcat(champ,";");
        strcat(champ,d.personne.nom);
        strcat(champ,";");
        strcat(champ,d.personne.prenom);
        // strcat(champ,";");
        // char * idG;
        // itoa(d.personne.groupe.idGroupe,idG);
        // strcat(champ,idG);
        break;
    
    default:
        break;
    }

    return champ;
}

presence ajouterPresence(personne p){
    char query[1024]="";
    strcat(query,"INSERT INTO `classe` (`idClasse`, `nomClasse`) VALUES(NULL,'");
    strcat(query,c.nom);
    strcat(query,"')");
    execQuery(query);
}




// int main(){
//     connection();
//    // afficherClasse();
//     classe c;
//     c=getClasse("LA2");
//     groupe g;
//     g=getGroupe(c,"TDB");
//     personne p;
//     p=getPersonne(1,g);
//    /* ajouterClasse(c);
    
//     ajouterGroupe(g);
//     afficherGroupe(c);
//     ajouterPersonne(p);*/
//     printf("%s %s",p.nom,p.prenom);
// }