#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

struct vak {
    char naam[20];
    int ECTS;
};


void vervangVakPtr(struct vak* vakken[], int index, struct vak nieuwVak)
{
    free(vakken[index]);

    vakken[index] = malloc(sizeof(struct vak));
    if (vakken[index] == NULL) {
        printf("Malloc fout in vervangVakPtr!\n");
        exit(1);
    }

    strcpy(vakken[index]->naam, nieuwVak.naam);
    vakken[index]->ECTS = nieuwVak.ECTS;
}

int main(void)
{
    struct vak* vakken[10];   
    int aantal, i;

    printf("sizeof(vakken) = %zu bytes\n", sizeof(vakken));

    printf("Hoeveel vakken wil je invoeren? (max 10) ");
    scanf("%d", &aantal);
    getchar();

    if (aantal > 10) aantal = 10;

    for (i = 0; i < aantal; i++) 
    {

        vakken[i] = malloc(sizeof(struct vak));
        if (vakken[i] == NULL) 
        {
            printf("Malloc fout!\n");
            return 1;
        }

        printf("Naam van vak %d: ", i + 1);
        fgets(vakken[i]->naam, sizeof(vakken[i]->naam), stdin);
        vakken[i]->naam[strcspn(vakken[i]->naam, "\n")] = '\0';

        printf("ECTS voor %s: ", vakken[i]->naam);
        scanf("%d", &vakken[i]->ECTS);
        getchar();
    }

    struct vak nieuw;
    strcpy(nieuw.naam, "NieuwVakPTR");
    nieuw.ECTS = 99;

    vervangVakPtr(vakken, 0, nieuw);

    printf("\nVakken (na vervanging):\n");
    for (i = 0; i < aantal; i++) 
    {
        printf("%d: %s (%d ECTS)\n",
            i + 1,
            vakken[i]->naam,
            vakken[i]->ECTS);
    }

    for (i = 0; i < aantal; i++) 
    {
        free(vakken[i]);
    }

    return 0;
}