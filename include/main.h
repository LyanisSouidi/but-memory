#ifndef MAIN_H
#define MAIN_H

#include<graph.h>

#define WINDOW_WIDTH 1250
#define WINDOW_HEIGHT 750

typedef struct {
    int x, y, L, H;
} zone;

int check_zone(zone z, int x, int y);

void dessiner_bouton(zone z, char* texte, couleur arriere_plan, couleur bordure, couleur couleur_texte, int taille_texte);

void dessiner_zone(zone z);

#endif
