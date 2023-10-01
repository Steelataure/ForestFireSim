#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

#include "main.h"
#include "init.h"

void simulerPropagationFeu(struct CelluleForet foret[100][100], int hauteur, int largeur);
void mettreCelluleEnFeu(struct CelluleForet foret[100][100], int ligne, int colonne, int hauteur, int largeur);
void cellFeatureChange(struct CelluleForet foret[100][100], int hauteur, int largeur);
void revenirEnArriere(struct CelluleForet foret[100][100], struct CelluleForet foretInitiale[100][100], int hauteur, int largeur);

#endif // SIMULATION_H_INCLUDED
