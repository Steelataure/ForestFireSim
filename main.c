#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "main.h"
#include "init.h"
#include "simulation.h"


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


int main() {
    int automatique_or_manuel;
    int nb_iterations;

    struct TailleMatrice tailleMatrice = demanderTailleMatrice();
    struct CelluleForet foret[100][100];

    printf("Veuillez choisir entre une saisie manuelle ou automatique \n(0 => manuelle | 1 => automatique) : ");
    scanf("%d", &automatique_or_manuel);

    if (automatique_or_manuel == 0){
        typeManuel(foret, tailleMatrice);
    }
    else if (automatique_or_manuel == 1){
        initialiserForetAleatoirement(foret, tailleMatrice);
    }
    afficherMatrice(foret, tailleMatrice);

    printf("Veuillez choisir le nombre d\'iterations : ");
    scanf("%d", &nb_iterations);


    simulerPropagationFeu(foret, tailleMatrice, nb_iterations);

    return 0;
}

