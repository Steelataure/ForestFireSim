
#include "main.h"
#include "init.h"
#include "menu.h"
#include "simulation.h"

extern struct TailleMatrice tailleMatrice;
extern struct CelluleForet foret[100][100];
extern struct CelluleForet foretInitiale[100][100];


void choiceManuAuto(struct CelluleForet foret[100][100], struct TailleMatrice taille){
    int automatique_or_manuel;

    printf("Veuillez choisir entre une saisie manuel ou automatique \n1) Automatique\n2) Manuel \n> ");
    scanf("%d", &automatique_or_manuel);

    switch (automatique_or_manuel){
    case 1:
        initialiserForetAleatoirement(foret, taille);
        break;
    case 2:
        typeManuel(foret, taille);
        break;
    default:
        printf("-----------------------------------------\n");
        printf("Vous n'avez pas saisi une reponse valable\n");
        printf("-----------------------------------------\n");
        choiceManuAuto(foret, taille);
        break;
    }
}

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

