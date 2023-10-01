#include "main.h"
#include "init.h"
#include "menu.h"
#include "simulation.h"

struct CelluleForet foret[100][100];
struct CelluleForet foretInitiale[100][100];


int main() {
    printf("------------------------------------------\n");
    printf(">>> PROJET SIMULATION DE FEU DE FORET <<< \n");
    printf("------------------------------------------\n");

    int hauteur, largeur;
    demanderTailleMatrice(&hauteur, &largeur);

    choiceManuAuto(foret, hauteur, largeur);

    afficherMatrice(foret, hauteur, largeur);

    simulerPropagationFeu(foret, hauteur, largeur);
    simulMenu(hauteur, largeur);


    return 0;
}



