#include <stdio.h>

double bereken_gemiddelde(double cijfers[], int aantal)//functie om gemiddelde te berekenen
{
	double som = 0.0;//variabele om de som van de cijfers bij te houden

	for (int i = 0; i < aantal; i++)//loop om door alle cijfers te itereren
    {
		som += cijfers[i];//cijfer toevoegen aan de som
    }

	return som / aantal;//gemiddelde berekenen door de som te delen door het aantal cijfers
}

int tel_te_lage_cijfers(double cijfers[], int aantal)//functie om het aantal te lage cijfers te tellen
{
	int count = 0;//variabele om het aantal te lage cijfers bij te houden

	for (int i = 0; i < aantal; i++)//loop om door alle cijfers te itereren
    {
		if (cijfers[i] < 5.5)//controleer of het cijfer lager is dan 5.5
        {
			count++;//verhoog de teller als het cijfer te laag is
        }
    }
    return count;
}

int tel_vieren(double cijfers[], int aantal)//functie om het aantal vieren te tellen
{
	int count = 0;//variabele om het aantal vieren bij te houden

	for (int i = 0; i < aantal; i++)//loop om door alle cijfers te itereren
    {
		if (cijfers[i] == 4.0)//controleer of het cijfer gelijk is aan 4.0
        {
            count++;
        }
    }
    return count;
}

int main(void)
{
	const int aantal = 6;//constante voor het aantal cijfers
	double cijfers[6];//array om de cijfers op te slaan
	double input;//variabele om de gebruikersinvoer op te slaan
	int ingevuld = 0;//variabele om bij te houden hoeveel cijfers al zijn ingevuld

	while (ingevuld < aantal)//loop om cijfers in te voeren totdat het gewenste aantal is bereikt
    {
		printf("Voer cijfer %d in: ", ingevuld + 1);//prompt voor de gebruiker om een cijfer in te voeren

		if (scanf_s("%lf", &input) != 1)//controleer of de invoer geldig is (een double)
        {
			printf("Ongeldige invoer, probeer opnieuw.\n");//foutmelding voor ongeldige invoer
            while (getchar() != '\n'); // buffer leegmaken
            continue;
        }

		if (input < 1.0 || input > 10.0)//controleer of het cijfer binnen het geldige bereik ligt
        {
			printf("Cijfer moet tussen 1 en 10 liggen.\n");//foutmelding voor cijfers buiten het bereik
            continue;
        }

		cijfers[ingevuld] = input;//sla het geldige cijfer op in de array
        ingevuld++;
    }

	double gem = bereken_gemiddelde(cijfers, aantal);//bereken het gemiddelde van de ingevoerde cijfers
	int te_laag = tel_te_lage_cijfers(cijfers, aantal);//tel het aantal te lage cijfers
	int vieren = tel_vieren(cijfers, aantal);//tel het aantal vieren

	printf("\nGemiddelde: %.2f\n", gem);//toon het gemiddelde met 2 decimalen
	printf("Aantal onvoldoendes (< 5.5): %d\n", te_laag);//toon het aantal te lage cijfers
	printf("Aantal vieren: %d\n", vieren);//toon het aantal vieren

	if (gem >= 7.5 && te_laag == 0)//controleer of het gemiddelde 7.5 of hoger is en er geen te lage cijfers zijn
    {
		printf("Behaald MET LOF.\n");//uitkomst voor zeer goed resultaat
    }
	else if (gem >= 5.5 && vieren <= 1)//controleer of het gemiddelde 5.5 of hoger is en er maximaal 1 vier is
    {
		printf("Behaald.\n");//uitkomst voor voldoende resultaat
    }
    else
    {
        printf("Niet behaald.\n");
    }

    return 0;
}