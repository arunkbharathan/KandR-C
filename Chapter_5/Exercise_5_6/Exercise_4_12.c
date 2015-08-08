/*Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa ; that is, convert
an integer into a string by calling a recursive routine.*/
#include <stdio.h>
void itoa(int n, char s[]);

int main()
{
	int i=-2147483648;
	char s[]="                               .";
	itoa(i,s);
	printf("\nString:%s\n",s);
	return 0;
}

void itoa(int n, char *s)
{
	static int i;
	int sign = 1;
	if(n < 0)
	{
		sign = -1;
		*(s + i++) = '-';
	}
	if(n / 10)
		itoa(sign*(n / 10), s);

	*(s + i++) = sign*(n % 10) + '0';
	*(s + i) = '\0';
}
