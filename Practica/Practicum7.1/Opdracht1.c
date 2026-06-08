#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct studieResultaat
{
	int id;
	char vak[12];
	int ECTS;
	double cijfer;
};

int compareOpVaknaam(const void *a, const void *b)
{
	struct studieResultaat srA = *(struct studieResultaat *)a;
	struct studieResultaat srB = *(struct studieResultaat *)b;

	return strcmp(srA.vak, srB.vak);
}

int compareOpECTSenVak(const void* a, const void* b)
{
	struct studieResultaat srA = *(struct studieResultaat *)a;
	struct studieResultaat srB = *(struct studieResultaat *)b;

	if (srA.ECTS < srB.ECTS)
		return -1;
	if (srA.ECTS > srB.ECTS)
		return 1;

	return strcmp(srA.vak, srB.vak);
}

int compareOpCijfer(const void* a, const void* b)
{
    struct studieResultaat srA = *(struct studieResultaat *)a;
    struct studieResultaat srB = *(struct studieResultaat *)b;
    if (srA.cijfer < srB.cijfer)
        return 1;
    if (srA.cijfer > srB.cijfer)
        return -1;
	return strcmp(srA.vak, srB.vak);
}

int main(void)
{
    struct studieResultaat resultaten[] = {
        {1, "Wiskunde",      5, 7.5},
        {2, "Programmeren", 6, 8.2},
        {3, "Netwerken",    5, 6.8},
        {4, "Nederlands",   4, 7.0}
    };

    int aantal = sizeof(resultaten) / sizeof(resultaten[0]);

    /* 1️ Sorteren op vaknaam */
    qsort(resultaten,
        aantal,
        sizeof(struct studieResultaat),
        compareOpVaknaam);

    printf("Gesorteerd op vaknaam:\n");
    for (int i = 0; i < aantal; i++)
    {
        printf("ID: %d | Vak: %-12s | ECTS: %d | Cijfer: %.1f\n",
            resultaten[i].id,
            resultaten[i].vak,
            resultaten[i].ECTS,
            resultaten[i].cijfer);
    }

    printf("\n");

    /* 2️ Sorteren op ECTS, bij gelijk op vaknaam */
    qsort(resultaten,
        aantal,
        sizeof(struct studieResultaat),
        compareOpECTSenVak);

    printf("Gesorteerd op ECTS en bij gelijk op vaknaam:\n");
    for (int i = 0; i < aantal; i++)
    {
        printf("ID: %d | Vak: %-12s | ECTS: %d | Cijfer: %.1f\n",
            resultaten[i].id,
            resultaten[i].vak,
            resultaten[i].ECTS,
            resultaten[i].cijfer);
    }

    /* 3️ Sorteren op cijfer (aflopend) */
    qsort(resultaten,
        aantal,
        sizeof(struct studieResultaat),
        compareOpCijfer);

    printf("Gesorteerd op cijfer (hoog naar laag):\n");
    for (int i = 0; i < aantal; i++)
    {
        printf("ID: %d | Vak: %-12s | ECTS: %d | Cijfer: %.1f\n",
            resultaten[i].id,
            resultaten[i].vak,
            resultaten[i].ECTS,
            resultaten[i].cijfer);
    }
    
    return 0;
}

