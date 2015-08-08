/*Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.*/
#include<stdio.h>
#include<math.h>
unsigned int rightrot(unsigned int x, unsigned int n);
unsigned int getnum(char s[]);
#define LIM 100

int main()
{
    unsigned int x, n;

    x = getnum("\nEnter x: ");

    n = getnum("\nRotate right by: ");

    printf("Result: %u\n", rightrot(x, n));
    return 0;

}

unsigned int rightrot(unsigned int x, unsigned int n)
{
    while (n) {
	if (x % 2) {
	    x >>= 1;
	    x |= (unsigned int) ldexp(1, sizeof(x) * 8 - 1);
	} else
	    x >>= 1;
	n--;
    }
    return x;
}

unsigned int getnum(char s[])
{
    unsigned int i, n;
    n = 0;
    char s2[LIM], c;

    printf("%s", s);
    for (i = 0; i < LIM - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
	s2[i] = c;
    s2[i] = '\0';


    for (i = 0; s2[i] >= '0' && s2[i] <= '9'; ++i)
	n = 10 * n + (s2[i] - '0');

    return n;
}
