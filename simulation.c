#include "simulation.h"
#include "init.h"

struct CelluleForet foretInitiale[100][100];

void simulerPropagationFeu(struct CelluleForet foret[100][100], struct TailleMatrice taille) {
    struct CelluleForet foretSuivante[100][100];
    int nb_iterations;

    printf("Veuillez choisir le nombre d'iterations : ");
    scanf("%d", &nb_iterations);

    int ligne_feu, colonne_feu;
    printf("Entrez la ligne de la cellule en feu : ");
    scanf("%d", &ligne_feu);
    printf("Entrez la colonne de la cellule en feu : ");
    scanf("%d", &colonne_feu);

    // Copiez la forêt initiale
    memcpy(foretInitiale, foret, sizeof(foret));

    // Mettre la cellule en feu une seule fois
    mettreCelluleEnFeu(foret, ligne_feu, colonne_feu, taille);

    for (int iter = 0; iter < nb_iterations; iter++) {
        if (iter >= 1) {
            simulMenu();
        }
        for (int i = 0; i < taille.longueur; i++) {
            for (int j = 0; j < taille.largeur; j++) {
                if (foret[i][j].etat == 1){
                    if (foret[i][j].degre == 2){
                        foret[i][j].etat = 0;
                        foret[i][j].type = '-';
                    }
                    else if (foret[i][j].degre > 2){
                        foret[i][j].degre -= 1;
                    }
                }
                else if (foret[i][j].type == '-') {

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
                if (foret[i][j].type == '+' || foret[i][j].type == '/') {
                    foret[i][j].degre = 0;
                    foret[i][j].etat = 0;
                }

            }
        }
        memcpy(foretSuivante, foret, sizeof(foret));
        afficherMatrice(foret, taille);
        printf("----------------------------------\n");
    }
}

void mettreCelluleEnFeu(struct CelluleForet foret[100][100], int ligne, int colonne, struct TailleMatrice tailleMatrice) {
    if (ligne >= 0 && ligne < tailleMatrice.longueur && colonne >= 0 && colonne < tailleMatrice.largeur) {
        foret[ligne - 1][colonne - 1].etat = 1;
        printf("Cellule en feu à la ligne %d, colonne %d\n", ligne, colonne);
    } else {
        printf("Coordonnees invalides. Veuillez choisir une cellule à l\'interieur des limites de la matrice\n");
    }
}

void CellFeatureChange(struct CelluleForet foret[100][100], struct TailleMatrice taille){
    int choice_statut;
    int cell_position;

    printf("Donner la position de la case à changer [ligne][colonne] ?\n");
    scanf("%d", &cell_position);

    printf("Que voulez-vous changer ?\n");
    printf("1) Le type ?\n");
    printf("2) L'état ?\n");
    printf("3) Le degré ?\n");
    scanf("%d", &choice_statut);

}


void revenirEnArriere(struct CelluleForet foret[100][100], struct CelluleForet foretInitiale[100][100], struct TailleMatrice taille) {
    int nb_iterations_arriere;

    printf("Veuillez choisir le nombre d'iterations en arriere : ");
    scanf("%d", &nb_iterations_arriere);

    if (nb_iterations_arriere <= 0) {
        printf("Le nombre d'iterations en arriere doit etre superieur a zero\n");
        return;
    }

    for (int iter = 0; iter < nb_iterations_arriere; iter++) {
        // Restaurer la forêt
        memcpy(foret, foretInitiale, sizeof(foret));

        afficherMatrice(foret, taille);
        printf("----------------------------------\n");
    }
}
