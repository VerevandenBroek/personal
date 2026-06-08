#include <stdio.h>
#pragma warning(disable:4996)

double fahrenheitNaarCelsius(double fahrenheit)
{
	return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double spanningNaarCelsius(double spanning)
{
	return -20.0 + (spanning * 20.0);
}

int leesMeetwaardesUitBestand(const char* bestandsnaam, double meetwaardes[], int maxAantal)
{
	FILE* fp = fopen(bestandsnaam, "r");
	if (fp == NULL)
	{
		return -1;
	}

	int aantal = 0;
	while (aantal < maxAantal && fscanf(fp, "%lf", &meetwaardes[aantal]) == 1)
	{
		aantal++;
	}

	fclose(fp);
	return aantal;
}

void kopieer_met_conversie(double meetwaardes[], int aantal, double (*conversieFunctie)(double))
{
	for (int i = 0; i < aantal; i++)
	{
		double origineel = meetwaardes[i];
		double geconverteerd = conversieFunctie(origineel);

		printf("Origineel: %.2f -> Geconverteerd: %.2f\n", origineel, geconverteerd);
	}
}


int main(void)
{
	double meetwaardes[100];
	int aantal;

	
	aantal = leesMeetwaardesUitBestand("fahrenheit.txt", meetwaardes, 100);
	if (aantal > 0)
	{
		printf("Fahrenheit naar Celsius:\n");
		kopieer_met_conversie(meetwaardes, aantal, fahrenheitNaarCelsius);
	}


	printf("\n");

	aantal = leesMeetwaardesUitBestand("spanning.txt", meetwaardes, 100);
	if (aantal > 0)
	{
		printf("Spanning naar Celsius:\n");
		kopieer_met_conversie(meetwaardes, aantal, spanningNaarCelsius);
	}

	return 0;
}

