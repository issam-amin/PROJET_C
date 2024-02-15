#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "GestionEmprunt.h"
#include "GestionLivres.h"

void menuEtudiant(){
    header();
    char **questions = (char**)malloc(8*sizeof(char*));
    for(int i=0;i<8;i++){
        *(questions+i) = (char*)malloc(255*sizeof(char));
    }
    strcpy(*(questions),"Afficher le catalogue des livres disponibles");
    strcpy(*(questions+1),"Rechercher un livre");
    strcpy(*(questions+2),"Effectuer un emprunt");
    strcpy(*(questions+3),"Verifier les emprunts en cours");
    strcpy(*(questions+4),"Mon historique des emprunts");
    strcpy(*(questions+5),"Verfier le nombre des avertissements");
    strcpy(*(questions+6),"Modifier le Numero de telephone");
    strcpy(*(questions+7),"Deconnexion");

    int x=22,y=5,h=19,w=75;
    setxy(x,y);
    for(int i=0;i<=w;i++){
        setColor(9);
        printf("-");
    }
    resetColor();
    setxy(x+27,y+1);
    printf("    Menu Etudiant\n");
    for(int i=1;i<=h;i++){
        setColor(9);
        setxy(x,y+i);
        printf("|");
        setxy(x+w,y+i);
        printf("|");
    }
    setxy(x,y+2);
    for(int i=0;i<=w;i++){
        printf("-");
    }
    resetColor();
    setxy(x+2,y+3);
    printf("(1) %s",*(questions));
    setxy(x+2,y+5);
    printf("(2) %s",*(questions+1));
    setxy(x+2,y+7);
    printf("(3) %s",*(questions+2));
    setxy(x+2,y+9);
    printf("(4) %s",*(questions+3));
    setxy(x+2,y+11);
    printf("(5) %s",*(questions+4));
    setxy(x+2,y+13);
    printf("(6) %s",*(questions+5));
    setxy(x+2,y+15);
    printf("(7) %s",*(questions+6));
    setxy(x+2,y+17);
    printf("(8) %s",*(questions+7));
    setxy(x,y+h);
    for(int i=0;i<=w;i++){
        setColor(9);
        printf("-");
    }
    resetColor();
    setxy(17,y+h+2);
    setColor(10);
    printf(" ");
    char ch ;
    int response;

    do{
        ch= getch();
        response = atoi(&ch);

        switch(response){
            case 1:
                clearConsole();
                setColor(9);
                printf("\n\t\t\t\t\t\tAffichage du catalogue\n\n");
                resetColor();
                affichage("doc.txt");
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                menuEtudiant();
                break;
            case 2:
                etat();
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                menuEtudiant();
                break;
            case 3:
                clearConsole();
                AJOUT_EMPRUNT();
                resetColor();
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                menuEtudiant();
                break;
            case 4:
                clearConsole();
                verfie_emprunt();
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                menuEtudiant();
                break;
            case 5:
                clearConsole();
                Recherche_Historique();
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                menuEtudiant();
                break;
            case 6:
                clearConsole();
                nombre_avertissement();
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                menuEtudiant();
                break;
            case 7:
                clearConsole();
                header();
                resetColor();
                if(modificationNumTelephone()==1){
                printf("Numero de telephone est modifiee avec success!");
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                menuEtudiant();
                }
                else{
                printf("Erreur lors de modification de nuumero de telephone!");
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                menuEtudiant();
                }
                break;
            case 8:
                clearConsole();
                connexion_etudiant();
                break;
        }

    }while(response != 8);

    resetColor();

}

void menuBibliothecaire(){
    header();
    char **questions = (char**)malloc(4*sizeof(char*));
    for(int i=0;i<4;i++){
        *(questions+i) = (char*)malloc(255*sizeof(char));
    }
    strcpy(*(questions),"Gestion des adherants");
    strcpy(*(questions+1),"Gestion des emprunts");
    strcpy(*(questions+2),"Gestion des livres");
    strcpy(*(questions+3),"Deconnexion");
    int x=22,y=5,h=10,w=75;
    setxy(x,y);
    for(int i=0;i<=w;i++){
        setColor(9);
        printf("-");
    }
    resetColor();
    setxy(x+27,y+1);
    printf("  Menu Bibliothecaire\n");
    for(int i=1;i<=h;i++){
        setColor(9);
        setxy(x,y+i);
        printf("|");
        setxy(x+w,y+i);
        printf("|");
    }
    setxy(x,y+2);
    for(int i=0;i<=w;i++){
        printf("-");
    }
    resetColor();
    setxy(x+2,y+3);
    printf("(1) %s",*(questions));
    setxy(x+2,y+5);
    printf("(2) %s",*(questions+1));
    setxy(x+2,y+7);
    printf("(3) %s",*(questions+2));
    setxy(x+2,y+9);
    printf("(4) %s",*(questions+3));
    setxy(x,y+h);
    for(int i=0;i<=w;i++){
        setColor(9);
        printf("-");
    }
    resetColor();
    setxy(17,y+h+2);
    setColor(10);
    printf(" ");
    char ch ;
    int response;
    do{
        ch= getch();
        response = atoi(&ch);


        switch(response){
        case 1:
            clearConsole();
            gestionAdherant();
            break;
        case 2:
            clearConsole();
            gestionEmprunt();
            break;
        case 3:
            clearConsole();
            gestionLivre();
            break;
        case 4:
            clearConsole();
            connexion_employee();
            break;
        default:
            menuBibliothecaire();
            break;
        }

    }while(response !=4);

    resetColor();
}

#endif // MENUS_H_INCLUDED
