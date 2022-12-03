#ifndef CARD_H
#define CARD_H

typedef struct {
    zone zone;
    int displayed, found, loaded, id;
    char *file;
} card;

card create_card(int x, int y,  int L, int H, char *file);

#endif