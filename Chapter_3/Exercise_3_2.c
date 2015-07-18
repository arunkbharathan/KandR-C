/*Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s . Use a switch . Write a
function for the other direction as well, converting escape sequences into the real characters.*/

#include <stdio.h>
#define lim 1000
void escape(char s[],char t[]);
void deescape(char u[],char s[]);

main() /* count digits, white space, others */
{
	int i;
	char c,s[lim]="",t[lim]="",u[lim]="";
		
	printf("\nEnter a string with tabs and newlines:\n");
	for (i=0; i < lim-1 && (c=getchar()) != EOF; ++i)
		t[i] = c;
	t[i--] = '\0';

	escape(s,t);
	printf("\n%s\n",s);
	deescape(u,s);
	printf("\n%s\n",u);

	return 0;
}

void escape(char s[], char t[])
{
	int i=0,k=0;

	for(i=0; t[i] != '\0'; k++, i++)
	{
		switch(t[i])
		{
			case '\n':
				s[k] = '\\';
				s[++k] = 'n';
				break;

			case '\t':
				s[k] = '\\';
				s[++k] = 't';
				break;

			default:
				s[k] = t[i];
				break;
		}
	}
	s[k] = '\0';
}

void deescape(char u[], char s[])
{
	int i=0,k=0;

	for(i=0; s[i] != '\0'; k++, i++)
	{
		switch(s[i])
		{
			case '\\':
				switch(s[++i])
				{
					case 'n':
						u[k] = '\n';
						break;
					case 't':
						u[k] = '\t';
						break;
					default :
						u[k] = '\\';
						u[++k] = s[i];
						break;
				}
				break;				
			default:
				u[k] = s[i];
				break;
		}
	}
	u[k] = '\0';
}
