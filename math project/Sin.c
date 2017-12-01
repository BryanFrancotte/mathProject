#include <stdlib.h>
#include <stdio.h>
#include "mathLib.h"


double sinus(double x, int nbDecimales){
	while (x < 0)x += 360;
	while (x > 360) x -= 360;
	int facteur = 1;

	//Gestion entre 0 et 90 degres
	if (x > 90){
		if (x > 180){
			facteur = -1;
			x -= (x > 270)? 270: 180;
		}
		else
			x -= 90;
	}
	double xTransforme = toRadians(x);
	double resultat = xTransforme;
	for (int i = 1; i < nbDecimales; i++)
		resultat += (exposant(-1.0, i) * exposant(xTransforme, (2 * i + 1))) / factorielle(2 * i + 1);
	return facteur * resultat;
}