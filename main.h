#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


typedef struct TailleMatrice TailleMatrice;
struct TailleMatrice {
    int longueur;
    int largeur;
};

typedef struct CelluleForet CelluleForet;
struct CelluleForet {
    char type;
    int etat;
    int degre;
};


#endif // MAIN_H_INCLUDED
