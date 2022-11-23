#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"../include/main.h"

void menu(void) {
    Zone Titre = {490, 60, 260, 55};
    Zone Selection = {42, 300, 230, 35};
    Zone Facile = {42, 375, 85, 35};
    Zone Moyen = {42, 450, 85, 35};
    Zone Difficile = {42, 525, 85, 35};
    Zone Quitter = {42, 605, 100, 35};

    ChargerImageFond("./img/backgrounds/menu.png");

    dessinerbouton(Titre, "JEU DE PAIRES !", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 2);

    dessinerbouton(Selection, "Selectionnez un niveau :", CouleurParNom("black"), CouleurParNom("white"), CouleurParNom("white"), 1);

    dessinerbouton(Facile, "Facile", CouleurParNom("black"), CouleurParNom("dark green"), CouleurParNom("dark green"), 1);

    dessinerbouton(Moyen, "Moyen", CouleurParNom("black"), CouleurParNom("orange"), CouleurParNom("orange"), 1);

    dessinerbouton(Difficile, "Difficile", CouleurParNom("black"), CouleurParNom("red"), CouleurParNom("red"), 1);

    dessinerbouton(Quitter, "QUITTER", CouleurParNom("red"), CouleurParNom("red"), CouleurParNom("white"), 1);


    int boucle = 1;
    while (boucle) {
        SourisPosition();

        if (SourisCliquee()) {
            if (checkzone(Quitter, _X, _Y)) boucle = 0;
        }
    }
}
