#ifndef GESTIONEMPRUNT_H_INCLUDED
#define GESTIONEMPRUNT_H_INCLUDED
#include "Structures.h"
#include "INTERFACE.h"


void gotoxy(int x, int y) {

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void gestionEmprunt(){
    header();

    char **questions = (char**)malloc(11*sizeof(char*));
    for(int i=0;i<11;i++){
        *(questions+i) = (char*)malloc(255*sizeof(char));
    }
    strcpy(*(questions),"Ajouter un emprunt");
    strcpy(*(questions+1),"Verifier les emprunts d un etudiant");
    strcpy(*(questions+2),"Verifier l etat d un livre");
    strcpy(*(questions+3),"Supprimer un emprunt");
    strcpy(*(questions+4),"Affichage de tous les emprunts en cours");
    strcpy(*(questions+5),"Affichage d historique de tous les emprunts");
    strcpy(*(questions+6),"Rechercher un emprunt dans l historique");
    strcpy(*(questions+7),"Nombre d avertissement d un adherant");
    strcpy(*(questions+8),"Verifier les emprunts ayant une date expirer");
    strcpy(*(questions+9),"Revient au menu principal");

    int x=22,y=5,h=22,w=75;
    setxy(x,y);
    for(int i=0;i<=w;i++){
        setColor(9);
        printf("-");
    }
    resetColor();
    setxy(x+27,y+1);
    printf(" Gestion des Emprunts\n");
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
    setxy(x+2,y+19);
    printf("(9) %s",*(questions+8));
    setxy(x+2,y+21);
    printf("(0) %s",*(questions+9));
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
            AJOUT_EMPRUNT();
            resetColor();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionEmprunt();
            break;
        case 2:
            clearConsole();
            verfie_emprunt();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionEmprunt();
            break;
        case 3:
            clearConsole();
            Recherche_emprunt();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionEmprunt();
            break;
        case 4:
            clearConsole();
            supprimer_emprunt();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionEmprunt();
            break;
        case 5:
            clearConsole();
            affichage_en_cour();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionEmprunt();
            break;
        case 6:
            clearConsole();
            affichage_de_historique();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionEmprunt();
            break;
        case 7:
            clearConsole();
            Recherche_Historique();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionEmprunt();
            break;
        case 8:
            clearConsole();
            nombre_avertissement();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionEmprunt();
            break;
        case 9:
            clearConsole();
            LIVRE_DATESR_EXPIRE();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionEmprunt();
            break;
        case 0:
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

    }while(response != 0);

    resetColor();
}


date traitementdate_retour(int j,int m,int a){
    date dateretour_traite;
    //traitement des cas de mois fevrier  et mois decembre
    //mois fevrier
    if(m==2 && j+14>28)
    {
         m++;
        int temps;
        temps=28 - j;
        j= 14 -temps;
        dateretour_traite.jour=j;
        dateretour_traite.mois=m;
        dateretour_traite.annee=a;
        return dateretour_traite;

    }
    else if (m==12 && j+14>30)
    {
        a++;
        int temps;
        temps=31 - j;
        j= 14 -temps;
        dateretour_traite.jour=j;
        dateretour_traite.mois=1;
        dateretour_traite.annee=a;
        return dateretour_traite;
    }
    switch (m)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            if( j+14> 30)
            {
                m++;
                int temps;
                temps=30 - j;
                j= 14 -temps;
                dateretour_traite.jour=j;
                dateretour_traite.mois=m;
                dateretour_traite.annee=a;
                return dateretour_traite;
            }
            else
            {
                dateretour_traite.jour=j+14;
                dateretour_traite.mois=m;
                dateretour_traite.annee=a;
                return dateretour_traite;
            }
        default:
        if( j+14> 31)
            {
                m++;
                int temps;
                temps=31 - j;
                j= 14 -temps;
                dateretour_traite.jour=j;
                dateretour_traite.mois=m;
                dateretour_traite.annee=a;
                return dateretour_traite;
            }
            else
            {
                dateretour_traite.jour=j+14;
                dateretour_traite.mois=m;
                dateretour_traite.annee=a;
                return dateretour_traite;
            }
    }
}


int etat_livre(char *ISBN){
      char *ISBNT;
      ISBNT=malloc(15*sizeof(char));
      FILE *PLIVRES;
      PLIVRES=fopen("LIVRES.txt","r");
      int c =0;
      while(!feof(PLIVRES))
      {
          fscanf(PLIVRES,"%s\n",ISBNT);
          if(strcmp(ISBN,ISBNT)==0){
            c=1;
            break;
          }
      }
      if(c==1)
        return 1;

      else if(c==0)
        return 0;
}


void AJOUT_EMPRUNT(){











    emprunt *ajouter;
    //allocation d'espace pour le variable de type emprunt
    ajouter=malloc(sizeof(emprunt));
    ajouter->TitreL=malloc(30*sizeof(char));
    ajouter->CNE=malloc(14*sizeof(char));
    ajouter->ISBN=malloc(14*sizeof(char));
    //collection des infos
    setColor(12);
    printf("\n          ********************************** VERIFICATION DES EMPRUNTS ***********************************\n\n\n");
    setColor(14);
    printf("\n\tVeuillez entrer l'ISBN du livre: ");
    resetColor();
    scanf("%s",ajouter->ISBN);
    int v= Recherche_empruntV2(ajouter->ISBN);
    int vl=etat_livre(ajouter->ISBN);
    if(v==1 && vl==1){
    setColor(10);
    printf("\nVeuillez entrer le Titre du livre: ");
    resetColor();
    scanf("%s",ajouter->TitreL);
    setColor(10);
    printf("\nVeuillez entrer le CNE d'etudiant: ");
    resetColor();
    scanf("%s",ajouter->CNE);

    //ajoutant la date d'emprunt
    time_t now=time(NULL);
    struct tm *todaystime = localtime(&now);
    int J,M,A;
   J= ajouter->date_emprunt.jour=todaystime->tm_mday;
   M=ajouter->date_emprunt.mois=todaystime->tm_mon+1;
   A=ajouter->date_emprunt.annee=todaystime->tm_year+1900;

   //ajoutant la date retour apres le traitement des cas
   ajouter->date_retour=traitementdate_retour(J,M,A);

   //On rempli le fichier maintenant
   //declation du pointeur et l'ouverture de fichier
   FILE*Pajout;
   FILE*Phistorique;
    Pajout=fopen("registre_emprunt.txt","a");
    Phistorique=fopen("historique_emprunt.txt","a");
    //remplicage du fichier de registre emprunt et aussi l historique
    fprintf(Pajout,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",ajouter->ISBN,ajouter->TitreL,ajouter->CNE,ajouter->date_emprunt.jour,ajouter->date_emprunt.mois,ajouter->date_emprunt.annee,ajouter->date_retour.jour,ajouter->date_retour.mois,ajouter->date_retour.annee);
    fprintf(Phistorique,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",ajouter->ISBN,ajouter->TitreL,ajouter->CNE,ajouter->date_emprunt.jour,ajouter->date_emprunt.mois,ajouter->date_emprunt.annee,ajouter->date_retour.jour,ajouter->date_retour.mois,ajouter->date_retour.annee);

    setColor(12);
    printf("Emprunt ajouter avec succes!");
    resetColor();
    printf("\nN'oubliez pas que la date de retour est : %d/%d/%d",ajouter->date_retour.jour,ajouter->date_retour.mois,ajouter->date_retour.annee);
    fclose(Pajout);
    fclose(Phistorique);
    free(ajouter);
    free(ajouter->TitreL);
    free(ajouter->CNE);
   }
   else if (vl==0){
    setColor(12);
    printf("       \n\nCE LIVRE N'EXISTE PAS DANS LA BIBLIOTHEQUE ENSAH");
    resetColor();
   }
   else if(v==0 && vl==1)
   {
        emprunt *Recherche;
    Recherche=malloc(sizeof(emprunt));
    Recherche->TitreL=malloc(35*sizeof(char));
    Recherche->CNE=malloc(14*sizeof(char));
    Recherche->ISBN=malloc(14*sizeof(char));
       FILE *Precherche;
    Precherche=fopen("registre_emprunt.txt","r");

        while(!feof(Precherche)){
        //le scan des infos de fichier
        fscanf(Precherche,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",Recherche->ISBN,Recherche->TitreL,Recherche->CNE,&Recherche->date_emprunt.jour,&Recherche->date_emprunt.mois,&Recherche->date_emprunt.annee,&Recherche->date_retour.jour,&Recherche->date_retour.mois,&Recherche->date_retour.annee);
        if(strcmp(Recherche->ISBN,ajouter->ISBN)==0)
          break;

        }



       printf("\nLE LIVRE: %s EST ENCORE EMPRUNTE \n DATE DE RETOUR DE LIVRE : %d/%d/%d\n",Recherche->TitreL,Recherche->date_retour.jour,Recherche->date_retour.mois,Recherche->date_retour.annee);
            free(Recherche);
            free(Recherche->TitreL);
            free(Recherche->CNE);
            fclose(Precherche);

   }

}
void affichage_en_cour(){
    //declaration du pointeur sur le fichier et ouverture du fichier
int i=4;
emprunt *afficher;
afficher=malloc(sizeof(emprunt));
afficher->TitreL=malloc(35*sizeof(char));
afficher->CNE=malloc(25*sizeof(char));
afficher->ISBN=malloc(25*sizeof(char));
FILE *Paffiche;
Paffiche=fopen("registre_emprunt.txt","r");
setColor(12);
printf("                ****************************** LES EMPRUNTS EN COURS  ******************************\n");
resetColor();
printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
setColor(14);
printf("³ISBN"); gotoxy(13,2);printf("³TITRE DE LIVRE");gotoxy(48,2);printf("³CNE");gotoxy(62,2);printf("³DATE D'EMPRUNT");gotoxy(80,2);printf("³DATE DE RETOUR³");
resetColor();
while(!feof(Paffiche)){
printf("\nÃÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
        //le scan des infos de fichier
    fscanf(Paffiche,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",afficher->ISBN,afficher->TitreL,afficher->CNE,&afficher->date_emprunt.jour,&afficher->date_emprunt.mois,&afficher->date_emprunt.annee,&afficher->date_retour.jour,&afficher->date_retour.mois,&afficher->date_retour.annee);
        //affichage
    //printf("\nle %d'eme livre =>\n",i);
   // printf("ISBN: %d , TITRE DE LIVRE : %s , CNE D'ETUDIANT : %s , DATE D'EMPRUNT: %d/%d/%d ,DATE DE RETOUR DE LIVTRE : %d/%d/%d\n",afficher->ISBN,afficher->TitreL,afficher->CNE,afficher->date_emprunt.jour,afficher->date_emprunt.mois,afficher->date_emprunt.anne,afficher->date_retour.jour,afficher->date_retour.mois,afficher->date_retour.anne);
    gotoxy(0,i);printf("³%s",afficher->ISBN); gotoxy(13,i);printf("³%s",afficher->TitreL);gotoxy(48,i);printf("³%s",afficher->CNE);gotoxy(62,i);printf("³%d/%d/%d",afficher->date_emprunt.jour,afficher->date_emprunt.mois,afficher->date_emprunt.annee);gotoxy(80,i);printf("³%d/%d/%d    ³",afficher->date_retour.jour,afficher->date_retour.mois,afficher->date_retour.annee);

    i+=2;
}
printf("\nÀÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
fclose(Paffiche);
free(afficher);
free(afficher->TitreL);
free(afficher->CNE);
free(afficher->ISBN);
}


int Recherche_emprunt(){


    setColor(12);
    printf("\n\t************************************* RECHERCHE DES EMPRUNTES *************************************\n\n\n");
    resetColor();
    //les variable ou on vas stocker
    char ISBNR[20];
    int c=0;
    emprunt *Recherche;
    Recherche=malloc(sizeof(emprunt));
    Recherche->TitreL=malloc(35*sizeof(char));
    Recherche->CNE=malloc(14*sizeof(char));
    Recherche->ISBN=malloc(14*sizeof(char));

    //ouverture de fichier
    FILE *Precherche;
    Precherche=fopen("registre_emprunt.txt","r");

    //stockage des données
    setColor(14);
    printf("Entrer l'ISBN de livre que vous cherchez: ");
    resetColor();
    scanf("%s",ISBNR);
     //exraction de fichier et comparaison
    while(!feof(Precherche)){
        //le scan des infos de fichier
        fscanf(Precherche,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",Recherche->ISBN,Recherche->TitreL,Recherche->CNE,&Recherche->date_emprunt.jour,&Recherche->date_emprunt.mois,&Recherche->date_emprunt.annee,&Recherche->date_retour.jour,&Recherche->date_retour.mois,&Recherche->date_retour.annee);
        if(strcmp(Recherche->ISBN,ISBNR)==0)
        {
            c=1;
            printf("\n\nLe livre : %s est encore emprunte\nSa date de retour prevue : %d/%d/%d\n",Recherche->TitreL,Recherche->date_retour.jour,Recherche->date_retour.mois,Recherche->date_retour.annee);
            fclose(Precherche);
            free(Recherche);
        return 0;
        }
    }
    if(c==0)
        {
            setColor(12);
            printf("\n\nCe livre n'existe pas dans le registre des emprunts\n");
            resetColor();
            fclose(Precherche);
            free(Recherche);
            return 1;
        }


}

int Recherche_empruntV2(char *ISBNR){

    //les variable ou on vas stocker
    int c=0;
    emprunt *Recherche;
    Recherche=malloc(sizeof(emprunt));
    Recherche->TitreL=malloc(35*sizeof(char));
    Recherche->CNE=malloc(14*sizeof(char));
    Recherche->ISBN=malloc(14*sizeof(char));

    //ouverture de fichier
    FILE *Precherche;
    Precherche=fopen("registre_emprunt.txt","r");

     //exraction de fichier et comparaison
    while(!feof(Precherche)){
        //le scan des infos de fichier
        fscanf(Precherche,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",Recherche->ISBN,Recherche->TitreL,Recherche->CNE,&Recherche->date_emprunt.jour,&Recherche->date_emprunt.mois,&Recherche->date_emprunt.annee,&Recherche->date_retour.jour,&Recherche->date_retour.mois,&Recherche->date_retour.annee);
        if(strcmp(Recherche->ISBN,ISBNR)==0)
        {
            c=1;
            return 0;

        }
    }
    if(c==0)
        {
            return 1;
        }

free(Recherche);
free(Recherche->TitreL);
free(Recherche->CNE);
free(Recherche->ISBN);
}


void Recherche_Historique(){
    setColor(12);
    printf("\t********************* RECHERCHER DANS L'HISTORIQUE DES EMPRUNTES D'UN ETUDIANT *********************\n\n\n");
    resetColor();
    char *CNER;
    int c=0;
    emprunt *Recherche;
    Recherche=malloc(sizeof(emprunt));
    Recherche->CNE=malloc(14*sizeof(char));
    Recherche->TitreL=malloc(35*sizeof(char));
    Recherche->ISBN=malloc(35*sizeof(char));
    CNER=malloc(14*sizeof(char));

    //ouverture de fichier
    FILE *Precherche;
    Precherche=fopen("historique_emprunt.txt","r");

    //stockage des données
    printf("Entrer votre CNE: ");
    scanf("%s",CNER);
     //exraction de fichier et comparaison
    clearScreen();
    while(!feof(Precherche)){
        //le scan des infos de fichier
        fscanf(Precherche,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",Recherche->ISBN,Recherche->TitreL,Recherche->CNE,&Recherche->date_emprunt.jour,&Recherche->date_emprunt.mois,&Recherche->date_emprunt.annee,&Recherche->date_retour.jour,&Recherche->date_retour.mois,&Recherche->date_retour.annee);
        if(strcmp(Recherche->CNE,CNER)==0)
        {
            c=1;
            break;
        }
    }
    fclose(Precherche);
    if(c==0)
        {
            printf("VOUS N'AVEZ AUCUNE EMPRUNT");
            getch();
        }
    else if(c==1)
    {
        int i=4;
        Precherche=fopen("historique_emprunt.txt","r");

        clearScreen();
        setColor(12);
        printf("********************************** HISTORIQUE D'EMPRUNTS ***********************************\n");
        resetColor();
printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
setColor(14);
printf("³ISBN"); gotoxy(13,2);printf("³TITRE DE LIVRE");gotoxy(48,2);printf("³CNE");gotoxy(62,2);printf("³DATE D'EMPRUNT");gotoxy(80,2);printf("³DATE DE RETOUR³");
resetColor();
        while(!feof(Precherche)){
        //le scan des infos de fichier
        fscanf(Precherche,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",Recherche->ISBN,Recherche->TitreL,Recherche->CNE,&Recherche->date_emprunt.jour,&Recherche->date_emprunt.mois,&Recherche->date_emprunt.annee,&Recherche->date_retour.jour,&Recherche->date_retour.mois,&Recherche->date_retour.annee);

        if(strcmp(Recherche->CNE,CNER)==0)
        {

           printf("\nÃÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
           gotoxy(0,i);printf("³%s",Recherche->ISBN); gotoxy(13,i);printf("³%s",Recherche->TitreL);gotoxy(48,i);printf("³%s",Recherche->CNE);gotoxy(62,i);printf("³%d/%d/%d",Recherche->date_emprunt.jour,Recherche->date_emprunt.mois,Recherche->date_emprunt.annee);gotoxy(80,i);printf("³%d/%d/%d    ³",Recherche->date_retour.jour,Recherche->date_retour.mois,Recherche->date_retour.annee);
            i+=2;


        }
    }
        printf("\nÀÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

    }


    fclose(Precherche);
    free(Recherche);
}


void affichage_de_historique(){
    //declaration du pointeur sur le fichier et ouverture du fichier
int i=5;
emprunt *afficher;
afficher=malloc(sizeof(emprunt));
afficher->TitreL=malloc(35*sizeof(char));
afficher->CNE=malloc(14*sizeof(char));
afficher->ISBN=malloc(14*sizeof(char));
FILE *Paffiche;
Paffiche=fopen("historique_emprunt.txt","r");
if(Paffiche==NULL)
{
    printf("erreur lors d'affichage");
}

printf("\n********************************** HISTORIQUE D'EMPRUNTS ***********************************\n");
printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("³ISBN"); gotoxy(13,3);printf("³TITRE DE LIVRE");gotoxy(48,3);printf("³CNE");gotoxy(62,3);printf("³DATE D'EMPRUNT");gotoxy(80,3);printf("³DATE DE RETOUR³");
//printf("\nÃÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");

while(!feof(Paffiche)){
printf("\nÃÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
        //le scan des infos de fichier
    fscanf(Paffiche,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",afficher->ISBN,afficher->TitreL,afficher->CNE,&afficher->date_emprunt.jour,&afficher->date_emprunt.mois,&afficher->date_emprunt.annee,&afficher->date_retour.jour,&afficher->date_retour.mois,&afficher->date_retour.annee);
        //affichage
  gotoxy(0,i);printf("³%s",afficher->ISBN); gotoxy(13,i);printf("³%s",afficher->TitreL);gotoxy(48,i);printf("³%s",afficher->CNE);gotoxy(62,i);printf("³%d/%d/%d",afficher->date_emprunt.jour,afficher->date_emprunt.mois,afficher->date_emprunt.annee);gotoxy(80,i);printf("³%d/%d/%d    ³",afficher->date_retour.jour,afficher->date_retour.mois,afficher->date_retour.annee);

i+=2;
}

printf("\nÀÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");

fclose(Paffiche);
free(afficher);
free(afficher->TitreL);
free(afficher->CNE);
free(afficher->ISBN);

}


void supprimer_emprunt(){


    setColor(12);
    printf("        ************************************** SUPPRESSION D'EMPRUNTS **************************************\n\n\n");
    resetColor();


    emprunt *retour;
    retour=malloc(sizeof(emprunt));
    retour->TitreL=malloc(35*sizeof(char));
    retour->CNE=malloc(14*sizeof(char));
    retour->ISBN=malloc(14*sizeof(char));
    FILE *Ptempsfile;

//    creation de fichier temporaire
    Ptempsfile=fopen("registre_temporaire.txt","w");
    fclose(Ptempsfile);
    FILE *PORIGINE;

    //l'ouverture des  fichoiers avec les modes convonable
    PORIGINE=fopen("registre_emprunt.txt","r");
    Ptempsfile=fopen("registre_temporaire.txt","a");

    if(Ptempsfile==NULL)
        printf("erreur d'overture");
    //l'identification de livre a suuprimé
    char ISBNR[20];
    printf("Veuillez entrer l'ISBN du livre a retournee : ");
    scanf("%s",ISBNR);
    int k=1;
    //on verifie si le livre est retourne au temp ou non
    while(!feof(PORIGINE)){
        //le scan des infos de fichier
        fscanf(PORIGINE,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",retour->ISBN,retour->TitreL,retour->CNE,&retour->date_emprunt.jour,&retour->date_emprunt.mois,&retour->date_emprunt.annee,&retour->date_retour.jour,&retour->date_retour.mois,&retour->date_retour.annee);

        if(strcmp(retour->ISBN,ISBNR)==0)
        {
            k=0;
            printf("\nLE LIVRE  : %s , EST EMPRUNTE PAR L'ETUDIANT DE CNE : %s \n\n DATE D'EMPRUNT: %d/%d/%d ,DATE DE RETOUR EXPECTE DE LIVTRE EST LE  : %d/%d/%d\n",retour->TitreL,retour->CNE,retour->date_emprunt.jour,retour->date_emprunt.mois,retour->date_emprunt.annee,retour->date_retour.jour,retour->date_retour.mois,retour->date_retour.annee);
            break;
        }
    }
    fclose(PORIGINE);
if(k==0){
    //comparant la date de retour avec la date d'ajourd'hui
        time_t now=time(NULL);
    struct tm *todaystime = localtime(&now);
    date reel;
    reel.annee=todaystime->tm_year+1900;
    reel.mois=todaystime->tm_mon+1;
    reel.jour=todaystime->tm_mday;
   int c = comparaison_des_dates(reel,retour->date_retour);
   if(c==0){
        setColor(12);
    printf("\n     \nLA DATE DE RETOUR EST DEJA  EXPIRE  LE  %d/%d/%d ",retour->date_retour.jour,retour->date_retour.mois,retour->date_retour.annee);
    getch();
    clearScreen();
    gotoxy(30,2);
    printf("\t\t\n!! ATTENTION  !!\n\t");
    gotoxy(28,4);
    printf("VOUS  AVEZ UNE AVERTISSEMENT");
    resetColor();
    FILE *PADV;
    PADV=fopen("LES ETUDIANTS AVERTIS.txt","a");
    fprintf(PADV,"%s\n",retour->CNE);
    fclose(PADV);
   }
   else if(c==1)
    printf("\n MERCI POUR RESPECTER LA DATE DE RETOUR ");

    PORIGINE=fopen("registre_emprunt.txt","r");
    //maintenant on supprime l'enregistrement on veut
    while(!feof(PORIGINE))
    {
        fscanf(PORIGINE,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",retour->ISBN,retour->TitreL,retour->CNE,&retour->date_emprunt.jour,&retour->date_emprunt.mois,&retour->date_emprunt.annee,&retour->date_retour.jour,&retour->date_retour.mois,&retour->date_retour.annee);
        if(strcmp(retour->ISBN,ISBNR)!=0){
        fprintf(Ptempsfile,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",retour->ISBN,retour->TitreL,retour->CNE,retour->date_emprunt.jour,retour->date_emprunt.mois,retour->date_emprunt.annee,retour->date_retour.jour,retour->date_retour.mois,retour->date_retour.annee);
        }
    }
    fclose(PORIGINE);
    fclose(Ptempsfile);

    remove("registre_emprunt.txt");
    rename("registre_temporaire.txt","registre_emprunt.txt");


    getch();
    clearScreen();
    printf("EMPRUNT SUPPRIMEE");
    getch();
    }
    else
        printf("EMPRUNT N'EXISTE PAS OU DEJA SUPPRIMEE");

    free(retour);
    free(retour->TitreL);
    free(retour->CNE);
    free(retour->ISBN);

}

int comparaison_des_dates(date reel, date expected){
    if( reel.annee > expected.annee ){
            return 0;
    }
    else if(reel.annee == expected.annee){
            if(reel.mois > expected.mois){
                    return 0;
            }
            else if(reel.mois == expected.mois){

                    if(reel.jour>expected.jour){
                        return 0;
                    }
                    else
                        return 1;
                    }
            else
                return 1;
    }
    else
        return 1;
}


int nombre_avertissement(){









    FILE *NADV;
    NADV=fopen("LES ETUDIANTS AVERTIS.txt","r");
    if(NADV == NULL)
        printf("erreur d'ouverture de fichier");
    int c =0;//comteur
    char *CNE,*CNET;//le CNE  a compter
    CNE=malloc(14*sizeof(char));
    CNET=malloc(14*sizeof(char));
    printf("Entrer le CNE de l'etudiant : ");
    scanf("%s",CNE);
    while(!feof(NADV))
    {
        fscanf(NADV,"%s",CNET);
        if(strcmp(CNET,CNE)==0)
            c++;
    }
    fclose(NADV);
    clearScreen();
gotoxy(0,0);printf("CODE ETUDIANT  "); gotoxy(15,0);printf(" \tNOMBRE D'AVERTISSEMENT ");
gotoxy(1,1);printf("%s",CNE); gotoxy(17,1);printf("\t    %d",c);
    return c;
}
void LIVRE_DATESR_EXPIRE(){
    //la date d'aujourd'hui
    time_t now=time(NULL);
    struct tm *curr_time=localtime(&now);
    date currnttime;
    currnttime.annee=curr_time->tm_year+1900;
    currnttime.mois=curr_time->tm_mon+1;
    currnttime.jour=curr_time->tm_mday;
    //extraction des infos de fichier
     emprunt * retour;
     retour=malloc(sizeof(emprunt));
     retour->TitreL=malloc(35*sizeof(char));
     retour->CNE=malloc(15*sizeof(char));
     retour->ISBN=malloc(15*sizeof(char));

     FILE * PORIGINE;
     PORIGINE=fopen("registre_emprunt.txt","r");
     int c=1,k=0;
     while(!feof(PORIGINE)){
        fscanf(PORIGINE,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",retour->ISBN,retour->TitreL,retour->CNE,&retour->date_emprunt.jour,&retour->date_emprunt.mois,&retour->date_emprunt.annee,&retour->date_retour.jour,&retour->date_retour.mois,&retour->date_retour.annee);
        //comparaison des dates

       c=comparaison_des_dates(currnttime,retour->date_retour);
        if(c==0){
            printf("\nLe Livre: %s DEVRAIT ETRE DEPOSE LE %d/%d/%d PAR L'ETUDIANT %s \n ",retour->TitreL,retour->date_retour.jour,retour->date_retour.mois,retour->date_retour.annee,retour->CNE);
            k=1;
        }
     }
     if(k==0)
        printf("AUCUNE DATE N'EST EXPIRE");


    fclose(PORIGINE);
    free(retour);
    free(retour->TitreL);
    free(retour->CNE);
    free(retour->ISBN);

}


void verfie_emprunt(){
    setColor(12);
    printf("\n          ********************************** VERIFICATION DES EMPRUNTS ***********************************\n\n\n");
    resetColor();
    //les variable ou on vas stocker
    char *CNER;
    CNER=malloc(14*sizeof(char));
    int c=0;
    emprunt *Recherche;
    Recherche=malloc(sizeof(emprunt));
    Recherche->TitreL=malloc(25*sizeof(char));
    Recherche->CNE=malloc(14*sizeof(char));
    Recherche->ISBN=malloc(14*sizeof(char));


    //ouverture de fichier
    FILE *Precherche;
    Precherche=fopen("registre_emprunt.txt","r");

    //stockage des données
    setColor(14);
    printf("Entrer votre CNE : ");
    resetColor();
    scanf("%s",CNER);
     //exraction de fichier et comparaison
    clearScreen();
    printf("\n\nVOS EMPRUNTS SONT => \n");
    while(!feof(Precherche)){
        //le scan des infos de fichier
        fscanf(Precherche,"%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",Recherche->ISBN,Recherche->TitreL,Recherche->CNE,&Recherche->date_emprunt.jour,&Recherche->date_emprunt.mois,&Recherche->date_emprunt.annee,&Recherche->date_retour.jour,&Recherche->date_retour.mois,&Recherche->date_retour.annee);
        if(strcmp(Recherche->CNE,CNER)== 0)
        {
            c=1;

           printf("LE LIVRE : %s \t\t",Recherche->TitreL); printf(" LA DATE DE RETOUR EST LE %d/%d/%d",Recherche->date_retour.jour,Recherche->date_retour.mois,Recherche->date_retour.annee);
            printf("\n");
        }
    }
    if(c==0)
        {
            setColor(12);
            printf("\n\nVOUS N'AVEZ PAS D'EMPRUNT !");
            resetColor();
        }
        fclose(Precherche);
        free(Recherche);
        free(Recherche->TitreL);
        free(Recherche->CNE);
        free(Recherche->ISBN);
        free(CNER);
}


#endif // GESTIONEMPRUNT_H_INCLUDED
