/*Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s .*/
#include <stdio.h>

void stringcat(char *, char *);

int main()
{
	char s[200],t[100];
	
	printf("\nEnter String1 : ");
	scanf("%s",s);
	printf("\nEnter String2 : ");
	scanf("%s",t);

	stringcat(s,t);
	printf("\nString1 + String2 : %s\n",s);
	return 0;
}

void stringcat(char *a, char *b)
{
	while(*a != '\0')
		a++;
	for(; *b != '\0'; a++,b++)
		*a = *b;
	*a = '\0';
}
