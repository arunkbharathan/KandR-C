/*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y , leaving the other bits unchanged.*/
#include<stdio.h>
#define LIM  100

unsigned long int setbits(unsigned long int x, int p, int n, unsigned long int y);
unsigned long int getnum(char s[]);

int  main()
{
	char s2[LIM],c;
	unsigned long int x,y;
	int i,p,n;
	
	x = getnum("\nEnter x: ");

	y = getnum("\nEnter y: ");

	p = getnum("\nEnter pos: ");

	n = getnum("\nEnter num of bits to take from end of y: ");

	printf("\noutput: %lu\n",setbits(x,p,n,y));

}



unsigned long int getnum(char s[])
{
	unsigned long int i, n;
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

unsigned long int setbits(unsigned long int x, int p, int n, unsigned long int y)
{

	x &= ~( (~ (~0 << n))<<(p+1-n));
	x|= (y & (~ (~0 << n)))<<(p+1-n);
	return x;
}
