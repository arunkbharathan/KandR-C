#include <stdio.h>
/* count lines in input */
main()
{
int c,t;
while ((c = getchar()) != EOF)
{

    if (c == '\b')
        {printf("\\b");
        continue;}
    if (c == '\t')
        {printf("\\t");
        continue;}
    if (c == '\\')
        {
        putchar('\\');continue;}
    putchar(c);
}

}
