#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"../include/menu.h"
#define WINDOW_WIDTH 1250
#define WINDOW_HEIGHT 750

typedef struct {
    int x, y, L, H;
} zone;

int check_zone(zone z, int x, int y) {
    return x >= z.x && x <= z.x + z.L && y >= z.y && y <= z.y + z.H;
}

void dessiner_bouton(zone z, char* texte, couleur arriere_plan, couleur bordure, couleur couleur_texte, int taille_texte) {
    ChoisirCouleurDessin(arriere_plan);
    RemplirRectangle(z.x, z.y, z.L, z.H);
    
    ChoisirCouleurDessin(bordure);
    DessinerRectangle(z.x, z.y, z.L, z.H);
    ChoisirCouleurDessin(couleur_texte);
    EcrireTexte(z.x + z.L / 2 - TailleChaineEcran(texte, taille_texte) / 2, z.y + z.H / 2 + TailleSupPolice(taille_texte) / 2, texte, taille_texte);
}

void dessiner_zone(zone z) { 
    RemplirRectangle(z.x, z.y, z.L, z.H);
}

int main(void){
    InitialiserGraphique();
    CreerFenetre(375,175,WINDOW_WIDTH,WINDOW_HEIGHT);
    
    menu();
    
    FermerGraphique();
    return EXIT_SUCCESS;
}