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

int update_coups(int coups) {
    char buf[100];

    ChoisirEcran(3);
    EffacerEcran(CouleurParComposante(54, 57, 63));
    ChoisirCouleurDessin(CouleurParNom("white"));
    snprintf(buf, 100, "Coups : %d", coups);
    EcrireTexte(180, 20, buf, 1);
    CopierZone(3, 0, 170, 0, 150, 30, 170, 0);
    ChoisirEcran(0);

    return coups;
}

int game(int colonnes, int lignes) {
    int i, j, t, used, r, l, c, case_max_width, case_max_height, case_max_dimensions, case_margin, boucle, coups, nb_paires_trouvees;
    unsigned long int timer;
    char file[30];
    size_t k, m;
    card* last_card = NULL; 
    int tab[colonnes * lignes];
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

    zone carte0 = {cards[0][0].zone.x, cards[0][0].zone.y, cards[0][0].zone.L, cards[0][0].zone.H};

    ChoisirEcran(4);
    sprintf(file, "img/cards/%dx%d/0.jpg", colonnes, lignes);
    ChargerImage(file, cards[0][0].zone.x, cards[0][0].zone.y, 0, 0, cards[0][0].zone.L, cards[0][0].zone.H);
    ChoisirEcran(0);

    timer = start_timer(0);
    coups = update_coups(0);

    for (l = 0; l < lignes; l++) {
        for (c = 0; c < colonnes; c++) {
            hide_card(carte0, cards[l][c]);
        }
    }

    nb_paires_trouvees = 0;
    while (nb_paires_trouvees < ((colonnes * lignes) / 2)) {
        update_timer(timer);

        SourisPosition();
        if (SourisCliquee()) {
            for (l = 0; l < lignes; l++) {
                for (c = 0; c < colonnes; c++) {
                    if (check_zone(cards[l][c].zone, _X, _Y) && !cards[l][c].displayed && !cards[l][c].found) {
                        cards[l][c] = show_card(cards[l][c]);
                        coups = update_coups(coups+1);
                        if (last_card != NULL)  {
                            if (!last_card->found && last_card->displayed && (cards[l][c].zone.x != last_card->zone.x || cards[l][c].zone.y != last_card->zone.y)) {
                                if (cards[l][c].id == last_card->id) {
                                    last_card->found = 1;
                                    cards[l][c].found = 1;
                                    nb_paires_trouvees++;
                                } else {
                                    wait(1);
                                    cards[l][c] = hide_card(carte0, cards[l][c]);
                                    *last_card = hide_card(carte0, *last_card);
                                }
                            }
                        }
                        last_card = &cards[l][c];
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

            while (Touche()!=XK_t);
            CopierZone(2,0,GAME_MARGIN_RIGHT,GAME_MARGIN_TOP,WINDOW_WIDTH - (GAME_MARGIN_RIGHT + GAME_MARGIN_LEFT),WINDOW_HEIGHT - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM),GAME_MARGIN_RIGHT,GAME_MARGIN_TOP);
            while (SourisCliquee());
            timer = start_timer(timer);
        }
    }

    for (l = 0; l < lignes; l++) {
        for (c = 0; c < colonnes; c++) {
            free(cards[l][c].file);
        }
    }

    return fin(stop_timer(timer), coups);
}