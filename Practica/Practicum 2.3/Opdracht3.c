#include <stdio.h>
#include <string.h>
#include <ctype.h>

#pragma warning(disable : 4996)

int isNummer(const char* s)
{
	int i = 0;

	if (s[0] == '\0') return 0;//leeg string is geen nummer

	while (s[i] != '\0') //controleert elk karakter tot het einde van de string
	{
		if (!isdigit(s[i])) return 0;//als een karakter geen cijfer is, is het geen nummer
		i++;
	}
	return 1;
}

int main(void)
{
	char buffer[100];
	char key[50];
	char value[50];

	printf("Voer iets in (bijv. \"Temperatuur : 24\"): ");//prompt voor invoer
	scanf(" %99[^\n]", buffer);//skipt whitespace, leest max 99 tekens of tot newline (spaties, dubbele punten, tekst, etc.)

	if (sscanf(buffer, " %49[^:] : %49s", key, value) != 2)//lees max 49 tekens voor key tot aan dubbele punt, : --> verwacht dubbele punt, negeer spaties rondom, en lees daarna max 49 tekens voor value
	{
		printf("Fout: invoer niet in juiste formaat.\n");
		return 1;
	}
	
	printf("Key = \"%s\"\n", key);//print de key
	printf("Value = \"%s\"\n", value);//print de value

	if (strcmp(key, "Temperatuur") == 0)//controleert of de key "Temperatuur" is
	{
		while (!isNummer(value))//controleert of de value een nummer is, zo niet, blijf vragen om invoer
		{
			printf("Fout: waarde moet een nummer zijn. Voer opnieuw in: ");
			scanf(" %49s", buffer);//leest opnieuw de invoer voor de value

			if (sscanf(buffer, " %49[^:] : %49s", key, value) != 2)//probeert opnieuw de key en value te lezen, verwacht nog steeds hetzelfde formaat
			{
				printf("Fout: invoer niet in juiste formaat.\n");
				return 1;
			}
		}
		printf("Temperatuur is numeriek: %s\n", value);//print dat de temperatuur geldig is
	}


	if (strcmp(key, "Brandstof") == 0) //controleert of de key "Brandstof" is
	{

		if (strcmp(value, "benzine") == 0 ||//controleert of de value een van de geldige brandstoffen is
			strcmp(value, "diesel") == 0 ||
			strcmp(value, "kerosine") == 0 ||
			strcmp(value, "LPG") == 0)
		{
			printf("Brandstof is geldig: %s\n", value);//print dat de brandstof geldig is
		}
		else 
		{
			printf("Ongeldige brandstof!\n");//print dat de brandstof ongeldig is
		}
	}

	return 0;

}
