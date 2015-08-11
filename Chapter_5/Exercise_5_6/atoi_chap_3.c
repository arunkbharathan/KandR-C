#include <ctype.h>
#include<stdio.h>
/* atoi: convert s to integer; version 2 */
int atoi(char s[]);

int main()
{
	char s[]="  -2382";
	printf("\ninteger = %d\n",atoi(s));
	return 0;
}


int atoi(char s[])
	{
		int n, sign;
		for (; isspace(*s);)
			s++;
		sign = (*s  == '-') ? -1 : 1;
		if (*s == '+' || *s == '-')
			s++;
		/* skip white space */
		/* skip sign */
		for (n = 0; isdigit(*s);)
			n = 10 * n + (*s++ - '0');
		return sign * n;
	}
