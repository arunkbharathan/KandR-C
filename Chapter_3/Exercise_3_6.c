/*Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.*/

#include <ctype.h>
#include<stdio.h>
#include<string.h>
#define lim 1000
void reverse(char s[]);
//* itoa: convert n to characters in s */
void itoa(int n, char s[], int w);

main()
{
	int i=-2147483648;
	char s[lim]="";
	itoa(i,s,15);
	printf("\nString:%s\n",s);
	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int w )
{
	int i,j, sign=1;
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
	for(j = w-i; j > 0; j--,i++)
	       s[i] = ' ';	
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
