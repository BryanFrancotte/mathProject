#include <stdlib.h>
#include <stdio.h>
#include "mathLib.h"

//fonction main
//ln (x+1)
double ln(int n, double x) {
	int i = 1;
	double resultat = 0.0;
	while (i <= n) {
		if ((i % 2) == 0)
			resultat -= exposant(x, i) / i;
		else 
			resultat += exposant(x, i) / i;
		i++;
	}
	return resultat;
}

int calculExposant(double x) {
	x++;
	int i = 0;
	while (x >= 1.4) {
		x /= 1.4;
		i++;
	}
	return i;
}

int calculNbIter(int p) {
	int n = 0;
	double terme = exposant(0.5, n + 1) / (n + 1);
	while (terme >= 0.5 * exposant(10, -p)) {
		n++;
		terme = exposant(0.5, n + 1) / (n + 1);
	}
	return n;
}

double lnPlus14(double x, int nbDecimales) {
	int k = calculExposant(x);
	double reste = (x + 1) / exposant(1.4, k);
	int p = entSup(nbDecimales + ((k + 1) / 5.));
	int n = calculNbIter(p);
	double resultat = 0.0;

	for (int i = 0; i < k; i++) 
		resultat += ln(n, 0.4);
	resultat += ln(n, reste - 1);
	return resultat;
}

double lnNormal(double x, int nbDecimales) {
	double resultat = 0.0;
	int n = calculNbIter(nbDecimales);
	resultat = ln(n, x);
	return resultat;
}

double logarithmeNeperien(double x, int nbDecimales) {
	if (x >= -0.6 && x <= 1.4) {
		return lnNormal(x, nbDecimales);
	}
	else if (x > 1.4) {
		return lnPlus14(x, nbDecimales);
	}
	else if (x > -1) {
		printf("[i] Pas encore supporter...\n");
		getchar();
		return 0.0;
	}
	else {
		printf("[X] Hors du domaine ( D=]-1;inf[ )...\n");
		getchar();
		return 0.0;
	}
}