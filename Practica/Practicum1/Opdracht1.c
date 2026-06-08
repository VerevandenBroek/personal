#include <stdio.h>


double bereken_belasting(double inkomen)//defineert functie met parameter (double inkomen), returntype (double)
{
	double belasting = 0.0;//start op 0.0 --> veilig optellen

	const double grens1 = 38883.0;//const: waarde mag niet veranderen
	const double grens2 = 78426.0;

	const double tarief1 = 0.3575;//double geschikt voor nauwkeurig rekenen
	const double tarief2 = 0.3756;
	const double tarief3 = 0.4950;

	if (inkomen <= grens1)//inkomen kleiner of gelijk aan grens1
	{
		belasting = inkomen * tarief1;//vermenigvuldigen met tarief1
	}
	else if (inkomen <= grens2)//inkomen groter dan grens1 maar kleiner of gelijk aan grens2
	{
		belasting = grens1 * tarief1;//eerste deel van belasting berekenen
		belasting += (inkomen - grens1) * tarief2;//deel boven grens1 berekenen en optellen bij belasting
	}
	else
	{
		belasting = grens1 * tarief1;//eerste deel van belasting berekenen
		belasting += (grens2 - grens1) * tarief2;//deel tussen grens1 en grens2 berekenen en optellen bij belasting
		belasting += (inkomen - grens2) * tarief3;//deel boven grens2 berekenen en optellen bij belasting
	}
	return belasting;//moet double teruggeven
}

int main(void)
{
	double inkomen;//variabele voor inkomen

	printf("Voer uw inkomen in:");//regel voor gebruiker
	if (scanf_s("%lf", &inkomen) != 1)//%lf --> double willen inlezen, &inkomen --> adres van variabele doorgeven, scanf_s retourneert aantal succesvol gelezen items, als dat niet 1 is, is er een fout
	{
		fprintf(stderr, "Ongeldige invoer.\n");//fprintf: zelf kiezen waarheen je print, stderr: standaard foutuitvoer, foutmelding
		return 1;//programma met foutcode 1 beëindigen
	}

	double b = bereken_belasting(inkomen);
	printf("De totale inkomstenbelasting is: %.2f euro\n", b);
	return 0;//programma succesvol beëindigen
}