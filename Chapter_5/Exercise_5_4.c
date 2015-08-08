/*Exercise 5-4. Write the function strend(s,t) , which returns 1 if the string t occurs at the
end of the string s , and zero otherwise.*/
#include <stdio.h>
#include <string.h>

int strend(const char *, const char *);

int main()
{
	char s[200],t[100];

	printf("\nEnter String1 : ");
	scanf("%s",s);getchar();
	printf("\nEnter String2 : ");
	scanf("%s",t);getchar();

	if(strend(s,t))
		printf("\nNot found at end\n");
	else
		printf("\nFound at the end\n");
	
	return 0;
}

int strend(const char *a,const char *b)
{
	int i = strlen(a) - strlen(b);
        a = a + i;
	while(*a++ == *b++)
		if (*a == '\0')
			return 0;
	return 1;
	
}
