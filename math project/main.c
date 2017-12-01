#include <stdio.h>
#include <windows.h>

#include "header.h"
#include "erreur.h"

int menu(){
	int choix;
	do {
		printf(
			"Menu choix\n"
			" %i- EXPO\n"
			" %i- LOG\n"
			" %i- SINUS\n"
			//" %i- PROB\n"
			"Choix: ",
				EXPO,
				LOG,
				SINUS
				//PROB
		);
		scanf_s("%i", &choix);
		system("cls");
	} while(choix < EXPO || choix > SINUS);
	return choix;
}


// return value of x
double obtention(int *nbDecimales, MenuPrincipal choix){
	double x = 0;
	do {
		printf("Entre the value of X:");
		scanf_s("%lf", &x);
		system("cls");
	} while(x < -1 && choix == LOG);

	do {
		printf("Entre the number of decimal: ");
		scanf_s("%i", nbDecimales);
		system("cls");
	} while(*nbDecimales < 0 || *nbDecimales >= 20);
	return x;
}
//double obtentionProba(double* moyenne,double* variance){
//	double x = 0;
//	do {
//		printf("Entre the value of X:");
//		scanf_s("%lf", &x);
//		system("cls");
//	} while(x < 0);  // OK ????
//
//		printf("Entre the value of the av:");
//		scanf_s("%lf", moyenne);
//		system("cls");
//	do {
//		printf("Entre the value of variance:");
//		scanf_s("%lf", variance);
//		system("cls");
//	} while(x < 0);  // OK ????
//	/*Variance toujours positive*/
//	return 0;
//}



int main(){
	//int codeMenu = DEFAULT;
	double resultat = DEFAULT;
	int nbDecimales = DEFAULT_DECIMALES;
	/*double moyenne = DEFAULT;
	double variance = DEFAULT;*/
	double x;
	MenuPrincipal numMenu = menu();
	switch (numMenu) {
		case EXPO:
			x = obtention(&nbDecimales, numMenu);
			resultat = exponentielle(x,nbDecimales);
			break;
		case LOG:
			x = obtention(&nbDecimales, numMenu);
			resultat = logarithmeNeperien(x,nbDecimales);
			break;
		case SINUS:
			x = obtention(&nbDecimales, numMenu);
			resultat = sinus(x,nbDecimales);
			break;
		/*case PROB:
			x = obtentionProba(&moyenne,&variance);
			resultat = proba(x,moyenne,variance);
			break;*/
	}

	/*
		char *msg = (char*)calloc(MAX_BUFFER, 1);
		if (msg != NULL) {
			sprintf_s(msg, MAX_BUFFER, "Resultat Valeur 2 : %%.%i", nbDecimales);
			strcat_s(msg, MAX_BUFFER, "lf\n");
			printf(msg, *resultat); // faire ici ??? 
			free(msg);
		}
		else
			codeErreur = ERREUR_POINTEUR_NULL;
	*/
	afficheDecimales(resultat, nbDecimales);
	printf("\n");
	system("pause");
	return 0;
}