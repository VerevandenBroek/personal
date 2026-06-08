#include <stdio.h>

void kopieerString(char* dest, const char* src)// dest is de bestemming, src is de bron
{
	int i = 0;//

	while (src[i] != '\0')//zolang geen einde van string bereikt
	{
		dest[i] = src[i];//kopieer karakter van bron naar bestemming
		i++;//volgende karakter
	}

	dest[i] = '\0';//eindkarakter toevoegen aan bestemming
}

int main(void)
{
	char bron[] = "Hallo";// bronstring die gekopieerd moet worden
	char doel[20];// doelstring waar de bron naartoe gekopieerd wordt, voldoende ruimte voor de bron

	kopieerString(doel, bron);//

	printf("Bron: %s\n", bron);// toon de bronstring
	printf("Doel: %s\n", doel);// toon de doelstring

	return 0;
}