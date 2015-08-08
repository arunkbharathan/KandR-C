/*Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAXLINE 100
/* rudimentary calculator */
int main()
{
	double atof(char []);
	char line[MAXLINE]="-897.6421";
	int getlyne(char line[], int max);
	printf("\nEnter a floating point value in scientific notation:\n");
	getlyne(line, MAXLINE);
	printf("\n%f\n",  atof(line));
	return 0;
}


double atof(char s[])
{
    double val, power;
    int exponent,expsign;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if(s[i] == 'e' || s[i] == 'E')
	    i++;
    expsign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (exponent = 0; isdigit(s[i]); i++)
	    exponent = 10 * exponent + (s[i] - '0');

    return (sign * val / power)*pow(10,expsign*exponent);
    
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

