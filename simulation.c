#include "simulation.h"
#include "init.h"

struct CelluleForet foretInitiale[100][100];

void simulerPropagationFeu(struct CelluleForet foret[100][100], int hauteur, int largeur) {
    struct CelluleForet foretSuivante[100][100];
    int nb_iterations;

    printf("----------------------------------\n");
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
    mettreCelluleEnFeu(foret, ligne_feu, colonne_feu, hauteur, largeur);

    for (int iter = 0; iter < nb_iterations; iter++) {
        if (iter >= 1) {
            simulMenu();
        }
        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
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
                    int feuVoisin = 0;

                    // Vérification des 8 voisins
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            int ni = i + dx;
                            int nj = j + dy;

                            if (ni >= 0 && ni < hauteur && nj >= 0 && nj < largeur) {
                                if (foret[ni][nj].etat == 1 && foret[ni][nj].degre > 0) {
                                    feuVoisin = 1;
                                    break; // Si un voisin est en feu, inutile de vérifier les autres
                                }
                            }
                        }
                        if (feuVoisin) {
                            break; // Si un voisin est en feu, inutile de vérifier les autres
                        }
                    }

                    if (feuVoisin) {
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
        afficherMatrice(foret, hauteur, largeur);
        printf("----------------------------------\n");
    }
}

void mettreCelluleEnFeu(struct CelluleForet foret[100][100], int ligne, int colonne, int hauteur, int largeur) {
    if (ligne >= 0 && ligne < hauteur && colonne >= 0 && colonne < largeur) {
        foret[ligne - 1][colonne - 1].etat = 1;
        printf("Cellule en feu à la ligne %d, colonne %d\n", ligne, colonne);
    } else {
        printf("Coordonnees invalides. Veuillez choisir une cellule à l\'interieur des limites de la matrice\n");
    }
}

void cellFeatureChange(struct CelluleForet foret[100][100], int hauteur, int largeur){
    int choice_status;
    int cell_line;
    int cell_row;

    char new_type;
    int new_etat;
    int new_degre;


    printf("Donner la ligne de la case a changer  ?\n> ");
    scanf("%d", &cell_line);

    printf("Donner la colonne de la case a changer ?\n> ");
    scanf("%d", &cell_row);

    printf("Que voulez-vous changer ?\n");
    printf("1) Le type ?\n");
    printf("2) L\'etat ?\n");
    printf("3) Le degre ?\n> ");
    scanf("%d", &choice_status);

    switch (choice_status){
    case 1:
        printf("Entrez le nouveau type de la cellule [%d][%d] ", cell_line, cell_row);
        printf("\n(+ => sol, * => arbre, => feuille, # => roche, x => herbe, / => eau)");
        printf("\n> ");
        scanf(" %c", &new_type);
        foret[cell_line][cell_row].type = new_type;
        break;

    case 2:
        printf("Entrez le nouvel etat de la cellule [%d][%d] ", cell_line, cell_row);
        printf("\n(0 => eteint, 1 => en feu)");
        printf("\n> ");
        scanf("%d", &new_etat);
        foret[cell_line][cell_row].etat = new_etat;
        break;

    case 3:
        printf("Entrez le degre de la cellule [%d][%d] ", cell_line, cell_row);
        printf("\n> ");
        scanf("%d", &new_degre);
        foret[cell_line][cell_row].degre = new_degre;
        break;

    default:
        printf("-----------------------------------------\n");
        printf("Vous n'avez pas saisi une reponse valable\n");
        printf("-----------------------------------------\n");
        cellFeatureChange(foret, hauteur, largeur);
        break;
    }

}


void revenirEnArriere(struct CelluleForet foret[100][100], struct CelluleForet foretInitiale[100][100], int hauteur, int largeur) {
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

        afficherMatrice(foret, hauteur, largeur);
        printf("----------------------------------\n");
    }
}
