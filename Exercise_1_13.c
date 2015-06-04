#include <stdio.h>
#define IN 1
#define OUT 0

/* inside a word */
/* outside a word */
/* count lines, words, and characters in input */
main()
{
int c ,state ,i , count;
state = OUT;
count = 0;
int nwords[16] ,pwords[16] ,dots[16];
for (i = 0; i < 16; ++i)
nwords[i] = 0;
for (i = 0; i < 16; ++i)
dots[i] = ' ';
while ((c = getchar()) != EOF) {

if (c == ' ' || c == '\n' || c == '\t')
{state = OUT;
 nwords[count]++;
}
else if (state == OUT) {
state = IN;
count = 0;
}
if(state == IN)
count++;
else
count=0;


}
int sum = 0;
count = 0;
for (i = 0; i < 16; ++i)
{
pwords[i] = nwords[i] - 100;
}
while ((count-100) < 0)
{
for (i = 0; i < 16; ++i)
{ if( pwords[i] >= 0)
   dots[i]= '*';
   else
   dots[i]= ' ';

sum += dots[i];

}

if(sum > 512)
{
for (i = 0; i < 16; ++i)
    printf("%2c ",dots[i]);
putchar('\n');
}
sum = 0;
count++;
for (i = 0; i < 16; ++i)
{
pwords[i]++;
}
}

for (i = 0; i < 16; ++i)
printf("%2d ",i);

putchar('\n');
}
