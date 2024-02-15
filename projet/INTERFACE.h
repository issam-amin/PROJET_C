#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

void header(){

    setxy(0,1);
    for(int i=0;i<46;i++){
        printf("%c",205);
    }
    printf("%c",185);

    setxy(46,0);
    printf("%c",201);

    for(int i=0;i<26;i++){
        printf("%c",205);
    }

    setxy(72,0);
    printf("%c",187);


    setxy(46,2);
    printf("%c",200);

    for(int i=0;i<26;i++){
        printf("%c",205);
    }

    setxy(72,2);
    printf("%c",188);


    setxy(72,1);
    printf("%c",204);

    for(int i=0;i<47;i++){
    printf("%c",205);
}

    setxy(50,1);
    printf("   ENSAH Library");

}

COORD c = {0,0};
void setxy (int x, int y){


    c.X = x; c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void afficherCadre(char* texte) {
    int longueur = strlen(texte);
    int largeur = longueur + 4;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int largeurConsole = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int positionX = (largeurConsole - largeur) / 2;

    printf("%*s+", positionX, "");
    for (int i = 0; i < largeur; ++i) {
        printf("-");
    }

    printf("+\n");
    printf("%*s|  %s  |\n", positionX, "", texte);
    printf("%*s+", positionX, "");


    for (int i = 0; i < largeur; ++i) {
        printf("-");
    }
    printf("+\n");
}

void afficherCadre2(char* texte) {
    int longueur = strlen(texte);
    int largeur = longueur + 4;


    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int largeurConsole = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int positionX = (largeurConsole - largeur) / 2;


    printf("%*s+", positionX, "");
    for (int i = 0; i < largeur; ++i) {
        printf("-");
    }


    printf("+\n");
    printf("%*s|  ", positionX, "");

    for (int i = 0; i < longueur; ++i) {
        if (texte[i] == '\n') {
            printf("              |\n%*s|  ", positionX, "");
    }
    else {
        printf("%c", texte[i]);
    }
}

    for (int i = longueur; i < largeur - 4; ++i) {
        printf(" ");
    }

    printf("                |\n");
    printf("%*s+", positionX, "");

    for (int i = 0; i < largeur; ++i) {
        printf("-");
}
    printf("+\n");

}

void startScreen(){

    setColor(9);
    afficherCadre("Bienvenue Dans la Bibliotheque Officielle de l ENSAH");
    setColor(10);
    afficherCadre("Authentification");
    resetColor();
    afficherCadre2("1-Inscription\n2-Connexion");

}


void clearConsole() {



    // For Windows
    #ifdef _WIN32
    system("cls");
    // For Unix-like systems
    #else
    system("clear");
    #endif
}
void clearScreen() {
    // For Windows
    #ifdef _WIN32
    system("cls");
    // For Unix-like systems
    #else
    system("clear");
    #endif
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 15 corresponds à la couleur par défaut (blanc sur noir)
}

void cadreInterieur(char *texte){
    int x = 34,y=6;
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
        printf("*****************%s*****************",texte);
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


}
#endif // INTERFACE_H_INCLUDED
