#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "main.h"
#include "menu.h"
#include "init.h"
#include "simulation.h"

struct TailleMatrice tailleMatrice;
struct CelluleForet foret[100][100];

struct TailleMatrice demanderTailleMatrice() {
    struct TailleMatrice taille;
    printf("Veuillez entrer la longueur de la matrice : ");
    scanf("%d", &taille.longueur);
    printf("Veuillez entrer la largeur de la matrice : ");
    scanf("%d", &taille.largeur);
    return taille;
}


void afficherMatrice(struct CelluleForet foret[100][100], struct TailleMatrice taille) {
    for (int i = 0; i < taille.longueur; i++) {
        for (int j = 0; j < taille.largeur; j++) {
            printf("%c ", foret[i][j].type);
        }
        printf("\n");
    }
}

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
    endMenu();
    return 0;
}

