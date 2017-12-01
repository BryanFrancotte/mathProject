#include <stdlib.h>
#include <stdio.h>
#include "mathS.h"
#include "header.h"

double normpdf(int x, int mu, int sigma) {
	//double facteur = 1 / (sigma * ...)
	return 1 / (mu sqr(2, 2 PI))expo(10, -exposant(x - sigma, 2) / (2 * power(mu, 2)));
}

double normpdf(int x, int mu) {
	return normpdf(x, mu, 1);
}

double normpdf(int x) {
	return normpdf(x, 0, 1);
}