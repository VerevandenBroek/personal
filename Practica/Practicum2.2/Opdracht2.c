#include <stdio.h>

int kopieerString(char* dest, int destGrootte, const char* src)//destGrootte is de grootte van de doelbuffer, inclusief de null-terminator
{
    int i = 0;

	while (src[i] != '\0') // Controleer de lengte van de bronstring
    {
        i++;
    }

	if (i + 1 > destGrootte) // +1 voor de null-terminator
    {
        return 0; 
    }

	int j = 0;// Kopieer de bronstring naar de doelbuffer
	while (src[j] != '\0') // Kopieer elk karakter totdat we de null-terminator bereiken
    {
		dest[j] = src[j];// Kopieer het karakter van de bron naar de doelbuffer
        j++;
    }

	dest[j] = '\0';// Voeg de null-terminator toe aan het einde van de doelstring
    return 1; 
}

int main(void)
{
    char bron[] = "Hallo wereld!";
    char doel[20];

    if (kopieerString(doel, 20, bron))
    {
		printf("Gelukt: %s\n", doel);// De bronstring is succesvol gekopieerd naar de doelbuffer
    }
    else
    {
		printf("Fout: Doelbuffer is te klein.\n");
    }
    return 0;
}
