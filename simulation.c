#include "simulation.h"


void simulerPropagationFeu(struct CelluleForet foret[][100], struct TailleMatrice taille, int nb_iterations) {
    struct CelluleForet foretSuivante[100][100];

    int ligne_feu, colonne_feu;
    printf("Entrez la ligne de la cellule en feu : ");
    scanf("%d", &ligne_feu);
    printf("Entrez la colonne de la cellule en feu : ");
    scanf("%d", &colonne_feu);

    // Mettre la cellule en feu une seule fois
    mettreCelluleEnFeu(foret, ligne_feu, colonne_feu, taille);

    for (int iter = 0; iter < nb_iterations; iter++) {
        for (int i = 0; i < taille.longueur; i++) {
            for (int j = 0; j < taille.largeur; j++) {
                //printf("%d %d \n", foret[i][j].degre, foret[i][j].etat);
                if (foret[i][j].etat == 1 && foret[i][j].degre == 2) {
                   foret[i][j].etat = 0;
                   foret[i][j].type = '-';
                }
                if (foret[i][j].type == '-') {
                    foret[i][j].type = '@';
                }

                if (foret[i][j].type == '#' || foret[i][j].type == 'x' || foret[i][j].type == '*' || foret[i][j].type == ' ') {

                    if ((i > 0 && j > 0 && foret[i - 1][j - 1].etat == 1) ||
                        (i > 0 && foret[i - 1][j].etat == 1) ||
                        (i > 0 && j < taille.largeur - 1 && foret[i - 1][j + 1].etat == 1) ||
                        (j > 0 && foret[i][j - 1].etat == 1) ||
                        (j < taille.largeur - 1 && foret[i][j + 1].etat == 1) ||
                        (i < taille.longueur - 1 && j > 0 && foret[i + 1][j - 1].etat == 1) ||
                        (i < taille.longueur - 1 && foret[i + 1][j].etat == 1) ||
                        (i < taille.longueur - 1 && j < taille.largeur - 1 && foret[i + 1][j + 1].etat == 1)) {
                            foret[i][j].etat = 1;
                            foret[i][j].degre -= 1;
                    }
                }
                if (foret[i][j].etat == 1 &&  foret[i][j].degre > 2) {
                    foret[i][j].degre -= 1;
                }
            }
        }

        memcpy(foretSuivante, foret, sizeof(foret));
        afficherMatrice(foret, taille);
        printf("-----------------------------------------------\n");
    }
}


void mettreCelluleEnFeu(struct CelluleForet foret[][100], int ligne, int colonne, struct TailleMatrice tailleMatrice) {
    if (ligne >= 0 && ligne < tailleMatrice.longueur && colonne >= 0 && colonne < tailleMatrice.largeur) {
        foret[ligne-1][colonne-1].etat = 1;
        printf("Cellule en feu à la ligne %d, colonne %d\n", ligne, colonne);
    } else {
        printf("Coordonnees invalides. Veuillez choisir une cellule à l\'interieur des limites de la matrice\n");
    }
}
