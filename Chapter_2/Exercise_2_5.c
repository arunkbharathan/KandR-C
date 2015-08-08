/*Write the function any(s1,s2) , which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 .
(The standard library function strpbrk does the same job but returns a pointer to the
location.)*/
#include<stdio.h>
#define lim 100
int any(char s[], char q[]);

int main()
{
    char s1[lim];
    char s2[lim], c;
    int i;

    printf("\nEnter String1: ");
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
	s1[i] = c;
    s1[i] = '\0';

    printf("\nEnter Search String: ");
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
	s2[i] = c;
    s2[i] = '\0';

    printf("\n%dth\n", any(s1, s2));
    return 0;
}



int any(char s[], char q[])
{
    int i, j;
    for (i = 0; q[i] != '\0'; i++)
	for (j = 0; s[j] != '\0'; j++)
	    if (s[j] == q[i])
		return j + 1;
    return -1;

}
