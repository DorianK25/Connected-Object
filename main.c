#include "libs/libs.h"

int main()
{   

    personne p;
    classe c;
    groupe g;
    char nom[250];
    char prenom[250];
    char classe[250];
    char groupe[250];
    printf("\n\nBonjour vous aller nous servir de test unitaire pour la lecture NFC");

    printf("\n\nQuel est votre nom ?");

    scanf("%s",nom);

    p.nom=nom;

    printf("\n\nQuel est votre prenom ?");

    scanf("%s",prenom);

    p.prenom=prenom;

    printf("\n\nVeuillez saisir votre classe parmis :");

    //afficherClasse();

    scanf("%s",classe);

    //c= getClasse(classe);

    printf("\n\nQuel est votre groupe parmis :");

    //afficherGroupe();

    scanf("%s",groupe);

    //groupe = getGroup(groupe,c)
    g.nom="A";
    g.classe.nom="LA1";

    p.groupe=g;

   // p.isAdmin=0;// pour le test

    //p.idNFC=getNFCId();

    //printf("\n\n Bonjour %s %s bienvenue sur la roll-call-tab\n\n",p.nom,p.prenom);

    printf("\n\n Bonjour %s %s appartenant au groupe %s de la classe %s bienvenue sur la roll-call-tab\n\n",p.nom,p.prenom,p.groupe.nom,p.groupe.classe.nom);


    return 0;
    
}