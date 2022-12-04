#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"../include/main.h"
#include"../include/timer.h"
#include"../include/card.h"
#include"../include/fin.h"

#define GAME_MARGIN_RIGHT 20
#define GAME_MARGIN_LEFT 20
#define GAME_MARGIN_TOP 35
#define GAME_MARGIN_BOTTOM 20

int game(int colonnes, int lignes) {
    int i, j, t, used, r, l, c, case_max_width, case_max_height, case_max_dimensions, case_margin, boucle, cheat;
    unsigned long int timer;
    char *file = (char*)malloc(30 * sizeof(char));
    size_t k, m;
    int* tab = malloc(sizeof(int) * (colonnes * lignes));
    srand(time(NULL));

    for (i = 1; i > -1; i--) {
        ChoisirEcran(i);
        EffacerEcran(CouleurParComposante(54, 57, 63));
    }

    ChoisirCouleurDessin(CouleurParNom("white"));

    for(i = 0; i < (colonnes * lignes) / 2;) {
        r = rand() % 60 + 1;
        used = 0;

        for (j = 0; j < i; j++) {
            if(tab[j] == r) {
                used = 1;
                break;
            }
        }
    
        if (!used) {
            tab[i] = r;
            i++;
        }
    }

    for (i = 0; i < (colonnes * lignes) / 2; i++) {
        tab[i + ((colonnes * lignes) / 2)] = tab[i];
    }

    for (k = 0; k < (colonnes * lignes) - 1; k++) {
        m = k + rand() / (RAND_MAX / ((colonnes * lignes) - k) + 1);
        t = tab[m];
        tab[m] = tab[k];
        tab[k] = t;
    }  

    case_max_width = (WINDOW_WIDTH - (GAME_MARGIN_RIGHT + GAME_MARGIN_LEFT)) / colonnes;
    case_max_height = (WINDOW_HEIGHT - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM)) / lignes;

    if (case_max_height <  case_max_width) {
        case_max_dimensions = case_max_height;
    } else {
        case_max_dimensions = case_max_width;
    }

    case_margin = case_max_dimensions * 0.05;
    card cards[lignes][colonnes];
    i=0;
    for (l = 0; l < lignes; l++) {
        for (c = 0; c < colonnes; c++) {
            sprintf(file, "img/cards/%dx%d/%d.jpg", colonnes, lignes, tab[i]);
            cards[l][c] = create_card(
                GAME_MARGIN_RIGHT + (((WINDOW_WIDTH - (GAME_MARGIN_RIGHT + GAME_MARGIN_LEFT)) - (case_max_dimensions * colonnes)) / 2) + (c * case_max_dimensions),
                GAME_MARGIN_TOP + (((WINDOW_HEIGHT - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM)) - (case_max_dimensions * lignes)) / 2) + (l * case_max_dimensions),
                case_max_dimensions - (2 * case_margin), case_max_dimensions - (2 * case_margin),
                tab[i],
                file
            );
            i++;
        }
    }
    free(file);

    timer = start_timer(0);

    boucle = 1;
    cheat=0;
    while (boucle) {
        update_timer(timer);

        SourisPosition();
        if (SourisCliquee()) {
            for (l = 0; l < lignes; l++) {
                for (c = 0; c < colonnes; c++) {
                    if (check_zone(cards[l][c].zone, _X, _Y)) {
                        cards[l][c] = show_card(cards[l][c]);
                    }
                }
            }
        }

        if (ToucheEnAttente() && Touche()==XK_t){
            timer = stop_timer(timer);
            for (l = 0; l < lignes; l++) {
                for (c = 0; c < colonnes; c++) {
                    load_card(cards[l][c]);
                }
            }

            CopierZone(0,2,GAME_MARGIN_RIGHT,GAME_MARGIN_TOP, WINDOW_WIDTH - (GAME_MARGIN_RIGHT + GAME_MARGIN_LEFT),WINDOW_HEIGHT - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM),GAME_MARGIN_RIGHT,GAME_MARGIN_TOP);

            CopierZone(1,0,GAME_MARGIN_RIGHT,GAME_MARGIN_TOP,WINDOW_WIDTH - (GAME_MARGIN_RIGHT + GAME_MARGIN_LEFT),WINDOW_HEIGHT - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM),GAME_MARGIN_RIGHT,GAME_MARGIN_TOP);

            if (Touche()==XK_t){
                CopierZone(2,0,GAME_MARGIN_RIGHT,GAME_MARGIN_TOP,WINDOW_WIDTH - (GAME_MARGIN_RIGHT + GAME_MARGIN_LEFT),WINDOW_HEIGHT - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM),GAME_MARGIN_RIGHT,GAME_MARGIN_TOP);
                while (SourisCliquee());
                timer = start_timer(timer);
            }
        }
    }

    for (l = 0; l < lignes; l++) {
        for (c = 0; c < colonnes; c++) {
            free(cards[l][c].file);
        }
    }

    return fin(stop_timer(timer));
}