#include <ctype.h>
#include<stdio.h>
#include<string.h>
void reverse(char s[]);
//* itoa: convert n to characters in s */
void itoa(int n, char s[]);

int main()
{
	int i=-2147483647;
	char s[]="";
	itoa(i,s);
	printf("\nString:%s\n",s);
	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char *s)
{
	int  sign;
	char *v = s;
	if ((sign = n) < 0) /* record sign */
		n = -n;
	/* make n positive */
	
	do {
		/* generate digits in reverse order */
		*s++ = n % 10 + '0'; /* get next digit */
		} while ((n /= 10) > 0);
	/* delete it */
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(v);
}




void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i],s[i] = s[j],s[j] = c;
		}
}
