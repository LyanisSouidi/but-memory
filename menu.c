#include<stdio.h>
#include<stdlib.h>
#include<graph.h>


typedef struct {
    int x,y,L,H;
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
    EcrireTexte(z.x + z.L / 2 - TailleChaineEcran(texte, tailletexte) / 2, 
        z.y + z.H / 2 + TailleSupPolice(tailletexte) / 2,
         texte, tailletexte);
}

void dessinerzone(Zone z) {
    
    RemplirRectangle(z.x, z.y, z.L, z.H);
}


int main()
{
    int boucle = 1;

    Zone Titre = {490, 60, 260, 55};
    Zone Selection = {42, 300, 230, 35};
    Zone Facile = {42, 375, 85, 35};
    Zone Moyen = {42, 450, 85, 35};
    Zone Difficile = {42, 525, 85, 35};
    Zone Quitter = {42, 605, 100, 35};

    InitialiserGraphique();
    CreerFenetre(375,175,1250,750);

    ChargerImageFond("./img/backgrounds/menu.png");

    dessinerbouton(Titre, "JEU DE PAIRES !", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 2);

    dessinerbouton(Selection, "Selectionnez un niveau :", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 1);

    dessinerbouton(Facile, "Facile", CouleurParNom("black"), CouleurParNom("dark green"), CouleurParNom("dark green"), 1);

    dessinerbouton(Moyen, "Moyen", CouleurParNom("black"), CouleurParNom("orange"), CouleurParNom("orange"), 1);

    dessinerbouton(Difficile, "Difficile", CouleurParNom("black"), CouleurParNom("red"), CouleurParNom("red"), 1);

    dessinerbouton(Quitter, "QUITTER", CouleurParNom("red"), CouleurParNom("red"), CouleurParNom("white"), 1);


    while(boucle) {
        SourisPosition();

        if(SourisCliquee()){

            if(checkzone(Quitter, _X, _Y))
                boucle = 0;
            
        }
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}