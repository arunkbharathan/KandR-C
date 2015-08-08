/* strindex: return index of t in s, -1 if none */
#include <stdio.h>

int main()
{
    char s[200], t[100];
    int strindex(char *, char *);

    printf("\nEnter String1 : ");
    scanf("%s", s);
    getchar();
    printf("\nEnter String2 : ");
    scanf("%s", t);
    getchar();

    printf("\nResult : %d\n", strindex(s, t));
    return 0;
}


int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; *(s + i) != '\0'; i++) {
	for (j = i, k = 0; *(t + k) != '\0' && *(s + j) == *(t + k);
	     j++, k++);
	if (k > 0 && *(t + k) == '\0')
	    return i;
    }
    return -1;
}
