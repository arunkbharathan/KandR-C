
/* 
// bitcount: count 1 bits in x 
int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}
*/
/*In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x . Explain why. Use this observation to write a faster version of bitcount .*/

#include<stdio.h>
unsigned int getnum(char s[]);
int bitcount(unsigned x);
#define LIM 100

void main()
{
	unsigned int x;

	x = getnum("\nEnter x: ");
	printf("\nBit Count: %d\n",bitcount(x));
}



unsigned int getnum(char s[])
{
	unsigned int i, n;
	n = 0;
	char s2[LIM],c;
	
	printf("%s",s);
	for (i=0; i < LIM-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		s2[i] = c;
	s2[i] = '\0';

	for (i = 0; s2[i] >= '0' && s2[i] <= '9'; ++i)
		n = 10 * n + (s2[i] - '0');
	
	return n;
}

int bitcount(unsigned x)
{
	int cnt=0;
	while(x)
	{
		cnt++;
		x&=x-1;
	}
	return cnt;
}
