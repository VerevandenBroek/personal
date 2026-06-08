#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)
#define MAX 36
#define NAAM 50

// a) Struct voor 1 wedstrijd
typedef struct 
{
    char locatie[10];      // Thuis of Uit
    int doelpuntenVoor;
    int doelpuntenTegen;
    char tegenstander[NAAM];
} Wedstrijd;

// d) Struct voor totaalresultaat
typedef struct 
{
    int aantalWedstrijden;
    int punten;
    int doelpuntenVoor;
    int doelpuntenTegen;
} Resultaat;

int main() 
{

    FILE* bestand;
    Wedstrijd wedstrijden[MAX];
    Resultaat totaal = { 0, 0, 0, 0 };

    int i = 0;

    bestand = fopen("uitslagen.txt", "r");
    if (bestand == NULL) 
    {
        printf("Kan bestand niet openen!\n");
        return 1;
    }

    // Inlezen van het bestand
    while (fscanf(bestand, "%s %d - %d %49s",
        wedstrijden[i].locatie,
        &wedstrijden[i].doelpuntenVoor,
        &wedstrijden[i].doelpuntenTegen,
        wedstrijden[i].tegenstander) == 4) 
    {

        i++;
    }

    fclose(bestand);

    totaal.aantalWedstrijden = i;

    // b) Print alle tegenstanders
    printf("Tegenstanders:\n");
    for (int j = 0; j < i; j++) 
    {
        printf("%s\n", wedstrijden[j].tegenstander);
    }

    // c) Punten en doelsaldo berekenen
    for (int j = 0; j < i; j++) 
    {

        totaal.doelpuntenVoor += wedstrijden[j].doelpuntenVoor;
        totaal.doelpuntenTegen += wedstrijden[j].doelpuntenTegen;

        if (wedstrijden[j].doelpuntenVoor > wedstrijden[j].doelpuntenTegen) 
        {
            totaal.punten += 3;
        }
        else if (wedstrijden[j].doelpuntenVoor == wedstrijden[j].doelpuntenTegen) 
        {
            totaal.punten += 1;
        }
    }

    // d) Resultaat printen
    printf("\n%d wedstrijden, %d punten en doelsaldo (%d-%d)\n",
        totaal.aantalWedstrijden,
        totaal.punten,
        totaal.doelpuntenVoor,
        totaal.doelpuntenTegen);

    // e) Zoeken op tegenstander
    char zoekNaam[NAAM];
    printf("\nVoer naam van tegenstander in: ");
    scanf("%s", zoekNaam);

    int gevonden = 0;

    for (int j = 0; j < i; j++) {
        if (strcmp(zoekNaam, wedstrijden[j].tegenstander) == 0) 
        {
            gevonden = 1;

            if (wedstrijden[j].doelpuntenVoor > wedstrijden[j].doelpuntenTegen) 
            {
                printf("Gewonnen van %s\n", zoekNaam);
            }
            else if (wedstrijden[j].doelpuntenVoor == wedstrijden[j].doelpuntenTegen) 
            {
                printf("Gelijk gespeeld tegen %s\n", zoekNaam);
            }
            else {
                printf("Verloren van %s\n", zoekNaam);
            }
        }
    }

    if (!gevonden) 
    {
        printf("Tegenstander niet gevonden.\n");
    }

    return 0;
}