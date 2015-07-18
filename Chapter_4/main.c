#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getlyne(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould";
/* pattern to search for */
/* find all lines matching pattern */
void main()
{
	char line[MAXLINE];
	int found = 0;
	while (getlyne(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
			}
	return found;
}
