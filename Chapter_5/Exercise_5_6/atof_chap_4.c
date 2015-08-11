#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 100
/* rudimentary calculator */
int atoi(char s[]);
int main()
{
	double  atof(char []);
	char line[MAXLINE]="-897.6421";
	int getlyne(char line[], int max);
	//getlyne(line, 100);
		printf("\t%f\n",  atof(line));
		printf("\t%d\n",  atoi(line));
	return 0;
}


double atof(char s[])
{
    double val, power;
    int sign;
    for (; isspace(*s);++s ) /* skip white space */
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (val = 0.0; isdigit(*s);)
        val = 10.0 * val + (*s++ - '0');
    if (*s == '.')
        s++;
    for (power = 1.0; isdigit(*s);) {
        val = 10.0 * val + (*s++ - '0');
        power *= 10;

    }
    return sign * val / power;

}

/* getlyne: get line into s, return length */
int getlyne(char s[], int lim)
{
	int c;
	char *v=s;
	
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		*s++  = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return strlen(v);
}

/* atoi: convert string s to integer using atof */
int atoi(char s[])
{
double atof(char s[]);
return (int) atof(s);
}

