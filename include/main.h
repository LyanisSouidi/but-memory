#ifndef MAIN_H
#define MAIN_H

#include<graph.h>

#define WINDOW_WIDTH 1250
#define WINDOW_HEIGHT 750

typedef struct {
    int x, y, L, H;
} Zone;

int checkzone(Zone z, int x, int y);

void dessinerbouton(Zone z, char* texte, couleur arriereplan, couleur bordure, couleur couleurtexte, int tailletexte);

void dessinerzone(Zone z);

#endif
