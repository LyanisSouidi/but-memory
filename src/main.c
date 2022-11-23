#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"../include/menu.h"

typedef struct {
    int x, y, L, H;
} Zone;
 
 /*Check si une position (x,y) se trouve dans la zone; retourne 1 si dedans, sinon 0.*/
int checkzone(Zone z, int x, int y) {
    return x >= z.x && x <= z.x + z.L && y >= z.y && y <= z.y + z.H;
}

void dessinerbouton(Zone z, char* texte, couleur arriereplan, couleur bordure, couleur couleurtexte, int tailletexte) {
    ChoisirCouleurDessin(arriereplan);
    RemplirRectangle(z.x, z.y, z.L, z.H);
    
    ChoisirCouleurDessin(bordure);
    DessinerRectangle(z.x, z.y, z.L, z.H);
    ChoisirCouleurDessin(couleurtexte);
    EcrireTexte(z.x + z.L / 2 - TailleChaineEcran(texte, tailletexte) / 2, z.y + z.H / 2 + TailleSupPolice(tailletexte) / 2, texte, tailletexte);
}

void dessinerzone(Zone z) { 
    RemplirRectangle(z.x, z.y, z.L, z.H);
}

int main(void){
    InitialiserGraphique();
    CreerFenetre(375,175,1250,750);
    
    menu();
    
    FermerGraphique();
    return EXIT_SUCCESS;
}
