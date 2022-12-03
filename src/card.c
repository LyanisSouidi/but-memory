#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"../include/main.h"

typedef struct {
    zone zone;
    int displayed, found, loaded, id;
    char *file;
} card;

card load_card(card carte) {
    if (!carte.loaded) {
        ChoisirEcran(1);
        ChargerImage(carte.file, carte.zone.x, carte.zone.y, 0, 0, carte.zone.L, carte.zone.H);
        carte.loaded = 1;
        ChoisirEcran(0);
    }
    return carte;
}

card show_card(card carte) {
    if (!carte.loaded) carte = load_card(carte);
    CopierZone(1, 0, carte.zone.x, carte.zone.y, carte.zone.L, carte.zone.H, carte.zone.x, carte.zone.y);
    carte.displayed = 1;
    return carte;
}

card create_card(int x, int y,  int L, int H, int id, char *file) {
    zone zone = {x, y, L, H};
    card carte = {zone, 0, 0, 0, id, file};
    DessinerRectangle(carte.zone.x, carte.zone.y, carte.zone.L, carte.zone.H);
    return carte;
}