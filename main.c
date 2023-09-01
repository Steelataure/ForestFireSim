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

void typeManuel(struct CelluleForet foret[][100], struct TailleMatrice taille) {

    for (int i = 0; i < taille.longueur; i++) {
        for (int j = 0; j < taille.largeur; j++) {
            printf("Entrez le type de la cellule [%d][%d] (A pour arbre, F pour feuille, R pour roche, etc.) : ", i, j);
            scanf(" %c", &foret[i][j].type);

            foret[i][j].etat = 0;
            foret[i][j].degre = 0;
        }
    }
}

int main() {
    int automatique_or_manuel;

    struct TailleMatrice tailleMatrice = demanderTailleMatrice();
    struct CelluleForet foret[100][100];

    printf("Veuillez choisir entre une saisi manuel ou automatique (0 => manuel | 1 => automatique) : ");
    scanf("%d", &automatique_or_manuel);

    if (automatique_or_manuel == 0){
        typeManuel(foret, tailleMatrice);
    }
    else if (automatique_or_manuel == 1){
        initialiserForetAleatoirement(foret, tailleMatrice);

    }

    afficherMatrice(foret, tailleMatrice);

    return 0;
}
