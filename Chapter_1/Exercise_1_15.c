/*Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.*/
#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
float convert(float farenheit);
#define LOWER 0
#define STEP 20
#define UPPER 300
main()
{
float fahr;


/* lower limit of temperature scale */
/* upper limit */
/* step size */
fahr = LOWER;
printf("Fahrenheit-Celsius table\n");
printf("------------------------\n");
while (fahr <= UPPER) {

printf("%3.0f\t %6.2f\n", fahr,convert(fahr));
fahr = fahr + STEP;
}
return 0;
}


float convert(float farenheit)
{
    return (5.0 * (farenheit-32) / 9);
}
