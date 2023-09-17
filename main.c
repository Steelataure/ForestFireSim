#include "main.h"
#include "init.h"
#include "menu.h"
#include "simulation.h"

extern struct TailleMatrice tailleMatrice;
extern struct CelluleForet foret[100][100];
extern struct CelluleForet foretInitiale[100][100];


int main() {
    printf("------------------------------------------\n");
    printf(">>> PROJET SIMULATION DE FEU DE FORET <<< \n");
    printf("------------------------------------------\n");

    menu();
    struct TailleMatrice tailleMatrice = demanderTailleMatrice();

    choiceManuAuto(foret, tailleMatrice);
    afficherMatrice(foret, tailleMatrice);
    simulerPropagationFeu(foret, tailleMatrice);
    simulMenu();
    return 0;
}

