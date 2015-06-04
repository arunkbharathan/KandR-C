#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
main()
{
int fahr;
printf("Fahrenheit-Celsius table\n");
printf("------------------------\n");
for (fahr=300;fahr >= 0;fahr=fahr-20)
{

printf("%3d\t %6.2f\n", fahr, (5.0/9)*(fahr-32));

}
}
