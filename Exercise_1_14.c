#include <stdio.h>
/* count digits, white space, others */

main()
{
int c, i;
int nchara[36],pwords[36],dots[36];

for (i = 0; i < 36; ++i)
nchara[i] = 0;
while ((c = getchar()) != EOF)
if (c >= 'a' && c <= 'z')
++nchara[c-'a'];
else if (c >= 'A' && c <= 'Z')
++nchara[c-'A'];
else if (c >= '0' && c <= '9')
++nchara[26+c-'0'];

/*
for (i = 0; i < 36; ++i)
printf(" %2d", nchara[i]);
putchar('\n');
for (i = 0; i < 36; ++i)
printf("  %c",('a'+i));           */

putchar('\n');



int sum = 0;
int count = 0;
for (i = 0; i < 36; ++i)
{
pwords[i] = nchara[i] - 100;
}
while ((count-100) < 0)
{
for (i = 0; i < 36; ++i)
{ if( pwords[i] >= 0)
   dots[i]= '*';
   else
   dots[i]= ' ';

sum += dots[i];

}

if(sum > 1152)
{
for (i = 0; i < 36; ++i)
    printf("  %c",dots[i]);
putchar('\n');
}
sum = 0;
count++;
for (i = 0; i < 36; ++i)
{
pwords[i]++;
}
}

for (i = 0; i < 26; ++i)
printf("  %c",('a'+i));
for (i = 0; i < 10; ++i)
printf("  %c",('0'+i));

putchar('\n');
}
