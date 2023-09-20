#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#include "init.h"


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
            printf("Entrez le type de la cellule [%d][%d] ", i, j);
            printf("\n(+ => sol, * => arbre, => feuille, # => roche, x => herbe, / => eau)");
            printf("\n >>> ");

            scanf(" %c", &foret[i][j].type);
        }
    }
}


void choiceManuAuto(struct CelluleForet foret[100][100], struct TailleMatrice taille){
    int automatique_or_manuel;

    printf("Que voulez vous faire ?\n");
    printf("1) Matrice aleatoire ?\n");
    printf("2) Matrice manuelle ?\n");
    printf("> ");
    scanf("%d", &automatique_or_manuel);
    printf("------------------------\n");

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
