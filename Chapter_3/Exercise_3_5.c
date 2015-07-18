/*Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s . In particular, itob(n,s,16) formats s as a
hexadecimal integer in s .*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define lim 1000
void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	int n10,base;
	char s[lim] = "";

	printf("\nEnter Integer in base 10: ");
	scanf("%d",&n10);
	printf("\nConvert to  base x: ");
	scanf("%d",&base);

	itob(n10,s,base);

	printf("\n%d in base %d is %s\n",n10,base,s);
	return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign=1;
    int c;
	if ( n < 0) /* record sign */
		sign = -1;
	/* make n positive */
	i = 0;
	do {
		/* generate digits in reverse order */
		c =  sign*(n % b);
		s[i++] =c<=9?('0'+c):(55+c); /* get next digit */
		} while (sign*(n /= b) > 0);
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
