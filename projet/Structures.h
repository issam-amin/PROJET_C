#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct date{
    int jour;
    int mois;
    int annee;
}date;

typedef struct adherant{

    char CNE[12];
    char nom[20];
    char prenom[20];
    char ville[15];
    char num_telephone[20];
    date date_inscription;

} adherant;

typedef struct emprunt{

    char *ISBN;
    char *TitreL;
    date date_emprunt;
    date date_retour;
    char *CNE;
}emprunt;

typedef struct  {
    int nbr_edition;
    char ISBN[20];
    char maison_edition[20];
    char titre[50];
    char auteur[30];
}livre;

#endif // STRUCTURES_H_INCLUDED
