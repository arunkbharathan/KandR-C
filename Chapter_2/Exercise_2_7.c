/*Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/
#include<stdio.h>
#define LIM  100

unsigned long int invert(unsigned long int x, int p, int n); 
unsigned long int getnum(char s[]);

int  main()
{
	char s2[LIM],c;
	unsigned long int x,y;
	int i,p,n;
	
	x = getnum("\nEnter x: ");

	p = getnum("\nEnter pos: ");

	n = getnum("\nEnter num of bits: ");

	printf("\noutput: %lu\n",invert(x,p,n));

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

unsigned long int invert(unsigned long int x, int p, int n)
{

	x^=  ((~ (~0 << n))<<(p+1-n));
	return x;
}
