#ifndef GESTIONADHERANT_H_INCLUDED
#define GESTIONADHERANT_H_INCLUDED
#include "Structures.h"

void gestionAdherant(){
    header();
    char **questions = (char**)malloc(5*sizeof(char*));
    for(int i=0;i<6;i++){
        *(questions+i) = (char*)malloc(255*sizeof(char));
    }
    strcpy(*(questions),"Ajouter un adherant");
    strcpy(*(questions+1),"Rechercher un adherant");
    strcpy(*(questions+2),"Modification de numero de telephone");
    strcpy(*(questions+3),"Supprimer un adherant");
    strcpy(*(questions+4),"Revient au menu principal");
    int x=22,y=5,h=12,w=75;
    setxy(x,y);
    for(int i=0;i<=w;i++){
        setColor(9);
        printf("-");
    }
    resetColor();
    setxy(x+27,y+1);
    printf(" Gestion des adherants\n");
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
    setxy(x,y+h);
    for(int i=0;i<=w;i++){
        setColor(9);
        printf("-");
    }
    resetColor();
    setxy(17,y+h+2);
    printf(" ");
    char ch ;
    int response;
    do{
        ch= getch();
        response = ch - '0';
        switch(response){
        case 1:
            clearConsole();
            header();

        if(ajoutAdherant_versionInsideMenu() == 1){
            setxy(x+21,34);
            setColor(14);
            printf("Etudiant ajoutee avec success!");
            setxy(x+1,36);
            setColor(12);
            printf("Appuyer sur n importe qu elle touche pour revenir au menu principal.....");
            resetColor();
            getch();
            clearConsole();
            gestionAdherant();
        }
        else{
            setxy(x+24,34);
            setColor(14);
            printf("Etudiant deja inscrit !");
            setColor(12);
            printf("\n\nAppuyer sur n importe qu elle touche pour revenir au menu principal..");
            resetColor();
            getch();
            clearConsole();
            gestionAdherant();
        }
            break;
        case 2:
            clearConsole();
            header();
            rechercheAdherant();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionAdherant();
            break;
        case 3:
            clearConsole();
            header();
            if(modificationNumTelephone()==1){
                setxy(x+15,23);
                setColor(12);
                printf("Numero de telephone est modifiee avec success!");
                resetColor();
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                gestionAdherant();
            }
            else{
                setxy(x+10,23);
                setColor(12);
                printf("Erreur lors de modification de numero de telephone!");
                resetColor();
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                gestionAdherant();
            }
            break;
        case 4:
            clearConsole();
            header();
            if(suppressionAdherant()==1){
                setColor(9);
                setxy(x+23,19);
                printf("Adherant supprimer avec success!");
                resetColor();
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                gestionAdherant();
            }
            else{
                setColor(9);
                setxy(x+24,19);
                printf("Erreur lors de la suppression!");
                resetColor();
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                gestionAdherant();
            }
            break;
        case 5:
            clearConsole();
            menuBibliothecaire();
            break;
        default:
            printf("choix invalide");
            printf("\n\nAppuyer sur n importe qu'elle touche pour revenir...");
            getch();
            clearConsole();
            menuBibliothecaire();
            break;
        }

    }while(response != 5);

    resetColor();
}

int ajoutAdherant_versionStartMenu(){

    //declaration des variables importants

    FILE *data = fopen("data.txt","r");
    FILE *pass_adh = fopen("passwordAdherant.txt", "a");

    adherant test;
    time_t now;
    char verification [200];


    if(data == NULL){
        printf("erreur lors de l ouverture de fichier");
        exit(0);
    }

    //verifier si la personne est déja inscrite
    resetColor();
    clearConsole();
    setColor(9);
    afficherCadre("Bienvenue Dans la Bibliotheque Officielle de l ENSAH");
    setColor(10);
    afficherCadre("Authentification");
    resetColor();
    int x = 34,y=6;
    setxy(x-1,y);
        printf("(*)---------------********************---------------(*)");

        for(int i=1;i<=26;i++){
            setxy(x,y+i);
            printf("|");
            setxy(x+53,y+i);
            printf("|");
        }
    setxy(x-1,y+27);
    printf("(*)--------------------------------------------------(*)");
    setxy(x+17,8);
    printf("*    inscription   *");
    setxy(x+17,9);
    printf("*");
    setxy(x+36,9);
    printf("*");
    setxy(x+17,7);
    printf("*");
    setxy(x+36,7);
    printf("*");

    setxy(x+17,10);
    printf("********************");
    /*Content*/
    setxy(x+24,12);
    printf(" CNE");
    setxy(x+7,13);
    printf("----------------------------------------");
    setxy(x+7,14);
    printf("|                                      |");
    setxy(x+7,15);
    printf("----------------------------------------");
    setxy(x+23,16);
    printf("  Nom");
    setxy(x+7,17);
    printf("----------------------------------------");
    setxy(x+7,18);
    printf("|                                      |");
    setxy(x+7,19);
    printf("----------------------------------------");
    setxy(x+24,20);
    printf("Prenom");
    setxy(x+7,21);
    printf("----------------------------------------");
    setxy(x+7,22);
    printf("|                                      |");
    setxy(x+7,23);
    printf("----------------------------------------");
    setxy(x+24,24);
    printf("Ville");
    setxy(x+7,25);
    printf("----------------------------------------");
    setxy(x+7,26);
    printf("|                                      |");
    setxy(x+7,27);
    printf("----------------------------------------");
    setxy(x+22,28);
    printf("Telephone");
    setxy(x+7,29);
    printf("----------------------------------------");
    setxy(x+7,30);
    printf("|                                      |");
    setxy(x+7,31);
    printf("----------------------------------------");

    //input
    setxy(x+9,14);
    scanf("%s", test.CNE);

    while(fgets(verification,200,data) != NULL){
        if(strstr(verification,test.CNE) != NULL){
            fclose(data);
            return 0;
        }

        }
    fclose(data);
    data = fopen("data.txt","a");

    if(data == NULL){
        printf("erreur lors de l ouverture de fichier");
        exit(0);
    }
    setxy(x+9,18);
    scanf("%s",test.nom);
    setxy(x+9,22);
    scanf("%s",test.prenom);
    setxy(x+9,26);
    scanf("%s",test.ville);
    setxy(x+9,30);
    fflush(stdin);
    gets(test.num_telephone);


    time(&now);

    struct tm *daba = localtime(&now);
    test.date_inscription.jour = daba->tm_mday;
    test.date_inscription.mois = daba->tm_mon + 1;
    test.date_inscription.annee = daba->tm_year + 1900;

    fprintf(data,"\n%s\t%s\t\t%s\t\t\t%s\t  %s\t \t  %d/%d/%d",test.CNE,test.nom,test.prenom,test.ville,test.num_telephone,test.date_inscription.jour,test.date_inscription.mois,test.date_inscription.annee);
    fprintf(pass_adh,"\n%s",test.CNE);
    fclose(pass_adh);
    fclose(data);

    return 1;
}

int ajoutAdherant_versionInsideMenu(){

    //declaration des variables importants

    FILE *data = fopen("data.txt","r");
    FILE *pass_adh = fopen("passwordAdherant.txt", "a");

    adherant test;
    time_t now;
    char verification [200];

    resetColor();
    if(data == NULL){
        printf("erreur lors de l ouverture de fichier");
        exit(0);
    }

    //verifier si la personne est déja inscrite
   int x = 32,y=6;
    setxy(x-1,y);
        printf("(*)---------------********************---------------(*)");

        for(int i=1;i<=26;i++){
            setxy(x,y+i);
            printf("|");
            setxy(x+53,y+i);
            printf("|");
        }
    setxy(x-1,y+27);
    printf("(*)--------------------------------------------------(*)");
    setxy(x+17,8);
    printf("* Ajout d'Adherant *");
    setxy(x+17,9);
    printf("*");
    setxy(x+36,9);
    printf("*");
    setxy(x+17,7);
    printf("*");
    setxy(x+36,7);
    printf("*");

    setxy(x+17,10);
    printf("********************");
    /*Content*/
    setxy(x+24,12);
    printf(" CNE");
    setxy(x+7,13);
    printf("----------------------------------------");
    setxy(x+7,14);
    printf("|                                      |");
    setxy(x+7,15);
    printf("----------------------------------------");
    setxy(x+23,16);
    printf("  Nom");
    setxy(x+7,17);
    printf("----------------------------------------");
    setxy(x+7,18);
    printf("|                                      |");
    setxy(x+7,19);
    printf("----------------------------------------");
    setxy(x+24,20);
    printf("Prenom");
    setxy(x+7,21);
    printf("----------------------------------------");
    setxy(x+7,22);
    printf("|                                      |");
    setxy(x+7,23);
    printf("----------------------------------------");
    setxy(x+24,24);
    printf("Ville");
    setxy(x+7,25);
    printf("----------------------------------------");
    setxy(x+7,26);
    printf("|                                      |");
    setxy(x+7,27);
    printf("----------------------------------------");
    setxy(x+22,28);
    printf("Telephone");
    setxy(x+7,29);
    printf("----------------------------------------");
    setxy(x+7,30);
    printf("|                                      |");
    setxy(x+7,31);
    printf("----------------------------------------");

    //input
    setxy(x+9,14);
    scanf("%s", test.CNE);
    setxy(x+9,18);
    scanf("%s",test.nom);
    setxy(x+9,22);
    scanf("%s",test.prenom);
    setxy(x+9,26);
    scanf("%s",test.ville);
    setxy(x+9,30);
    fflush(stdin);
    gets(test.num_telephone);


    while(fgets(verification,200,data) != NULL){
        if(strstr(verification,test.CNE) != NULL){
            fclose(data);
            return 0;
        }
    }

    time(&now);
    FILE *da = fopen("data.txt","a");
    struct tm *daba = localtime(&now);
    test.date_inscription.jour = daba->tm_mday;
    test.date_inscription.mois = daba->tm_mon + 1;
    test.date_inscription.annee = daba->tm_year + 1900;

    fprintf(da,"\n%s\t%s\t\t%s\t\t\t%s\t      %s\t \t     %d/%d/%d",test.CNE,test.nom,test.prenom,test.ville,test.num_telephone,test.date_inscription.jour,test.date_inscription.mois,test.date_inscription.annee);
    fprintf(pass_adh,"\n%s",test.CNE);
    fclose(pass_adh);
    fclose(da);
    return 1;
}

void rechercheAdherant(){

    FILE *data = fopen("data.txt","r");
    char test[12];
    char get[200];
    char date[15];
    adherant m;

    if(data == NULL){
        printf("erreur lors de l ouverture de fichier");
        exit(0);
    }
    int x = 34,y=6;
    setxy(x-1,y);
    printf("(*)---------------********************---------------(*)");

    for(int i=1;i<=11;i++){
        setxy(x,y+i);
        printf("|");
        setxy(x+53,y+i);
        printf("|");
    }
    setxy(x-1,y+11);
    printf("(*)--------------------------------------------------(*)");
    setxy(x+1,8);
    printf("*****************    Recherche     *****************");
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
    printf("CNE");
    setxy(x+7,13);
    printf("----------------------------------------");
    setxy(x+7,14);
    printf("|                                      |");
    setxy(x+7,15);
    printf("----------------------------------------");
    setxy(x+9,14);
    scanf("%s",test);
    int c =0;
    while(fgets(get,200,data) != NULL){
        if(strstr(get,test)!=NULL){
            sscanf(get, "%s %s %s %s %s %d/%d/%d", m.CNE, m.nom, m.prenom, m.ville, m.num_telephone, &m.date_inscription.jour, &m.date_inscription.mois, &m.date_inscription.annee);
            setxy(x+13,19);
            setColor(9);
            printf("Resultat de votre recherche");
            setxy(x,20);
            setColor(10);
            printf("+------------+------------+------------+---------------+\n");
            setxy(x,21);
            printf("|   NOM      |  PRENOM    |   VILLE    |  TELEPHONE    |\n");
            setxy(x,22);
            printf("+------------+------------+------------+---------------+\n");
            setxy(x,23);

    // Data
            resetColor();
            printf("|   %s     |   %s  | %s  |%s  |\n", m.nom, m.prenom, m.ville, m.num_telephone);

    // Footer
            setxy(x,24);
            setColor(10);
            printf("+------------+------------+------------+---------------+\n");
            resetColor();
            c=1;
        }
    }
    if(c==0){
        setxy(x+17,18);
    setColor(12);
        printf("Rien n est trouver");
        resetColor();
    }
    fclose(data);

}

int suppressionAdherant(){

    FILE *data = fopen("data.txt","r");
    FILE *NewData = fopen("newdata.txt","w");

    char test[12];
    char get[200];
    int c = 0;


    if((data == NULL) || (NewData == NULL)){
        printf("erreur lors de l ouverture de fichier");
        exit(0);
    }

    int x = 34,y=6;
    setxy(x-1,y);
    printf("(*)---------------********************---------------(*)");

    for(int i=1;i<=11;i++){
        setxy(x,y+i);
        printf("|");
        setxy(x+53,y+i);
        printf("|");
    }
    setxy(x-1,y+11);
    printf("(*)--------------------------------------------------(*)");
    setxy(x+1,8);
    printf("*****************  Suppression     *****************");
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
    printf("CNE");
    setxy(x+7,13);
    printf("----------------------------------------");
    setxy(x+7,14);
    printf("|                                      |");
    setxy(x+7,15);
    printf("----------------------------------------");
    setxy(x+9,14);
    scanf("%s",test);

    while(fgets(get,200,data) != NULL){
        if(strstr(get,test)!=NULL){
            c=1;
            continue;
        }
        else
            fputs(get,NewData);
}
    fclose(data);
    fclose(NewData);


    remove("data.txt");
    rename("newdata.txt","data.txt");
    if(c==0){
        return 0;
    }
    else
        return 1;
}

int modificationNumTelephone() {
    FILE *data = fopen("data.txt", "r");
    FILE *NewData = fopen("newdata.txt", "w");

    char test[12];
    char nouveauNum[20];
    adherant m;
    char line[256];
    int x = 34,y=6;

    if ((data == NULL) || (NewData == NULL)) {
        printf("erreur lors de l ouverture de fichier");
        exit(0);
    }
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
        printf("*****************    Modifier      *****************");
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
        printf("CNE");
        setxy(x+7,13);
        printf("----------------------------------------");
        setxy(x+7,14);
        printf("|                                      |");
        setxy(x+7,15);
        printf("----------------------------------------");

        setxy(x+21,16);
        printf("Nouveau Num");
        setxy(x+7,17);
        printf("----------------------------------------");
        setxy(x+7,18);
        printf("|                                      |");
        setxy(x+7,19);
        printf("----------------------------------------");

        setxy(x+9,14);
        scanf("%s", test);

        setxy(x+9,18);

    scanf("%s", nouveauNum);

    int c = 0;
    while (fgets(line, sizeof(line), data) != NULL) {
        sscanf(line, "%s %s %s %s %s %d/%d/%d", m.CNE, m.nom, m.prenom, m.ville, m.num_telephone, &m.date_inscription.jour, &m.date_inscription.mois, &m.date_inscription.annee);
        if(strstr(line,test)!=NULL){
            fprintf(NewData, "%s\t%s\t\t%s\t\t\t%s\t\t  %s\t\t  %d/0%d/%d\n", m.CNE, m.nom, m.prenom, m.ville, nouveauNum, m.date_inscription.jour, m.date_inscription.mois, m.date_inscription.annee);
            c = 1;
        }
        else{
            fprintf(NewData,"%s", line);
        }

    }

    fclose(data);
    fclose(NewData);
    remove("data.txt");
    rename("newdata.txt","data.txt");

    if(c==1)
        return 1;
    else
        return 0;
}


#endif // GESTIONADHERANT_H_INCLUDED
