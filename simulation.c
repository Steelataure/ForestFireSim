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
                    // Appliquer les r�gles pour la cellule en feu
                    // Par exemple, mettre la cellule en cendres si n�cessaire
                } else {
                    // Appliquer les r�gles pour les cellules non en feu
                    // Par exemple, v�rifier les voisins pour la propagation du feu
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
        printf("Coordonn�es invalides. Veuillez choisir une cellule � l'int�rieur des limites de la matrice\n");
    }
}

