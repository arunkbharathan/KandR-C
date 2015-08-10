/*Exercise 5-5. Write versions of the library functions strncpy , strncat , and strncmp , which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s . Full descriptions are in Appendix B.*/

#include <stdio.h>
void stringncat(char *, const char *, int);
void stringncpy(char *, const char *, int);
int stringncmp(const char *, const char *, int);

int main()
{
	char s[200],t[100];
	int n;

	printf("\nEnter String1 : ");
	scanf("%s",s);getchar();
	printf("\nEnter String2 : ");
	scanf("%s",t);getchar();
	printf("\nAtmost how many characters : ");
	scanf("%d",&n);
		
//	stringncat(s, t, n);
//	printf("\nConcatenated : %s",s);
	stringncpy(s, t, n);
	printf("\nCopied string2 to above result : %s\n",s);

//	printf("Result : %d\n",stringncmp(s, t, n));
		
	return 0;
}

void stringncat(char *a, const char *b, int i)
{
	while(*a != '\0')
		a++;
	for(; *b != '\0' && i > 0; a++, b++, i--)
		*a = *b;
	*a = '\0';

}

void stringncpy(char *a, const char *b, int j)
{
	while ((*a = *b) && j > 1)
	{
		a++;
		b++;
		j--;
	}
	*++a = '\0'; 

}

int stringncmp(const char *s, const char *t, int k)
{
	for ( ; *s == *t; s++, t++, k--)
		if (*s == '\0' || k == 0)
			return 0;
	return *s - *t;
}
