#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

#include "main.h"

void simulerPropagationFeu(struct CelluleForet foret[][100], struct TailleMatrice taille, int nb_iterations);
void mettreCelluleEnFeu(struct CelluleForet foret[][100], int ligne, int colonne, struct TailleMatrice taille);

#endif // SIMULATION_H_INCLUDED
