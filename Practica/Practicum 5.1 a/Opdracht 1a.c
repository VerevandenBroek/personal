#include <stdio.h>

//Functie 1: Rijen controleren (2D array als parameter)
int checkRows(int sudoku[9][9], int fouten[]) 
{
    int foutCount = 0;

    for (int r = 0; r < 9; r++) //loop loopt 9 keer (1 keer per rij)
    {
        int som = 0; //Som van de waarden in de rij wordt bij elke rij opnieuw op 0 gezet
        for (int c = 0; c < 9; c++) //c is het kolomnummer, loop loopt door alle 9 waarden in de rij
        {
            som += sudoku[r][c]; //het getal in de rij wordt bij de som opgeteld
        }
		if (som != 45) // Als de som niet 45 is, is er een fout in deze rij
        {
            fouten[foutCount++] = r + 1;   //r begint bij 0, r+ 1 geeft rijnummer 1-9, foutCount++ eerst als index, daarna verhogen met 1
        }
    }
    return foutCount;
}


// Functie 2: Kolommen controleren (single pointer!)
int checkCols(int* sudoku, int fouten[]) //pointer naar eerste element van 9x9 array
{
    int foutCount = 0;

    for (int col = 0; col < 9; col++) 
    {
        int som = 0;

        for (int row = 0; row < 9; row++) 
        {
            som += *(sudoku + row * 9 + col); //row * 9 springt naar begin van juiste rij, +col gaat naar juiste kolom binnen rij
        }

        if (som != 45) 
        {
            fouten[foutCount++] = col + 1;      // kolom nummer opslaan
        }
    }

    return foutCount;
}


// Functie 3: Blokken controleren (2D array) 
int checkBlocks(int sudoku[9][9], int fouten[]) //volledige sudoku als 2D array
{
    int foutCount = 0;

    for (int br = 0; br < 3; br++) //Er zijn 3 blokrijen
    {
        for (int bc = 0; bc < 3; bc++) //Samen bepalen bc en br welk blok wordt gecontroleerd
        {

            int som = 0;

            for (int r = 0; r < 3; r++) 
            {
                for (int c = 0; c < 3; c++) 
                {
                    som += sudoku[br * 3 + r][bc * 3 + c];
                }
            }

            if (som != 45) 
            {
                fouten[foutCount++] = br * 3 + bc + 1; // blok nummer
            }
        }
    }

    return foutCount;
}


// MAIN 
int main() 
{
    FILE* file;
    int sudoku[9][9];

    fopen_s(&file, "sudokufoutrij.txt", "r");

    if (file == NULL) 
    {
        printf("Kon sudoku.txt niet openen.\n");
        return 1;
    }

    // Inlezen
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            fscanf_s(file, "%d", &sudoku[i][j]);
        }
    }

    fclose(file);

    // Sudoku printen
    printf("Ingelezen Sudoku:\n");
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Controle Resultaten ---\n");

    int foutenR[9], foutenC[9], foutenB[9];

    int FR = checkRows(sudoku, foutenR);
    int FC = checkCols((int*)sudoku, foutenC);
    int FB = checkBlocks(sudoku, foutenB);

    // Rijen printen
    if (FR == 0) printf("Alle rijen zijn correct.\n");
    else 
    {
        printf("Foute rijen: ");
        for (int i = 0; i < FR; i++) printf("%d ", foutenR[i]);
        printf("\n");
    }

    // Kolommen printen
    if (FC == 0) printf("Alle kolommen zijn correct.\n");
    else 
    {
        printf("Foute kolommen: ");
        for (int i = 0; i < FC; i++) printf("%d ", foutenC[i]);
        printf("\n");
    }

    // Blokken printen
    if (FB == 0) printf("Alle blokken zijn correct.\n");
    else 
    {
        printf("Foute blokken: ");
        for (int i = 0; i < FB; i++) printf("%d ", foutenB[i]);
        printf("\n");
    }

    return 0;
}