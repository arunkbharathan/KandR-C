#include<stdio.h>
#include<string.h>

void reverse(char s[]);

int main()
{
	char s[]=",  -2382";
	reverse(s);
	printf("\nReverse string = %s\n",s);
	return 0;
}

void reverse(char *s)
{
	int c;
	char *v = s + strlen(s) -1;
	for (; s < v; s++, v--) {
		c = *s,*s = *v,*v = c;
		}
}
