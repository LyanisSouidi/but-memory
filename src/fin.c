#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"../include/main.h"
#include"../include/timer.h"

void fin(unsigned long int timer) {

    Zone Recommencer = {375, 665, 150, 35};
    Zone Quitterfin = {735, 665, 100, 35};

    ChargerImage("./../img/backgrounds/peeposhy.png", 225, 100, 0, 0, 800, 550);

    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(550, 150, "You Win !", 2);

    char buf[100];
    timer = stop_timer(timer);
    unsigned int secondes = timer / DELTA;
    unsigned int minutes = 0;
    while (secondes >= 60) {
        minutes += 1;
        secondes -= 60;
    }
    snprintf(buf, 100, "Votre temps : %02d:%02d", minutes, secondes);
    EcrireTexte(530, 200, buf, 1);

    dessinerbouton(Recommencer, "Recommencer", CouleurParNom("black"), CouleurParNom("dark green"), CouleurParNom("dark green"), 1);

    dessinerbouton(Quitterfin, "QUITTER", CouleurParNom("red"), CouleurParNom("red"), CouleurParNom("white"), 1);

    SourisPosition();

        if(SourisCliquee()) {

            if(checkzone(Quitterfin, _X, _Y))
                Touche();
            
        }
}