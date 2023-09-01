#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

struct TailleMatrice demanderTailleMatrice() {
    struct TailleMatrice taille;
    printf("Veuillez entrer la longueur de la matrice : ");
    scanf("%d", &taille.longueur);
    printf("Veuillez entrer la largeur de la matrice : ");
    scanf("%d", &taille.largeur);
    return taille;
}

void initialiserForetAleatoirement(struct CelluleForet foret[][100], struct TailleMatrice taille) {
    srand(time(NULL));

    for (int i = 0; i < taille.longueur; i++) {
        for (int j = 0; j < taille.largeur; j++) {
            char typesPossibles[] = {'+', '*', ' ', '#', 'x', '/', '-', '@'};
            int indexType = rand() % 8;
            foret[i][j].type = typesPossibles[indexType];

            foret[i][j].etat = 0;
            foret[i][j].degre = 0;
        }
    }
}

void afficherMatrice(struct CelluleForet foret[][100], struct TailleMatrice taille) {
    for (int i = 0; i < taille.longueur; i++) {
        for (int j = 0; j < taille.largeur; j++) {
            printf("%c ", foret[i][j].type);
        }
        printf("\n");
    }
}

int main() {
    struct TailleMatrice tailleMatrice = demanderTailleMatrice();

    struct CelluleForet foret[100][100];

    initialiserForetAleatoirement(foret, tailleMatrice);

    afficherMatrice(foret, tailleMatrice);

    return 0;
}
