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
		int i, n, sign;
		for (i = 0; isspace(*(s + i)); i++)
			;
		sign = (*(s + i) == '-') ? -1 : 1;
		if (*(s + i) == '+' || *(s + i) == '-')
			i++;
		/* skip white space */
		/* skip sign */
		for (n = 0; isdigit(*(s + i)); i++)
			n = 10 * n + (*(s + i) - '0');
		return sign * n;
	}
