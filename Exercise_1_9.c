#include <stdio.h>
/* count lines in input */
main()
{
int c,d=0;

while ((c = getchar()) != EOF)
{

    if (c != ' ')
    {
        putchar(d);
    }
    d=c;
}
putchar(d);
}
