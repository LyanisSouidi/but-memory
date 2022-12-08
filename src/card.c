#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    char *filename = (char*)malloc(30 * sizeof(char));
    memcpy(filename, file, 30);
    zone zone = {x, y, L, H};
    card carte = {zone, 0, 0, 0, id, filename};
    return carte;
}

card hide_card(zone carte0, card carte){
    CopierZone(4, 0, carte0.x, carte0.y, carte0.L, carte0.H, carte.zone.x, carte.zone.y);
    carte.displayed = 0;
    return carte;
}