#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

struct vak // Struct definitie voor een vak
{
	char naam[20];// Naam van het vak
	int  ECTS;// Aantal ECTS punten voor het vak
};

void print_vakken(const struct vak v[], int n) // Functie om de lijst van vakken af te drukken
{
	printf("Index  %-20s  ECTS\n", "Naam");// Header van de tabel
	for (int i = 0; i < n; i++) // Loop door de vakken en druk ze af
    {
		printf("%5d  %-20s  %d\n", i, v[i].naam, v[i].ECTS);// Index, naam en ECTS van elk vak
    }
}

void wijzig_vak_ptr(struct vak v[], int n) // Functie om een vak te wijzigen via pointer-variant
{
	int idx;// Index van het vak dat gewijzigd moet worden

	printf("Welk vak wil je wijzigen (0..%d)? ", n - 1);// Vraag de gebruiker om de index van het vak dat gewijzigd moet worden
	if (scanf("%d", &idx) != 1 || idx < 0 || idx >= n) // Controleer of de invoer geldig is
    {
		printf("Ongeldige index.\n");// Foutmelding bij ongeldige index
        return;
    }

	printf("Nieuwe naam: ");// Vraag de gebruiker om de nieuwe naam van het vak
	scanf("%19s", v[idx].naam);// Lees de nieuwe naam in en sla deze op in de struct
	printf("Nieuwe ECTS: ");// Vraag de gebruiker om het nieuwe aantal ECTS punten
	scanf("%d", &v[idx].ECTS);// Lees het nieuwe aantal ECTS punten in en sla deze op in de struct
}

struct vak wijzig_vak_value(struct vak course) // Functie om een vak te wijzigen via value-return variant
{
	printf("Nieuwe naam: ");// Vraag de gebruiker om de nieuwe naam van het vak
	scanf("%19s", course.naam);// Lees de nieuwe naam in en sla deze op in de struct
	printf("Nieuwe ECTS: ");// Vraag de gebruiker om het nieuwe aantal ECTS punten
	scanf("%d", &course.ECTS);// Lees het nieuwe aantal ECTS punten in en sla deze op in de struct

    return course;
}   

struct vak maak_vak_interactief(void) // Functie om een nieuw vak te maken via interactieve invoer
{
	struct vak temp;// Tijdelijke variabele om het nieuwe vak op te slaan

	printf("Naam: ");// Vraag de gebruiker om de naam van het nieuwe vak
	scanf("%19s", temp.naam);// Lees de naam in en sla deze op in de struct
	printf("ECTS: ");// Vraag de gebruiker om het aantal ECTS punten voor het nieuwe vak
	scanf("%d", &temp.ECTS);// Lees het aantal ECTS punten in en sla deze op in de struct

    return temp;
}   


int main(void) 
{

	struct vak lijst[] = {// Voorbeeldlijst van vakken
		{"C_Programmeren", 5},// Vaknaam en ECTS punten
        {"Wiskunde", 6},// Vaknaam en ECTS punten
		{"Databases", 5},// Vaknaam en ECTS punten
		{"Software_Engineering", 6},// Vaknaam en ECTS punten
		{"Algoritmen", 5}// Vaknaam en ECTS punten
    };

	int n = sizeof(lijst) / sizeof(lijst[0]);// Bereken het aantal vakken in de lijst

	printf("== Originele vakken ==\n");// Druk de originele lijst van vakken af
	print_vakken(lijst, n);// Druk de lijst van vakken af

	printf("\n== Wijzig via pointer-variant ==\n");// Druk de lijst van vakken af voordat we een wijziging aanbrengen
	wijzig_vak_ptr(lijst, n);// Wijzig een vak via pointer-variant
	print_vakken(lijst, n);// Druk de lijst van vakken af na de wijziging

	printf("\n== Wijzig via value-return variant ==\n");// Druk de lijst van vakken af voordat we een wijziging aanbrengen
	int index = 0;// Index van het vak dat gewijzigd moet worden
	printf("Index van vak dat je via value wilt wijzigen (0..%d): ", n - 1);// Vraag de gebruiker om de index van het vak dat gewijzigd moet worden
}