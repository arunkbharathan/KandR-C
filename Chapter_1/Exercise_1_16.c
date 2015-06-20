/*Revise the main routine of the longest-line program so it will correctly print the
length of arbitrary long input lines, and as much as possible of the text.*/
#include <stdio.h>
#define MAXLINE 10
/* maximum input line length */
int getlyne(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input*/
main()
{
int len;

int max;

char line[MAXLINE];
char longest[MAXLINE];

max = 0;
while ((len = getlyne(line, MAXLINE)) > 0)
{
if(len>MAXLINE)
{printf("\nLine length %d larger than MAXLINE %d.\nIncrease array limit. \n\nProgram output not correct",len,MAXLINE);
break;}
if (len > max) {
max = len;
copy(longest, line);
}
}
if (max > 0) /* there was a line */
printf("\nLongest is %s", longest);
return 0;
}

int getlyne(char s[],int lim)
{
int c, i;

for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
s[i] = c;
if (c == '\n') {
s[i] = c;
++i;
}
s[i] = '\0';



return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
int i;
i = 0;
while ((to[i] = from[i]) != '\0')
++i;
}
