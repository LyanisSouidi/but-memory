#ifndef CARD_H
#define CARD_H

typedef struct {
    zone zone;
    int displayed, found, loaded, id;
    char *file;
} card;

void load_card(card carte);

void show_card(card carte);

card create_card(int x, int y,  int L, int H, int id, char *file);

#endif