#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"../include/main.h"

typedef struct {
    zone zone;
    int displayed, found;
    char *file;
} card;

card create_card(int x, int y,  int L, int H, char *file) {
    zone zone = {x, y, L, H};
    card carte = {zone, 0, 0, file};
    DessinerRectangle(carte.zone.x, carte.zone.y, carte.zone.L, carte.zone.H);
    return carte;
}