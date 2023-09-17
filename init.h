#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED


struct TailleMatrice {
    int longueur;
    int largeur;
};

struct CelluleForet {
    char type;
    int etat;
    int degre;
};

struct TailleMatrice demanderTailleMatrice();
void afficherMatrice(struct CelluleForet foret[100][100], struct TailleMatrice taille);

void initialiserForetAleatoirement(struct CelluleForet foret[100][100], struct TailleMatrice taille);
void typeManuel(struct CelluleForet foret[100][100], struct TailleMatrice taille);


#endif // INIT_H_INCLUDED
