#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"../include/main.h"

#define GAME_MARGIN_RIGHT 20
#define GAME_MARGIN_LEFT 20
#define GAME_MARGIN_TOP 35
#define GAME_MARGIN_BOTTOM 20

void game(int colonnes, int lignes) {
    EffacerEcran(CouleurParComposante(54, 57, 63));
    ChoisirCouleurDessin(CouleurParNom("white"));

    unsigned int case_max_width = (WINDOW_WIDTH - (GAME_MARGIN_RIGHT + GAME_MARGIN_LEFT)) / colonnes;
    unsigned int case_max_height = (WINDOW_HEIGHT - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM)) / lignes;
    unsigned int case_max_dimensions;

    if (case_max_height <  case_max_width) {
        case_max_dimensions = case_max_height;
    } else {
        case_max_dimensions = case_max_width;
    }

    unsigned int case_margin = case_max_dimensions * 0.05;

    for (unsigned int l = 0; l < lignes; l += 1) {
        for (unsigned int c = 0; c < colonnes; c += 1) {
					DessinerRectangle(GAME_MARGIN_RIGHT + (c * case_max_dimensions), GAME_MARGIN_TOP + (l * case_max_dimensions), case_max_dimensions - (2 * case_margin), case_max_dimensions - (2 * case_margin));
        }
    }
    
    Touche();
}
