#pragma warning(disable : 4996)  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(const double a[], int n) // const double a[] betekent dat de functie de array niet zal wijzigen
{
	for (int i = 0; i < n; i++) // Loop door de array en print elk element met 2 decimalen
    {
		printf("%.2f ", a[i]);//%.2f zorgt ervoor dat het getal met 2 decimalen wordt weergegeven    
    }
	printf("\n");// Print een nieuwe regel na het printen van de array
}

double* gen_random_array(int n, double lo, double hi) // Deze functie genereert een array van n willekeurige doubles tussen lo en hi
{
	double* p = (double*)malloc(n * sizeof(double)); // Dynamisch geheugen toewijzen voor n doubles
	if (!p) return NULL;// Controleer of de geheugenallocatie is gelukt

	for (int i = 0; i < n; i++) // Loop door de array en vul elk element met een willekeurige double tussen lo en hi
    {
		double r = (double)rand() / (double)RAND_MAX; // Genereer een willekeurig getal tussen 0 en 1
		p[i] = lo + r * (hi - lo);// Schaal het willekeurige getal naar het bereik [lo, hi]
    }
	return p;// Retourneer de pointer naar de gegenereerde array
}

int main(void) 
{
	srand((unsigned)time(NULL));// Initialiseer de random number generator met de huidige tijd als seed

    int n;
	double lo, hi;// Variabelen declareren voor het aantal elementen en de onder- en bovengrens

	printf("Aantal? ");// Vraag de gebruiker om het aantal elementen in de array
	if (scanf("%d", &n) != 1) return 1;   // Controleer of de invoer geldig is

	printf("Voer ondergrens en bovengrens in (bijv. -5 10): ");// Vraag de gebruiker om de onder- en bovengrens voor de willekeurige getallen
	if (scanf("%lf %lf", &lo, &hi) != 2) return 1;// Controleer of de invoer geldig is

	double* arr = gen_random_array(n, lo, hi);// Genereer een array van n willekeurige doubles tussen lo en hi
	if (!arr) return 1;// Controleer of de array succesvol is gegenereerd

	print_array(arr, n);// Print de gegenereerde array

    free(arr); 
}