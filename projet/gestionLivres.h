#ifndef GESTIONLIVRES_H_INCLUDED
#define GESTIONLIVRES_H_INCLUDED
#include "structures.h"

void gestionLivre(){


    header();
    char **questions = (char**)malloc(5*sizeof(char*));
    for(int i=0;i<6;i++){
        *(questions+i) = (char*)malloc(255*sizeof(char));
    }
    strcpy(*(questions),"Afficher le catalogue des livres");
    strcpy(*(questions+1),"Ajouter un Livre");
    strcpy(*(questions+2),"Supprimer un Livre");
    strcpy(*(questions+3),"Chercher un Livre");
    strcpy(*(questions+4),"Revenir au menu principal");
    int x=22,y=5,h=12,w=75;
    setxy(x,y);
    for(int i=0;i<=w;i++){
        setColor(9);
        printf("-");
    }
    resetColor();
    setxy(x+27,y+1);
    printf(" Gestion des Livres\n");
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

            setColor(9);
            printf("\n\t\t\t\t\t\tAffichage du catalogue\n\n");
            resetColor();
            affichage("doc.txt");
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionLivre();
            break;
        case 2:
            clearConsole();
            header();
            ajout_livre();
            printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
            getch();
            clearConsole();
            gestionLivre();
            break;
        case 3:
            clearConsole();
            header();
            if(supp()==1){
                setxy(x+26,y+13);
                printf("Livre supprimer avec success");
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                gestionLivre();
            }
            else
            {
                setxy(x+17,y+13);
                printf("Ce livre n'existe pas dans la bibliotheque");
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                gestionLivre();
            }
            break;
        case 4:
            clearConsole();
            header();

            if(etat()==1){
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                gestionLivre();
            }
            else{
                setxy(x+16,18);
                setColor(12);
                printf("Ce livre n'existe pas dans notre bibliotheque");
                resetColor();
                printf("\n\nAppuyer sur n importe qu'elle touche pour continuer...");
                getch();
                clearConsole();
                gestionLivre();
            }
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
    fflush(stdin);
}
void copie(char filename[25]){








    char buff[1000];
    FILE *c,*o;
    c= fopen(filename,"w");
    o = fopen("C:\\Users\\hp\\Desktop\\c\\DATA_1.txt", "r");
    if(o==NULL || c== NULL)
    {
        printf("erreur de creation du fichier COPIE\n");
        exit(1);
    }
    while(!feof(o))
    {
        fgets(buff,sizeof(buff),o);
        fprintf(c,"%s",buff);
    }
    printf("COPIE CHECK\n");
    fclose(o);
    fclose(c);
    fflush(stdin);

}
void affichage(char filename[100]){


    FILE *o;
    //copie("doc.txt");
    char line[1000];
    o= fopen(filename,"r");

    if (o == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }
    clearConsole();
    setColor(12);
    setxy(40,1);
    printf("Le catalogue des livres\n\n\n");
    resetColor();
    setColor(14);
    // Utilisation de parenthèses pour définir l'ordre des opérations
    while ((fgets(line,sizeof(line),o)) !=NULL)
    {
        puts(line);
        resetColor();

    }

    fclose(o);
    fflush(stdin);
}

void ajout_livre(){

    livre a;
    FILE *c;
    FILE *q;
    // creation de livre
    c= fopen("doc.txt","a+");
    q= fopen("LIVRES.txt","a");
    if(q==NULL)
    {
        printf("erreur de creation du fichier AJOUT \n");
        exit(1);
    }

    if(c==NULL)
    {
        printf("erreur de creation du fichier AJOUT \n");
        exit(1);
    }

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
    printf("*  Ajout De Livre  *");
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
    printf("ISBN");
    setxy(x+7,13);
    printf("----------------------------------------");
    setxy(x+7,14);
    printf("|                                      |");
    setxy(x+7,15);
    printf("----------------------------------------");
    setxy(x+23,16);
    printf("Titre");
    setxy(x+7,17);
    printf("----------------------------------------");
    setxy(x+7,18);
    printf("|                                      |");
    setxy(x+7,19);
    printf("----------------------------------------");
    setxy(x+23,20);
    printf("Auteur");
    setxy(x+7,21);
    printf("----------------------------------------");
    setxy(x+7,22);
    printf("|                                      |");
    setxy(x+7,23);
    printf("----------------------------------------");
    setxy(x+19,24);
    printf("Maison d'edition");
    setxy(x+7,25);
    printf("----------------------------------------");
    setxy(x+7,26);
    printf("|                                      |");
    setxy(x+7,27);
    printf("----------------------------------------");
    setxy(x+20,28);
    printf("Num d'edition");
    setxy(x+7,29);
    printf("----------------------------------------");
    setxy(x+7,30);
    printf("|                                      |");
    setxy(x+7,31);
    printf("----------------------------------------");

    //input
    setxy(x+9,14);
    scanf("%s",a.ISBN);
    do{
        fflush(stdin);
        setxy(x+9,18);
        gets(a.titre);
    }while(strcmp(a.titre,"\0")==0);

    do{
        setxy(x+9,22);
        fflush(stdin);
        gets(a.auteur);

    }while(strcmp(a.auteur,"\0")==0);

    do{
        setxy(x+9,26);
        fflush(stdin);
        gets(a.maison_edition);
    }while(strcmp(a.maison_edition,"\0")==0);


    setxy(x+9,30);
     scanf("%d",&a.nbr_edition);

    // ISBN

    while(strlen(a.ISBN)<13)
    {
        strcat(a.ISBN, " ");
    }
    // TITRE

    while(strlen(a.titre)<46)
    {
        strcat(a.titre, " ");
    }
    // auteur

    while(strlen(a.auteur)<28)
    {
        strcat(a.auteur, " ");
    }
    // MAISON DEDITION

    while(strlen(a.maison_edition)<16)
    {
        strcat(a.maison_edition, " ");
    }

    setColor(12);
    setxy(x+9,y+29);
    printf("Le livre est ajoutee avec success");
    sleep(2);
    resetColor();
    fprintf(c,"%s   %s  %s   %s     %d\n",a.ISBN,a.titre,a.auteur,a.maison_edition,a.nbr_edition);
    fputs(a.ISBN,q);

    fclose(c);
    fclose(q);
    affichage("doc.txt");
    fflush(stdin);
}

int supp(){



      char sp[25];
      livre del[30];
      FILE *nv,*c;
      nv =fopen("doc_n.txt","w");
      c = fopen("doc.txt","r");
      int ch = 0;
      if(nv==NULL || c==NULL)
      {
          printf("erreur de creation du fichier \n");
          exit(1);
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
    printf("*****************   Suppression    *****************");
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
    printf("ISBN");
    setxy(x+7,13);
    printf("----------------------------------------");
    setxy(x+7,14);
    printf("|                                      |");
    setxy(x+7,15);
    printf("----------------------------------------");
    setxy(x+9,14);
    fflush(stdin);
    gets(sp);
    char line[1000];
    int numberOfBooks = 0;
        while (fgets(line, sizeof(line), c) != NULL && numberOfBooks < 100)
            {
                // Assuming each line has the format: Title;Author;Year
                sscanf(line, "%[^ ] %[^ ] %[^ ] %[^ ] %d", del[numberOfBooks].ISBN, del[numberOfBooks].titre,
                del[numberOfBooks].auteur, del[numberOfBooks].maison_edition, &del[numberOfBooks].nbr_edition);

                if(strcmp(sp,del[numberOfBooks].ISBN)!=0 ){
                    fputs(line,nv);
                    numberOfBooks++;
                }
                else if(strcmp(sp,del[numberOfBooks].ISBN)==0 )
                    ch=1;
            }

      fclose(nv);
      fclose(c);
      remove("doc.txt");
      rename("doc_n.txt","doc.txt");
      if(ch==1){
        return 1;
      }
      else
        return 0;
  }
int etat(){

      livre books[30];
      char id[20];
      FILE *etat;
      etat= fopen("doc.txt","r");
      if(etat==NULL)
      {
          printf("erreur de creation du fichier \n");
          exit(1);
      }
                        // SAISIE D'ISBN
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
    printf("ISBN");
    setxy(x+7,13);
    printf("----------------------------------------");
    setxy(x+7,14);
    printf("|                                      |");
    setxy(x+7,15);
    printf("----------------------------------------");
    setxy(x+9,14);
    scanf("%s",id);
                    // OUVERTURE ET STOCKAGE DANS LE TABLEAU
      char line[1000];
      int numberOfBooks = 0,verification=0;
      while (fgets(line, sizeof(line), etat) != NULL && numberOfBooks < 100)
      {
          sscanf(line, "%[^ ] %[^ ] %[^ ] %[^ ] %d", books[numberOfBooks].ISBN, books[numberOfBooks].titre,
                 books[numberOfBooks].auteur, books[numberOfBooks].maison_edition, &books[numberOfBooks].nbr_edition);
          numberOfBooks++;
      }
      for (int j = 1; j < numberOfBooks; j++)
        {
          if (strcmp(id, books[j].ISBN) == 0) {
              verification=1;

              setxy(x-16,y+13);
              setColor(8);
              printf("Informations sur le livre");
              resetColor();

              setxy(x-16,y+14);
              printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
              setxy(x-16,y+15);printf("³Titre");setxy(x+19,y+15);printf("³Auteur");setxy(x+51,y+15);printf("³Maison Edition            ³");
              setxy(x-16,y+16);printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
              setxy(x-16,y+17);printf("³%s",books[j].titre);setxy(x+19,y+17);printf("³%s",books[j].auteur);setxy(x+51,y+17);printf("³%s            ³",books[j].maison_edition);
              setxy(x-16,y+18);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
              break;
          }
      }
     if(verification!=1)
        return 0;
     else
        return 1;
  }
#endif // GESTIONLIVRES_H_INCLUDED
