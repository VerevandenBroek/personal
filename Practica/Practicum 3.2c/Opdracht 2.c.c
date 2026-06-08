#pragma warning(disable : 4996)   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* gen_random_array(int n, double min, double max) 
{
	if (n <= 0 || min > max) return NULL;//contrôleer of n positief is en min niet groter is dan max

	double* a = (double*)malloc(n * sizeof(double));//dynamische geheugenallocatie voor n doubles
	if (!a) return NULL;//controleer of malloc succesvol was

	for (int i = 0; i < n; i++) //vul de array met willekeurige doubles tussen min en max
    {
		double r = (double)rand() / (double)RAND_MAX;//genereer een willekeurig getal tussen 0 en 1
		a[i] = min + r * (max - min);//schalen naar het bereik [min, max]
    }
    return a;
}

void print_array(const double a[], int n) //functie om de inhoud van een array van doubles af te drukken
{
	for (int i = 0; i < n; i++) //loop door de array en druk elk element af met 2 decimalen
    {
		printf("%.2f ", a[i]);//%.2f zorgt ervoor dat het getal met 2 decimalen wordt weergegeven
    }
    printf("\n");
}

double* max_per_index(const double a[], const double b[], int n) //functie die een nieuwe array retourneert met de maximale waarde per index van twee arrays
{
	if (!a || !b || n <= 0) return NULL;//controleer of de invoer geldig is

	double* out = (double*)malloc(n * sizeof(double));//dynamische geheugenallocatie voor de output array
	if (!out) return NULL;//controleer of malloc succesvol was

	for (int i = 0; i < n; i++) //loop door beide arrays en vergelijk de waarden op dezelfde index, sla de maximale waarde op in de output array
    {
		out[i] = (a[i] >= b[i]) ? a[i] : b[i];//gebruik een ternary operator om de maximale waarde te bepalen
    }

    return out;
}

int main(void) 
{
	srand((unsigned)time(NULL));//initialiseer de random number generator met de huidige tijd als seed

    int n;
    double lo, hi;

    printf("Hoeveel getallen? ");
	if (scanf("%d", &n) != 1 || n <= 0) return 1;//controleer of de invoer voor n geldig is

    printf("Ondergrens en bovengrens: ");
	if (scanf("%lf %lf", &lo, &hi) != 2 || lo > hi) return 1;//controleer of de invoer voor lo en hi geldig is

	double* a1 = gen_random_array(n, lo, hi);//genereer twee arrays met willekeurige doubles binnen het opgegeven bereik
    double* a2 = gen_random_array(n, lo, hi);

	if (!a1 || !a2) //controleer of de arrays succesvol zijn gegenereerd
    {
        free(a1);
        free(a2);
        printf("Fout bij geheugentoewijzing.\n");
        return 1;
    }

    double* maxarr = max_per_index(a1, a2, n);
    if (!maxarr) 
    {
        free(a1);
        free(a2);
        printf("Fout bij allocatie van max-array.\n");
        return 1;
    }

    printf("\nArray 1:\n");
    print_array(a1, n);

    printf("Array 2:\n");
    print_array(a2, n);

    printf("Max-array:\n");
    print_array(maxarr, n);

    free(a1);
    free(a2);
    free(maxarr);

    return 0;
}