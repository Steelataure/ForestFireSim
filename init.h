// init.h
#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

struct CelluleForet {
    char type;
    int etat;
    int degre;
};

void afficherMatrice(struct CelluleForet foret[100][100], int hauteur, int largeur);
//struct TailleMatrice demanderTailleMatrice();
void initialiserForetAleatoirement(struct CelluleForet foret[100][100], int hauteur, int largeur);
void typeManuel(struct CelluleForet foret[100][100], int hauteur, int largeur);
void choiceManuAuto(struct CelluleForet foret[100][100], int hauteur, int largeur);

void demanderTailleMatrice(int *hauteur, int *largeur);

#endif // INIT_H_INCLUDED
