#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include "INTERFACE.h"
#include "MENUS.h"
#include "GestionAdherant.h"
#include "GestionEmprunt.h"
#include "Structures.h"



void interactionUtilisateur(){

    int choix;
    char email[30];
    char password[20];
    char code[20];
    char ch;
    int i=0;
    int x = 33,y=6;

    startScreen();

    ch = getch();
    choix = atoi(&ch);

    if (choix == 1) {
        if(ajoutAdherant_versionStartMenu() == 1){
            setxy(x+13,35);
            setColor(14);
            printf("Etudiant ajoutee avec success!!");
            setxy(x-4,36);
            printf("Votre mot de passe pour une prochaine authentification serai votre CNE !");
            setColor(12);
            printf("\n\n\nAppuyer sur n importe qu elle touche pour revenir au menu principal");
            resetColor();
            getch();
            clearConsole();
            interactionUtilisateur();
        }
        else{
            setxy(x+14,34);
            setColor(14);
            printf("Vous etes deja inscrit !");
            setColor(12);
            printf("\n\nAppuyer sur n importe qu elle touche pour revenir au menu principal..");
            resetColor();
            getch();
            clearConsole();
            interactionUtilisateur();
        }

    resetColor();

    } else if (choix == 2) {
            connexion_etudiant();
    }

}

void connexion_employee(){

    FILE *pass_bib = fopen("passwordBib.txt", "r");
    FILE *IdEmployee = fopen("IdEmployee.txt","r");

    int choix;
    char email[30];
    char password[20];
    char code[20];
    char ch;
    int i=0;
    int x = 34,y=6;


    if (IdEmployee == NULL || pass_bib == NULL) {
        perror("Error opening file");
        return;
    }
        clearConsole();
        setColor(9);
        afficherCadre("Bienvenue Dans la Bibliotheque Officielle de l ENSAH");
        setColor(10);
        afficherCadre("Authentification");
        resetColor();
        setxy(x-1,y);
        printf("(*)---------------********************---------------(*)");

        for(int i=1;i<=14;i++){
            setxy(x,y+i);
            printf("|");
            setxy(x+53,y+i);
            printf("|");
        }
        setxy(x-1,y+15);
        printf("(*)--------------------------------------------------(*)");
        setxy(x+1,8);
        printf("*****************    Connexion     *****************");
        setxy(x+17,7);
        printf("*");
        setxy(x+36,7);
        printf("*");
        setxy(x+17,9);
        printf("*");
        setxy(x+36,9);
        printf("*");
        setxy(x+17,10);
        printf("********************");
    /*Content*/
        setxy(x+24,12);
        printf("Email");
        setxy(x+7,13);
        printf("----------------------------------------");
        setxy(x+7,14);
        printf("|                                      |");
        setxy(x+7,15);
        printf("----------------------------------------");

        setxy(x+23,16);
        printf("Password");
        setxy(x+7,17);
        printf("----------------------------------------");
        setxy(x+7,18);
        printf("|                                      |");
        setxy(x+7,19);
        printf("----------------------------------------");

        setxy(x+9,14);
        scanf("%s", email);

        char lastname[50];
        char firstname[50];

        // Find the position of '.' and '@' in the email
        char *dotPosition = strchr(email, '.');
        char *atPosition = strchr(email, '@');

        // Check if both '.' and '@' are present in the email
        if (dotPosition != NULL && atPosition != NULL && dotPosition < atPosition) {
        // Extract lastname
            strncpy(lastname, email, dotPosition - email);
            lastname[dotPosition - email] = '\0';

        // Extract firstname
            strncpy(firstname, dotPosition + 1, atPosition - dotPosition - 1);
            firstname[atPosition - dotPosition - 1] = '\0';
        }


        setxy(x+9,18);
        while (1){
            ch = getch();
            if (ch == 13)
                break;
            else if (ch == 8 && i > 0)
            {
                printf("\b \b");
                i--;
            }
            else{
                password[i++] = ch;
                printf("*");
        }

    }   password[i] = '\0';

        int emailValid = 0;
        int passwordFound = 0;
        char verif[100];
        while(fgets(verif,sizeof(verif),IdEmployee)!=NULL){
            if((strstr(verif,lastname)!= NULL)&&(strstr(verif,firstname)!= NULL)&&(strstr(email, "uae.ac.ma") != NULL)){
                emailValid =1;
            }
        }



        while (fgets(code, sizeof(code), pass_bib) != NULL) {
            code[strcspn(code, "\n")] = '\0';
                if (strcmp(password, code) == 0) {
                    passwordFound = 1;
                }
        }


        fclose(IdEmployee);
        fclose(pass_bib);


        if (!emailValid || !passwordFound) {
            setxy(x+13,23);
            setColor(12);
            printf("Email ou Password invalide");
            resetColor();
            sleep(2);
            clearScreen();
            connexion_employee();
        }
        else{
            clearConsole();
            menuBibliothecaire();
        }
}


void connexion_etudiant(){

    FILE *pass_adh = fopen("passwordAdherant.txt", "r");
    FILE *data = fopen("data.txt","r");

    int choix;
    char email[30];
    char password[20];
    char code[20];
    char ch;
    int i=0;
    int x = 34,y=6;


    if (data == NULL || pass_adh == NULL) {
        perror("Error opening file");
        return;
    }
        clearConsole();
        setColor(9);
        afficherCadre("Bienvenue Dans la Bibliotheque Officielle de l ENSAH");
        setColor(10);
        afficherCadre("Authentification");
        resetColor();
        setxy(x-1,y);
        printf("(*)---------------********************---------------(*)");

        for(int i=1;i<=14;i++){
            setxy(x,y+i);
            printf("|");
            setxy(x+53,y+i);
            printf("|");
        }
        setxy(x-1,y+15);
        printf("(*)--------------------------------------------------(*)");
        setxy(x+1,8);
        printf("*****************    Connexion     *****************");
        setxy(x+17,7);
        printf("*");
        setxy(x+36,7);
        printf("*");
        setxy(x+17,9);
        printf("*");
        setxy(x+36,9);
        printf("*");
        setxy(x+17,10);
        printf("********************");
    /*Content*/
        setxy(x+24,12);
        printf("Email");
        setxy(x+7,13);
        printf("----------------------------------------");
        setxy(x+7,14);
        printf("|                                      |");
        setxy(x+7,15);
        printf("----------------------------------------");

        setxy(x+23,16);
        printf("Password");
        setxy(x+7,17);
        printf("----------------------------------------");
        setxy(x+7,18);
        printf("|                                      |");
        setxy(x+7,19);
        printf("----------------------------------------");

        setxy(x+9,14);
        scanf("%s", email);

        char lastname[50];
        char firstname[50];

        // Find the position of '.' and '@' in the email
        char *dotPosition = strchr(email, '.');
        char *atPosition = strchr(email, '@');

        // Check if both '.' and '@' are present in the email
        if (dotPosition != NULL && atPosition != NULL && dotPosition < atPosition) {
        // Extract lastname
            strncpy(lastname, email, dotPosition - email);
            lastname[dotPosition - email] = '\0';

        // Extract firstname
            strncpy(firstname, dotPosition + 1, atPosition - dotPosition - 1);
            firstname[atPosition - dotPosition - 1] = '\0';
        }


        setxy(x+9,18);
        while (1){
            ch = getch();
            if (ch == 13)
                break;
            else if (ch == 8 && i > 0)
            {
                printf("\b \b");
                i--;
            }
            else{
                password[i++] = ch;
                printf("*");
        }

    }   password[i] = '\0';

        int emailValid = 0;
        int passwordFound = 0;
        char verif[100];
        while(fgets(verif,sizeof(verif),data)!=NULL){
            if((strstr(verif,lastname)!= NULL)&&(strstr(verif,firstname)!= NULL)&&(strstr(email, "uae.ac.ma") != NULL)){
                emailValid =1;
            }
        }


        while (fgets(code, sizeof(code), pass_adh) != NULL) {
            code[strcspn(code, "\n")] = '\0';
                if (strcmp(password, code) == 0) {
                    passwordFound = 1;
                }
        }


        fclose(data);
        fclose(pass_adh);


        if (!emailValid || !passwordFound) {
            setxy(x+13,23);
            setColor(12);
            printf("Email ou Password invalide");
            resetColor();
            sleep(2);
            clearScreen();
            connexion_etudiant();
        }
        else{
            clearConsole();
            menuEtudiant();
        }
}


void base(){

    setColor(9);
    afficherCadre("Bienvenue Dans la Bibliotheque Officielle de l ENSAH");
    resetColor();
    int x=33,y=8,h=12,w=52;
    setxy(x,y);
    for(int i=0;i<=w;i++){
        printf("-");
    }
    for(int i=1;i<=h;i++){
        setxy(x,y+i);
        printf("|");
        setxy(x+w,y+i);
        printf("|");
    }
    setxy(x+25,y+1);
    printf("(1)");
    setxy(x+18,y+3);
    printf("Je suis un adherant");
    setxy(x+25,y+7);
    printf("(2)");
    setxy(x+18,y+9);
    printf("Je suis un employee");
    setxy(x,y+6);
    for(int i=0;i<=w;i++){
        printf("-");
    }
    setxy(x,y+h);
    for(int i=0;i<=w;i++){
        printf("-");
    }
    printf("\n");
    setxy(x+25,y+14);
    char ch= getch();
    clearConsole();
    switch(ch){
    case '1':
        interactionUtilisateur();
        break;
    case '2':
        connexion_employee();
        break;
    default:
        base();
        break;
    }
}


int main(){
    base();


    return 0;
}
