#include <stdio.h>


int printArray(double array[], int size) //functie die een array van doubles en de grootte van de array als parameters neemt
{
	int i;
	for (i = 0; i < size; i++) //for loop die door de array loopt en elk element afdrukt met 2 decimalen
	{
		printf("%.2f ", array[i]);//%.2f zorgt ervoor dat er 2 decimalen worden afgedrukt
	}
	printf("\n");//nieuwe regel na het afdrukken van de array
	return 0;
}

int main(void)
{
	double a[5] = { 1.22, 3.45, 4.78, 8.92, 6.32 };
	double b[5] = { 2.34, 5.67, 7.89, 9.01, 3.45 };
	double c[5] = { 3.45, 6.78, 8.90, 1.23, 4.56 };
	printf("Array a: ");
	printArray(a, 5); //aanroepen van de printArray functie met array a en grootte 5
	printf("Array b: ");
	printArray(b, 5); //aanroepen van de printArray functie met array b en grootte 5
	printf("Array c: ");
	printArray(c, 5); //aanroepen van de printArray functie met array c en grootte 5
	return 0;
}

