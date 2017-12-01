#pragma once
#define DEFAULT				0
#define DEFAULT_DECIMALES	5

#define MAX_BUFFER 1024

typedef enum menuPrincipal{
 EXPO = 1,
 LOG,
 SINUS,
 //PROB,
}MenuPrincipal;

// Erreur
	// ErreurAbsolute
	// ErreurRelative 


double exponentielle(double x, int nbDecimales);
double logarithmeNeperien(double x,int nbDecimales);
double sinus(double x,int nbDecimales);
//double proba(double x,double moyenne,double variance, double resultat);


