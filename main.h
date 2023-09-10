#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

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
void initialiserForetAleatoirement(struct CelluleForet foret[100][100], struct TailleMatrice taille);
void afficherMatrice(struct CelluleForet foret[100][100], struct TailleMatrice taille);

#endif // MAIN_H_INCLUDED
