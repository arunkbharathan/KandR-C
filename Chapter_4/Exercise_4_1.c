/*Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s , or -1 if there is none.*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */
int getlyne(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould";
void reverse(char s[]);
/* pattern to search for */
/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int found = 0;
	getlyne(line, MAXLINE);
	printf("\nAt Index %d\n",strindex(line, pattern) );
	found++;
			
	return found;
}

/* getlyne: get line into s, return length */
int getlyne(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;
	reverse(s);
	reverse(t);
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
		{
			reverse(s);
			reverse(t);
			return strlen(s)-i-strlen(t);
		}
		}
	reverse(s);
	reverse(t);
	return -1;
}

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i],s[i] = s[j],s[j] = c;
		}
}
