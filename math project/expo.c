#include <string.h> 
#include <stdlib.h>
#include <stdio.h>

#include "header.h"
#include "mathLib.h"


//Fonctions principales
double expo(double valeur, int nbDecimales){
	double resPrecision = (2.7 * exposant(0.5, (1 + 1))) / (1 + 1);
	double resultat = 0;	
	int n = 2; 
	while (resPrecision >= (0.5*exposant(10.0, -nbDecimales))){
		resPrecision = (2.7 * exposant(0.5, (n + 1))) / (factorielle(n + 1));
		n++;
	}
	n--;
	for (int i = 0; i < n; i++) 
		resultat += exposant(valeur, i) / factorielle(i);
	return resultat;
}

int erreurPropage(double valeurModif, int nbDecimales) {
	return entSup((nbDecimales + valeurModif - 0.5)*(valeurModif / 5) + 0.31);
}

double expoPlus05(double valeur, int nbDecimales) {
	double resultatY;
	double resultatReste;
	double valeurModif = (int)valeur + 1;
	int coef = (int)(valeur / 0.5);
	double reste = valeur - (coef * 0.5);
	int p = erreurPropage(valeurModif, nbDecimales);

	resultatY = expo(0.5, p);
	resultatReste = expo(reste, p);
	return (exposant(resultatY, coef)) * resultatReste;
}

double expoMoins05(double valeur, int nbDecimales) {
	double valeurCorrigee = valeurAbsolue(valeur);
	double resultat = expoPlus05(valeurCorrigee, nbDecimales);
	return  1 / resultat;
}


double exponentielle(double x, int nbDecimales){
	if (x > 0.5)
		return expoPlus05(x, nbDecimales);
	else{
		if (x < -0.5)
			return expoMoins05(x, nbDecimales);
		else
			return expo(x, nbDecimales);
	}
}