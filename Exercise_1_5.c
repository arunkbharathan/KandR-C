#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20
main()
{
int fahr;
printf("Fahrenheit-Celsius table\n");
printf("------------------------\n");
for (fahr=UPPER;fahr >= LOWER;fahr=fahr-STEP)
{

printf("%3d\t %6.2f\n", fahr, (5.0/9)*(fahr-32));

}
}
