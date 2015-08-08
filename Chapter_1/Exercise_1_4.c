//Write a program to print the corresponding Celsius to Fahrenheit table.
#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
/* lower limit of temperature scale */
/* upper limit */
/* step size */
    celsius = lower;
    printf("Celsius-Fahrenheit table\n");
    printf("------------------------\n");
    while (celsius <= upper) {
	fahr = celsius * 9 / 5 + 32;
	printf("%3.0f\t %6.2f\n", celsius, fahr);
	celsius = celsius + step;
    }
    return 0;
}
