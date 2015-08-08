#include <stdio.h>
#define MAXLINE 100
/* rudimentary calculator */
main()
{
	double sum, atof(char []);
	char line[MAXLINE]="-897.6421";
	int getlyne(char line[], int max);
	sum = 0;
		printf("\t%f\n",  atof(line));
		printf("\t%d\n",  atoi(line));
	return 0;
}


double atof(char s[])
{
    double val, power;
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
    return sign * val / power;
    
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

/* atoi: convert string s to integer using atof */
int atoi(char s[])
{
double atof(char s[]);
return (int) atof(s);
}
