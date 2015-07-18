/*Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2 wordsize-1 ). Explain why not.
Modify it to print that value correctly, regardless of the machine on which it runs.*/

#include <ctype.h>
#include<stdio.h>
#include<string.h>
#define lim 1000
void reverse(char s[]);
//* itoa: convert n to characters in s */
void itoa(int n, char s[]);

main()
{
	int i=-2147483648;
	char s[lim]="";
	itoa(i,s);
	printf("\nString:%s\n",s);
	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign=1;
	if ( n < 0) /* record sign */
		sign = -1;
	/* make n positive */
	i = 0;
	do {
		/* generate digits in reverse order */
		s[i++] = sign*(n % 10) + '0'; /* get next digit */
		} while (sign*(n /= 10) > 0);
	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}




void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i],s[i] = s[j],s[j] = c;
		}
}
