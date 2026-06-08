#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genereer_random(int min, int max)
{
    return rand() % (max - min + 1) + min;//geeft willekeurig getal, % is de modulus operator, geeft de rest van de deling, +min verschuift het bereik, zodat het tussen min en max valt
}

int main(void)
{
    int min, max;//gebruiker kiest onder- en bovengrens
    int secret;//het te raden geheime getal
    int gok;//de gok van de speler
    int guesses[20];//array voor maximaal 20 gokjes
    int beurt = 0;//teller voor het aantal beurten
    int max_beurten = 5;//aantal toegestane pogingen
    char opnieuw = 'j';//gebruikt om nogmaals spelen bij te houden


	srand((unsigned)time(NULL));//initialiseert de random generator met de huidige tijd, zodat we elke keer een ander getal krijgen

    do
    {
		printf("Kies ondergrens: ");//gebruiker kiest ondergrens
		scanf_s("%d", &min);//%d leest een int, &min geeft het adres van de variabele min door, zodat scanf_s de waarde kan opslaan

        printf("Kies bovengrens: ");
        scanf_s("%d", &max);

        secret = genereer_random(min, max);//functieaanroep

        printf("Ik heb een getal gekozen tussen %d en %d. Raad het!\n", min, max);

        beurt = 0;//beurtenteller resetten

		while (beurt < max_beurten)//zolang het aantal beurten minder is dan het maximum aantal beurten
        {
            printf("Beurt %d: ", beurt + 1);
			if (scanf_s("%d", &gok) != 1)//controleert of de invoer een geldig getal is, als dat niet het geval is, geeft het een foutmelding en stopt het programma
            {
                printf("Ongeldige invoer.\n");
                return 1;
            }

			guesses[beurt] = gok;//gok opslaan in de array op de index van de huidige beurt
            beurt++;

            if (gok < secret)
            {
                printf("Hoger!\n");
            }
            else if (gok > secret)
            {
                printf("Lager!\n");
            }
            else
            {
                printf("Goed geraden!\n");
                break;
            }
        }

        printf("\nJe gokjes waren:\n");
		for (int i = 0; i < beurt; i++)//loopt door de array van gokjes tot het aantal beurten, en print elk gokje
        {
			printf("%d ", guesses[i]);//%d print een int, guesses[i] geeft het gokje op de index i in de array
        }
        printf("\n");

		printf("Nogmaals spelen? (j/n): ");//vraagt de gebruiker of hij nogmaals wil spelen, en leest de invoer in de variabele opnieuw
		scanf_s(" %c", &opnieuw, 1);//%c leest een char, &opnieuw geeft het adres van de variabele opnieuw door, zodat scanf_s de waarde kan opslaan, 1 is de grootte van de buffer voor de char

	} while (opnieuw == 'j');//als de gebruiker 'j' invoert, begint het spel opnieuw

    return 0;
}