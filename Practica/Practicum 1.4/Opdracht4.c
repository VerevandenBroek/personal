#include <stdio.h>

#define FRAMES 10// Aantal frames in een bowling game

int bereken_score(int rolls[], int rollCount)// rolls[] bevat alle worpen van een speler, rollCount is het aantal worpen
{
	int score = 0;// Totale score van de speler
	int i = 0;// Index voor het bijhouden van de huidige worp in rolls[]

	for (int frame = 1; frame <= FRAMES; frame++)// Loop door elk frame
    {
        if (rolls[i] == 10)  // STRIKE
        {
			score += 10 + rolls[i + 1] + rolls[i + 2];// Score voor strike = 10 + volgende 2 worpen
			i += 1;// Bij strike ga je direct naar de volgende frame (1 worp in dit frame)
        }
        else if (rolls[i] + rolls[i + 1] == 10)  // SPARE
        {
			score += 10 + rolls[i + 2];// Score voor spare = 10 + volgende worp
			i += 2;// Bij spare ga je naar de volgende frame (2 worpen in dit frame)
        }
        else   // GEEN strike, GEEN spare
        {
			score += rolls[i] + rolls[i + 1];// Score = som van de 2 worpen in dit frame
			i += 2;// Ga naar de volgende frame (2 worpen in dit frame)
        }
    }

    return score;
}

int main(void)
{
	int spelers = 2; // Aantal spelers (kan aangepast worden)
	int rolls[30];// Array om alle worpen van een speler op te slaan (maximaal 21 worpen per speler, maar 30 is veilig)
	int rollCount = 0;// Aantal worpen dat de speler heeft gedaan

	for (int speler = 1; speler <= spelers; speler++)// Loop door elke speler
    {
		rollCount = 0;// Reset worp teller voor elke speler

        printf("\n==========================\n");
        printf("SPELER %d\n", speler);
        printf("==========================\n");

		for (int frame = 1; frame <= FRAMES; frame++)// Loop door elk frame
        {
			int r1, r2;// Variabelen voor worp 1 en worp 2

            // ---- WORP 1 ----
			while (1)// Validatie voor worp 1 (moet tussen 0 en 10 zijn)
            {
				printf("Frame %d - worp 1 (0..10): ", frame);// Vraag om invoer voor worp 1
				if (scanf_s("%d", &r1) == 1 && r1 >= 0 && r1 <= 10)// Controleer of de invoer geldig is (een getal tussen 0 en 10)
                    break;

				printf("Ongeldige invoer.\n");// Foutmelding bij ongeldige invoer
				while (getchar() != '\n');// Clear de invoerbuffer bij ongeldige invoer
            }

			rolls[rollCount++] = r1;// Sla worp 1 op in de rolls array

			if (frame == 10)// In het 10e frame zijn er speciale regels voor worp 2 en mogelijk worp 3
            {
                if (r1 == 10) // strike in frame 10
                {
                    // worp 2
					while (1)// Validatie voor worp 2 (moet tussen 0 en 10 zijn)
                    {
						printf("Frame 10 - worp 2 (0..10): ");// Vraag om invoer voor worp 2
						if (scanf_s("%d", &r2) == 1 && r2 >= 0 && r2 <= 10)// Controleer of de invoer geldig is (een getal tussen 0 en 10)
                            break;

						printf("Ongeldige invoer.\n");// Foutmelding bij ongeldige invoer
						while (getchar() != '\n');// Clear de invoerbuffer bij ongeldige invoer
                    }
					rolls[rollCount++] = r2;// Sla worp 2 op in de rolls array

                    // worp 3 afhankelijk van worp 2
					int r3, max3 = (r2 == 10 ? 10 : 10 - r2);// Als worp 2 ook een strike is, dan is worp 3 max 10, anders max (10 - r2)

                    while (1)
                    {
						printf("Frame 10 - worp 3 (0..%d): ", max3);// Vraag om invoer voor worp 3 met de juiste max waarde afhankelijk van worp 2
						if (scanf_s("%d", &r3) == 1 && r3 >= 0 && r3 <= max3)// Controleer of de invoer geldig is (een getal tussen 0 en max3)
                            break;

						printf("Ongeldige invoer.\n");// Foutmelding bij ongeldige invoer
						while (getchar() != '\n');// Clear de invoerbuffer bij ongeldige invoer
                    }
					rolls[rollCount++] = r3;// Sla worp 3 op in de rolls array
                }
                else
                {
                    // GEEN strike → worp 2 max = (10 - r1)
                    while (1)
                    {
						printf("Frame 10 - worp 2 (0..%d): ", 10 - r1);// Vraag om invoer voor worp 2 met max waarde afhankelijk van worp 1
						if (scanf_s("%d", &r2) == 1 && r2 >= 0 && r2 <= (10 - r1))// Controleer of de invoer geldig is (een getal tussen 0 en (10 - r1))
                            break;

						printf("Ongeldige invoer.\n");// Foutmelding bij ongeldige invoer
						while (getchar() != '\n');// Clear de invoerbuffer bij ongeldige invoer
                    }
					rolls[rollCount++] = r2;// Sla worp 2 op in de rolls array

					if (r1 + r2 == 10)// spare in frame 10 → worp 3
                    {
						int r3;// Worp 3 bij spare in frame 10 kan tussen 0 en 10 zijn
                        while (1)
                        {
							printf("Frame 10 - worp 3 (0..10): ");// Vraag om invoer voor worp 3 bij spare in frame 10
							if (scanf_s("%d", &r3) == 1 && r3 >= 0 && r3 <= 10)// Controleer of de invoer geldig is (een getal tussen 0 en 10)
                                break;

							printf("Ongeldige invoer.\n");// Foutmelding bij ongeldige invoer
							while (getchar() != '\n');// Clear de invoerbuffer bij ongeldige invoer
                        }
						rolls[rollCount++] = r3;// Sla worp 3 op in de rolls array
                    }
                }
            }
            else
            {
                if (r1 == 10) // strike → geen worp 2
                    continue;

                // ---- WORP 2 ---- (geen strike)
                while (1)
                {
					printf("Frame %d - worp 2 (0..%d): ", frame, 10 - r1);// Vraag om invoer voor worp 2 met max waarde afhankelijk van worp 1 (10 - r1)
					if (scanf_s("%d", &r2) == 1 && r2 >= 0 && r2 <= (10 - r1))// Controleer of de invoer geldig is (een getal tussen 0 en (10 - r1))
                        break;

					printf("Ongeldige invoer.\n");// Foutmelding bij ongeldige invoer
					while (getchar() != '\n');// Clear de invoerbuffer bij ongeldige invoer
                }

				rolls[rollCount++] = r2;// Sla worp 2 op in de rolls array
            }
        }

		int score = bereken_score(rolls, rollCount);// Bereken de totale score van de speler op basis van alle worpen

		printf("\n--- RESULTAAT SPELER %d ---\n", speler);// Print de resultaten voor de speler
		printf("Worpen (%d): ", rollCount);// Print het aantal worpen en de worpen zelf

		for (int i = 0; i < rollCount; i++)// Loop door alle worpen en print ze
			printf("%d ", rolls[i]);// Print elke worp gevolgd door een spatie

		printf("\nTotale score: %d\n", score);// Print de totale score van de speler
    }

    return 0;
}