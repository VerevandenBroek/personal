#pragma warning(disable : 4996)   

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* gen_random_array(int n, double min, double max) //hier worden de random getallen gegenereerd en in een array geplaatst
{
	if (n <= 0 || min > max) return NULL;//foutafhandeling

	double* a = (double*)malloc(n * sizeof(double));//laat een array van doubles maken met de grootte n
	if (!a) return NULL;  //controleer of de geheugenallocatie gelukt is 

	for (int i = 0; i < n; i++) //hier worden de random getallen gegenereerd en in de array geplaatst
    {
		double r = (double)rand() / (double)RAND_MAX;//genereer een random getal tussen 0 en 1
		a[i] = min + r * (max - min);//schaal het getal naar het bereik [min, max]
    }
    return a;
}

void print_array(const double a[], int n) //hier worden de getallen in de array afgedrukt
{
	for (int i = 0; i < n; i++) //hier worden de getallen in de array afgedrukt
    {
		printf("%.2f ", a[i]);//druk elk getal af met 2 decimalen
    }
	printf("\n");//druk een nieuwe regel na het afdrukken van de array
}

int main(void) 
{
	srand((unsigned)time(NULL));//initialiseer de random generator met de huidige tijd als zaad

    int n;
    double lo, hi;

	printf("Hoeveel getallen? ");//vraag de gebruiker om het aantal getallen in te voeren
	if (scanf("%d", &n) != 1 || n <= 0) return 1;//controleren of de invoer geldig is en of n positief is

	printf("Voer ondergrens en bovengrens in: ");//vraag de gebruiker om de ondergrens en bovengrens in te voeren
	if (scanf("%lf %lf", &lo, &hi) != 2 || lo > hi) return 1;//controleren of de invoer geldig is en of lo niet groter is dan hi


	double* a1 = gen_random_array(n, lo, hi);//genereer de eerste array met random getallen
	double* a2 = gen_random_array(n, lo, hi);//genereer de tweede array met random getallen

	if (!a1 || !a2) //controleer of de geheugenallocatie voor beide arrays gelukt is
    {
        free(a1);
        free(a2);
        printf("Fout bij geheugentoewijzing.\n");
        return 1;
    }

    printf("\nArray 1:\n");
    print_array(a1, n);

    printf("Array 2:\n");
    print_array(a2, n);

    free(a1);
    free(a2);

    return 0;
}