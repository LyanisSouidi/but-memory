#include<stdlib.h>
#include<graph.h>
 
int main()
{
    InitialiserGraphique();
    CreerFenetre(375,175,1250,750);
    ChargerImageFond("./img/backgrounds/menu.png");
    couleur c;
    c=CouleurParNom("black");
    ChoisirCouleurDessin(c);
    RemplirRectangle(440, 60, 260, 55);
    RemplirRectangle(42, 350, 230, 35);
    RemplirRectangle(42, 425, 85, 35);
    RemplirRectangle(42, 500, 85, 35);
    RemplirRectangle(42, 575, 85, 35);

    c=CouleurParNom("white");
    ChoisirCouleurDessin(c);
    EcrireTexte(450, 100, "JEU DE PAIRES !", 2);
    DessinerRectangle (440, 60, 260, 55);

    c=CouleurParNom("white");
    ChoisirCouleurDessin(c);
    EcrireTexte(50, 375, "Selectionnez un niveau :", 1);
    DessinerRectangle(42, 350, 230, 35);

    c=CouleurParNom("dark green");
    ChoisirCouleurDessin(c);
    EcrireTexte(50, 450, "Facile", 1);
    DessinerRectangle(42, 425, 85, 35);

    c=CouleurParNom("orange");
    ChoisirCouleurDessin(c);
    EcrireTexte(50, 525, "Moyen", 1);
    DessinerRectangle(42, 500, 85, 35);

    c=CouleurParNom("red");
    ChoisirCouleurDessin(c);
    EcrireTexte(50, 600, "Difficile", 1);
    DessinerRectangle(42, 575, 85, 35);

    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}