#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"../include/main.h"
#include"../include/timer.h"
#include"../include/fin.h"

#define GAME_MARGIN_RIGHT 20
#define GAME_MARGIN_LEFT 20
#define GAME_MARGIN_TOP 35
#define GAME_MARGIN_BOTTOM 20

typedef struct {
    int x, y, L, H, displayed, found;
    char *file;
} card;

card create_card(int x, int y, int L, int H, char *file) {
    card carte = {x, y, L, H, 0, 0, file};
    
    return carte;
}

int game(int colonnes, int lignes) {
    int i,j;
    int used, r;
    int* tab = malloc(sizeof(int) * (colonnes * lignes));
    srand(time(NULL));

    EffacerEcran(CouleurParComposante(54, 57, 63));
    ChoisirCouleurDessin(CouleurParNom("white"));

    for(i=0; i < (colonnes * lignes) / 2;) {
        r = rand() % 60 + 1;
        used=0;

        for(j=0; j < i; j++) {
            if(tab[j] == r) {
                used = 1;
                break;
            }
        }
    
        if(!used) {
            tab[i] = r;
            i++;
        }
    }

    for (i=0; i<(colonnes*lignes)/2; i+=1) {
    tab[i+((colonnes*lignes)/2)] = tab[i];
    }

    if ((colonnes * lignes) > 1) 
    {
        size_t i;
        for (i = 0; i < (colonnes * lignes) - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / ((colonnes * lignes) - i) + 1);
          int t = tab[j];
          tab[j] = tab[i];
          tab[i] = t;
        }
    }    

    unsigned int case_max_width = (WINDOW_WIDTH - (GAME_MARGIN_RIGHT + GAME_MARGIN_LEFT)) / colonnes;
    unsigned int case_max_height = (WINDOW_HEIGHT - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM)) / lignes;
    unsigned int case_max_dimensions;

    if (case_max_height <  case_max_width) {
        case_max_dimensions = case_max_height;
    } else {
        case_max_dimensions = case_max_width;
    }

    unsigned int case_margin = case_max_dimensions * 0.05;
    card cards[lignes][colonnes];

    for (unsigned int l = 0; l < lignes; l += 1) {
        for (unsigned int c = 0; c < colonnes; c += 1) {
		    cards[l][c] = create_card(GAME_MARGIN_RIGHT + (c * case_max_dimensions), GAME_MARGIN_TOP + (l * case_max_dimensions), case_max_dimensions - (2 * case_margin), case_max_dimensions - (2 * case_margin));
        }
    }
    unsigned long int timer = start_timer(0);

    int boucle = 1;
    while (boucle) {
      update_timer(timer);
    }
    
    return fin(timer);
}
