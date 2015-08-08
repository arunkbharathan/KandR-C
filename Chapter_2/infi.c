#include<stdio.h>
long double two_raiseto_ld(unsigned int);


void main()
{
    unsigned int i;
    char bits[] =
	{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f };
    long double ld_max = *(long double *) bits;
//infinity = two_raiseto_ld(16384);
//if(infinity == two_raiseto_ld(16383))
//printf("yes");
//for(i=0;i<16;i++)
//printf("%x ",bits[i]);

    printf("\n%Lf\n", ld_max);
}


long double two_raiseto_ld(unsigned int exponent)
{
    unsigned int i = 1;
    long double temp = 1;
    while (i <= exponent) {
	temp *= 2;
	i++;
    }


    return temp;
}
