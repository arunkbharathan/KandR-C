#include <stdio.h>
/* count characters in input; 2nd version */
main()
{
double nc;
int c;
for (nc = 0; (c=getchar()) != EOF;)
{
    if (c== '\n')
    {
        ++nc;
    }
}
printf("\n%.0f\n", nc);
}
