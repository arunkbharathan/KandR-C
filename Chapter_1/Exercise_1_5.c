/*Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0.*/
#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20
int main()
{
    int fahr;
    printf("Fahrenheit-Celsius table\n");
    printf("------------------------\n");
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {

	printf("%3d\t %6.2f\n", fahr, (5.0 / 9) * (fahr - 32));

    }
    return 0;
}
