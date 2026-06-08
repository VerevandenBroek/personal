#include <stdio.h>

#define FRAMES 10

int main(void)
{
	int worpen_per_frame;// 2 of 3 worpen per frame
	int rolls[40];// Maximaal 3 worpen per frame, dus 30 + extra voor strikes/spares
	int rollCount = 0;// Telt het aantal worpen

	printf("Hoeveel worpen per frame (2 of 3): ");// Vraag het aantal worpen per frame
	scanf_s("%d", &worpen_per_frame);// Lees het aantal worpen per frame in

	for (int frame = 1; frame <= FRAMES; frame++)  // Loop door de frames
    {
		int resterend = 10;// Aantal resterende pins in het frame

		for (int w = 1; w <= worpen_per_frame; w++)// Loop door de worpen in het frame
        {
			int r = 0;// Variabele om het aantal omgevallen pins in de huidige worp op te slaan

            while (1)
            {
				printf("Frame %d - worp %d (0..%d): ", frame, w, resterend);// Vraag de gebruiker om het aantal omgevallen pins in te voeren
				if (scanf_s("%d", &r) == 1 && r >= 0 && r <= resterend)// Controleer of de invoer geldig is (een getal tussen 0 en het aantal resterende pins)
                    break;

				printf("Ongeldige invoer.\n");// Geef een foutmelding als de invoer ongeldig is
				while (getchar() != '\n');// Verwijder de rest van de invoer om te voorkomen dat deze de volgende invoer beïnvloedt
            }

			rolls[rollCount++] = r;// Sla het aantal omgevallen pins op in de rolls array
			resterend -= r;// Verminder het aantal resterende pins met het aantal omgevallen pins

			if (resterend == 0)// Als alle pins zijn omgevallen, vul de resterende worpen in het frame met 0 en ga naar het volgende frame
            {
				for (int k = w + 1; k <= worpen_per_frame; k++)// Loop door de resterende worpen in het frame
                {
					rolls[rollCount++] = 0;// Vul de resterende worpen in het frame met 0
                }
                break;
            }
        }
    }
	//
    int score = 0;
    for (int i = 0; i < rollCount; i++)
        score += rolls[i];

    printf("\nTOTALE SCORE: %d\n", score);

    return 0;
}