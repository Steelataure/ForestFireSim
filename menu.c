#ifndef MENU_C_INCLUDED
#define MENU_C_INCLUDED

#include "menu.h"
#include "init.h"
#include "simulation.h"

extern struct TailleMatrice tailleMatrice;
extern struct CelluleForet foret[100][100];
extern struct CelluleForet foretInitiale[100][100];

void menu(){
    int choice;
    printf("Que voulez vous faire ?\n");
    printf("1) Commencer une simulation\n");
    printf("2) Quitter\n");
    printf("> ");

    scanf("%d", &choice);

    switch (choice){
        case 1:
            //struct TailleMatrice tailleMatrice = demanderTailleMatrice();
            break;
        case 2:
            exit(0);
            break;
        default:
            wrongInput();
            menu();
            break;
        }
}

void simulMenu(){
    int choice;
    int nombreIterations;

    printf("Que voulez vous faire ?\n");
    printf("1) Conitnuer ?\n");
    printf("2) Revenir en arriere ?\n");
    printf("3) Changer l\'etat d\'une case ?\n");
    printf("4) Refaire une autre simulation\n");
    printf("5) Quitter\n");
    printf("> ");

    scanf("%d", &choice);

    switch (choice){
        case 1:
            break;
        case 2:
            revenirEnArriere(foret, foretInitiale, tailleMatrice);
            break;
        case 3:
            break;
        case 4:
            main();
            break;
        case 5:
            exit(0);

        default:
            wrongInput();
            break;

        }

}

void wrongInput(){
    printf("-----------------------------------------\n");
    printf("Vous n'avez pas saisi une reponse valable\n");
    printf("-----------------------------------------\n");
}

#endif // MENU_C_INCLUDED
