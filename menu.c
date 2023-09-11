#ifndef MENU_C_INCLUDED
#define MENU_C_INCLUDED

#include "menu.h"
#include "main.h"
#include "simulation.h"

extern struct TailleMatrice tailleMatrice;
extern struct CelluleForet foret[100][100];

void menu(){
    int endchoice;
    printf("Que voulez vous faire ?\n");
    printf("1) Commencer une simulation\n");
    printf("2) Quitter\n");
    printf("> ");

    scanf("%d", &endchoice);

    switch (endchoice){
    case 1:
        //struct TailleMatrice tailleMatrice = demanderTailleMatrice();
        break;
    case 2:
        exit(0);
        break;

    default:
        printf("-----------------------------------------\n");
        printf("Vous n'avez pas saisi une reponse valable\n");
        printf("-----------------------------------------\n");
        menu();
        break;

    }
}

void endMenu(){
    int endchoice;
    printf(">>> FIN DE LA SIMULATION <<< \n");
    printf("Que voulez vous faire ?\n");
    printf("1) Ajouter des iterations\n");
    printf("2) Revenir en arri�re\n");
    printf("3) Refaire une autre simulation\n");
    printf("4) Quitter\n");
    printf("> ");

    scanf("%d", &endchoice);

    switch (endchoice){
    case 1:
        //simulerPropagationFeu(foret, tailleMatrice);
        break;
    case 2:
        break;
    case 3:
        main();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("-----------------------------------------\n");
        printf("Vous n'avez pas saisi une reponse valable\n");
        printf("-----------------------------------------\n");
        endMenu();
        break;
    }
}


#endif // MENU_C_INCLUDED
