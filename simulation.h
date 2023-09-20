#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

#include "main.h"
#include "init.h"

void simulerPropagationFeu(struct CelluleForet foret[100][100], struct TailleMatrice taille);
void mettreCelluleEnFeu(struct CelluleForet foret[100][100], int ligne, int colonne, struct TailleMatrice taille);
void revenirEnArriere(struct CelluleForet foret[100][100], struct CelluleForet foretInitiale[100][100], struct TailleMatrice taille);
void cellFeatureChange(struct CelluleForet foret[100][100], struct TailleMatrice taille);

#endif // SIMULATION_H_INCLUDED
