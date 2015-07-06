#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
main()
{
float fahr, celsius;
float lower, upper, step;
lower = 0;
upper = 300;
step = 20;
/* lower limit of temperature scale */
/* upper limit */
/* step size */
printf("//asddede");
printf("/* dgfgdgd*/");
printf("/* dgfg\" dgd*/");
fahr = lower;
while (fahr <= upper) {
celsius = 5 * (fahr-32) / 9;
printf("%3.0f\t %6.2f\n", fahr, celsius);
fahr = fahr + step;
}
}
