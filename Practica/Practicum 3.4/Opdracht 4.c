#pragma warning(disable : 4996)   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int  id;
    char naam[20];
    char opleiding[10];
} teamlid;

int generatieId(void) // Genereert een uniek ID voor elk teamlid
{
	static int teller = 1000;   // Startwaarde voor ID's
	return teller++;// Verhoogt de teller na elke oproep
}

void vul_team(teamlid* team, int n) // Vul het team met gegevens van de gebruiker
{
	for (int i = 0; i < n; i++) // Loop door elk teamlid
    {
		team[i].id = generatieId();// Genereer een uniek ID voor het teamlid

		printf("Teamlid %d - naam: ", i);// Vraag de naam van het teamlid
		scanf("%19s", team[i].naam);      // Lees de naam in, maximaal 19 tekens + null-terminator
		printf("Teamlid %d - opleiding: ", i);// Vraag de opleiding van het teamlid
		scanf("%9s", team[i].opleiding);    // Lees de opleiding in, maximaal 9 tekens + null-terminator
    }
}

void print_team(const teamlid* team, int n) // Print de gegevens van alle teamleden
{
	puts("\nID    Naam                 Opleiding");// Print de koptekst
	for (int i = 0; i < n; i++) // Loop door elk teamlid
    {
		printf("%-5d %-20s %-10s\n", team[i].id, team[i].naam, team[i].opleiding);// Print het ID, de naam en de opleiding van het teamlid in een nette indeling
    }
}

void zoek_op_opleiding(const teamlid* team, int n, const char* opleid) // Zoek en print teamleden op basis van hun opleiding
{
	int count = 0;// Teller voor het aantal gevonden resultaten
	puts("\nZoekresultaten:");// Print de koptekst voor de zoekresultaten
	for (int i = 0; i < n; i++) // Loop door elk teamlid
    {
		if (strcmp(team[i].opleiding, opleid) == 0) // Vergelijk de opleiding van het teamlid met de zoekopdracht
        {
			printf("%-5d %-20s %-10s\n", team[i].id, team[i].naam, team[i].opleiding);// Print het ID, de naam en de opleiding van het gevonden teamlid in een nette indeling
			count++;// Verhoog de teller voor gevonden resultaten
        }
    }
	if (!count) puts("(geen resultaten)");// Als er geen resultaten zijn gevonden, print een bericht dat er geen resultaten zijn
}

int voeg_teamlid_toe(teamlid** pTeam, int* pN) // Voeg een nieuw teamlid toe aan het bestaande team
{
	int nieuwAantal = *pN + 1;// Bereken het nieuwe aantal teamleden

	teamlid* nieuw = (teamlid*)realloc(*pTeam, (size_t)nieuwAantal * sizeof(teamlid));// Probeer het geheugen opnieuw te alloceren voor het nieuwe aantal teamleden
    if (!nieuw) 
    {
		puts("Herallocatie mislukt.");// Als realloc mislukt, geef een foutmelding en retourneer 0
        return 0;
    }

	*pTeam = nieuw;       // Update de pointer naar het team met de nieuwe geheugenlocatie
	(*pTeam)[*pN].id = generatieId();// Genereer een uniek ID voor het nieuwe teamlid

	printf("Nieuw teamlid - naam: ");      scanf("%19s", (*pTeam)[*pN].naam);// Vraag de naam van het nieuwe teamlid en lees deze in
	printf("Nieuw teamlid - opleiding: "); scanf("%9s", (*pTeam)[*pN].opleiding);// Vraag de opleiding van het nieuwe teamlid en lees deze in

	*pN = nieuwAantal;//    Update het aantal teamleden met het nieuwe aantal
    return 1;
}

int main(void) 
{
    int n;
	printf("Aantal teamleden: ");// Vraag het aantal teamleden van de gebruiker
	if (scanf("%d", &n) != 1 || n <= 0) // Controleer of de invoer geldig is (een positief geheel getal)
    {
		puts("Ongeldig aantal.");// Als de invoer ongeldig is, geef een foutmelding en beëindig het programma
        return 1;
    }

	teamlid* team = (teamlid*)malloc((size_t)n * sizeof(teamlid));// Probeer geheugen te alloceren voor het opgegeven aantal teamleden
	if (!team) // Controleer of de geheugenallocatie is gelukt
    {
		puts("Allocatie mislukt.");// Als de allocatie mislukt, geef een foutmelding en beëindig het programma
        return 1;
    }

	vul_team(team, n);// Vul het team met gegevens van de gebruiker
	print_team(team, n);// Print de gegevens van alle teamleden

	char query[10];// Buffer voor de zoekopdracht (opleiding)
	printf("\nZoek op opleiding: ");// Vraag de gebruiker om een opleiding om op te zoeken
	scanf("%9s", query);// Lees de zoekopdracht in, maximaal 9 tekens + null-terminator
	zoek_op_opleiding(team, n, query);// Zoek en print teamleden op basis van de opgegeven opleiding

    int keus = 0;
	printf("\nNog een teamlid toevoegen? (1 = ja, anders = nee): ");// Vraag de gebruiker of ze nog een teamlid willen toevoegen
	if (scanf("%d", &keus) == 1 && keus == 1) // Controleer of de invoer geldig is en of de gebruiker heeft gekozen om een teamlid toe te voegen
    {
		if (voeg_teamlid_toe(&team, &n)) // Probeer een nieuw teamlid toe te voegen en controleer of dit succesvol was
        {
			puts("\nTeam na toevoegen:");// Print een bericht dat het team is bijgewerkt
			print_team(team, n);// Print de gegevens van alle teamleden, inclusief het nieuwe teamlid
        }
    }

    free(team);
    return 0;
}
