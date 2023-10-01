#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#include "init.h"


struct CelluleForet foret[100][100];


void demanderTailleMatrice(int *hauteur, int *largeur) {
    printf("Entrez la hauteur de la matrice : ");
    scanf("%d", hauteur);
    printf("Entrez la largeur de la matrice : ");
    scanf("%d", largeur);
}


void afficherMatrice(struct CelluleForet foret[100][100], int hauteur, int largeur) {
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            printf("%c ", foret[i][j].type);
        }
        printf("\n");
    }
}

// Fonction pour initialiser la forêt aléatoirement
void initialiserForetAleatoirement(struct CelluleForet foret[100][100], int hauteur, int largeur) {
    srand(time(NULL));

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
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
void typeManuel(struct CelluleForet foret[100][100], int hauteur, int largeur) {

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            printf("Entrez le type de la cellule [%d][%d] ", i, j);
            printf("\n(+ => sol, * => arbre, => feuille, # => roche, x => herbe, / => eau)");
            printf("\n >>> ");

            scanf(" %c", &foret[i][j].type);
        }
    }
}


void choiceManuAuto(struct CelluleForet foret[100][100], int hauteur, int largeur){
    int automatique_or_manuel;

    printf("Que voulez vous faire ?\n");
    printf("1) Matrice aleatoire ?\n");
    printf("2) Matrice manuelle ?\n");
    printf("> ");
    scanf("%d", &automatique_or_manuel);
    printf("------------------------\n");

    switch (automatique_or_manuel){
    case 1:
        initialiserForetAleatoirement(foret, hauteur, largeur);
        break;
    case 2:
        typeManuel(foret, hauteur, largeur);
        break;
    default:
        printf("-----------------------------------------\n");
        printf("Vous n'avez pas saisi une reponse valable\n");
        printf("-----------------------------------------\n");
        choiceManuAuto(foret, hauteur, largeur);
        break;
    }
}

// Réinitialisez les éléments par défauts
void relancerSimulation(struct CelluleForet foret[100][100], int hauteur, int largeur) {
    initialiserForetAleatoirement(foret, hauteur, largeur);
}
