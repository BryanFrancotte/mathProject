#include "mathS.h"

//Fonctions secondaires
double exposant(double base, int puissance) {
	double valeur = 1.0;
	if (puissance > 0) {
		for (int i = 0; i < puissance; i++)
			valeur *= base;
	}else {
		for (int i = 0; i < -puissance; i++)
			valeur *= 1 / base;
	}
	return valeur;
}

double factorielle(int valeur) {
	double resultat = 1.0;
	for (int i = 1; i <= valeur; i++)
		resultat *= i;
	return resultat;
}
double valeurAbsolue(double valeur) {
	return (valeur > 0) ? valeur : -valeur;
}
double toRadians(double angdeg){
	return angdeg / 180.0 * PI;
}
double power(double x, int y) {
	double p = 1.0;
	for (int i = 0; i < y; i++)
		p *= x;
	return p;
}
int entSup(double valeur) {
	int partieEntiere = (int)valeur;
	return partieEntiere++;
}
