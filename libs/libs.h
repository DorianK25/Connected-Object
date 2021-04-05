#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct 
{
    char* nom;
}cours;

typedef struct 
{
    char* nom;
}classe;

typedef struct 
{
    char* nom;
    classe classe;
}groupe;

typedef struct 
{
    char* nom;
    char* prenom;
    int isAdmin;//boolean
    char* idNFC;
    groupe groupe;

}personne;

typedef struct 
{
    personne personne;

}presence;

typedef struct 
{
    cours cours;
    time_t date;
    groupe groupe;
    presence listePresence[];

}seance;

typedef struct 
{
    char* intitule;
}reponse;

typedef struct 
{
    char* intitule;
    reponse reponse[4];
    personne demandeur;
    personne repondeur;
    reponse bonneReponse;

}question;

question getQuestion();
void postQuestion(question);
reponse getReponse();
void postReponse(reponse);
seance getSeance();
void postSeance(seance);
presence getPresence();
void postPresence(presence);
personne getPersonne();
void postPersonne(personne);
groupe getGroupe();
void postGroupe(groupe);
classe getClasse();
void postClasse(classe c);
cours getCours();
void postCours(cours c);

