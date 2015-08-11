/* strindex: return index of t in s, -1 if none */
#include <stdio.h>
#include <stddef.h>

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
    ptrdiff_t  j;
    char *Ss,*St;
    Ss = s;
    St = t;
    for (; *s != '\0';s++) {
    
	for (j = 0, t = St; *t != '\0' && *(s+j) == *t;j++,t++)
        ;
	if (t-St > 0 && *t == '\0')
	    return s-Ss;
    }
    return -1;
}
