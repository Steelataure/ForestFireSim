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
                if (foret[i][j].etat == 1) {
                    // Appliquer les règles pour la cellule en feu
                    // Par exemple, mettre la cellule en cendres si nécessaire
                } else {
                    // Appliquer les règles pour les cellules non en feu
                    // Par exemple, vérifier les voisins pour la propagation du feu
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
        foret[ligne][colonne].etat = 1;
    } else {
        printf("Coordonnées invalides. Veuillez choisir une cellule à l'intérieur des limites de la matrice\n");
    }
}

