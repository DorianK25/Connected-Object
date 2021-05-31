#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 8080
#include "../bdd/bdd.h"

typedef struct 
{
    int idCours;
    char* nom;
}cours;

typedef struct 
{
    int idClasse;
    char* nom;
}classe;

typedef struct 
{
    int idGroupe;
    char* nom;
    classe classe;
}groupe;

typedef struct 
{
    int idPersonne;
    char* nom;
    char* prenom;
    int isAdmin;//boolean
    char* idNFC;
    groupe groupe;
}personne;

typedef struct 
{
    int idPresence;
    personne personne;
}presence;

typedef struct 
{
    cours cours;
    time_t date;
    int idSeance;
    char* nom;
    groupe groupe;
    presence listePresence[50];
    int nbPresences;
}seance;

typedef struct 
{
    int idReponse;
    char* intitule;
}reponse;

typedef struct 
{
    int idQuestion;
    char* intitule;
    reponse reponse[4];
    personne demandeur;
    personne repondeur;
    reponse bonneReponse;
}question;

typedef struct
{
    int typeData;
    question question;
    reponse reponse;
    personne personne;
}data;

data deserialize(char *);
char *serialize(data);
void reverse(char s[]);
void itoa(int n, char s[]);
void afficherClasse();
void ajouterClasse(classe);
void afficherGroupe(classe);
void ajouterGroupe(groupe);
void ajouterPersonne(personne);
question getQuestion();
void postQuestion(question);
reponse getReponse();
void postReponse(reponse);
seance getSeance();
void postSeance(seance);
void postPresence(presence);
personne getPersonne(char *);
void postPersonne(personne);
groupe getGroupe(classe,char *);
void postGroupe(groupe);
classe getClasse(char *);
void postClasse(classe);
cours getCours();
void postCours(cours);
presence ajouterPresence(personne,seance);
void getPresence(personne ,seance ,presence *);
void afficherPresence(seance);
data loadData(char **);