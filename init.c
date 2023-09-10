#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"
#include "main.h"

// Fonction pour initialiser la forêt aléatoirement
void initialiserForetAleatoirement(struct CelluleForet foret[100][100], struct TailleMatrice taille) {
    srand(time(NULL));

    for (int i = 0; i < taille.longueur; i++) {
        for (int j = 0; j < taille.largeur; j++) {
            char typesPossibles[] = {'+', '*', ' ', '#', 'x', '/'};
            int indexType = rand() % 6;
            foret[i][j].type = typesPossibles[indexType];
            foret[i][j].etat = 0;
            foret[i][j].degre = 0;

            if (foret[i][j].type == '*') {
                foret[i][j].degre = 4;
            }
            else if (foret[i][j].type == 'x') {
                foret[i][j].degre = 3;
            }
            else if (foret[i][j].type == ' ') {
                foret[i][j].degre = 2;
            }
            else if (foret[i][j].type == '-') {
                foret[i][j].degre = 1;
            }
            else if (foret[i][j].type == '#') {
                foret[i][j].degre = 5;
            }
            else {
                foret[i][j].degre = 0;
            }
        }
    }
}

// Fonction pour initialiser la forêt manuellement
void typeManuel(struct CelluleForet foret[100][100], struct TailleMatrice taille) {

    for (int i = 0; i < taille.longueur; i++) {
        for (int j = 0; j < taille.largeur; j++) {
            printf("Entrez le type de la cellule [%d][%d] (A pour arbre, F pour feuille, R pour roche, etc.) : ", i, j);
            scanf(" %c", &foret[i][j].type);
        }
    }
}
