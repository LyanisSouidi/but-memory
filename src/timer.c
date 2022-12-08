#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#define DELTA 1000000L

void update_timer(unsigned long int start) {
	int secondes = ((Microsecondes() - start) / DELTA);
	int minutes = 0;
	char buf[100];
		
	while (secondes >= 60) {
		minutes += 1;
		secondes -= 60;
	}

	ChoisirEcran(3);
	EffacerEcran(CouleurParComposante(54, 57, 63));
	ChoisirCouleurDessin(CouleurParNom("white"));
	snprintf(buf, 100, "Temps : %02d:%02d", minutes, secondes);
	EcrireTexte(20, 20, buf, 1);
	CopierZone(3, 0, 0, 0, 150, 30, 0, 0);
	ChoisirEcran(0);
}

unsigned long int start_timer(unsigned long int start) {
	start = Microsecondes() - start;
	update_timer(start);
	return start;
}

unsigned long int stop_timer(unsigned long int start) {
	return Microsecondes() - start;
}

void wait(int sec) {
    unsigned long int end = Microsecondes() + (sec * DELTA);
    while (Microsecondes() <= end);
}