#include<stdio.h>
int test(int);
int main()
{
    printf("\n%d\n",test(5));
    return test(1);
}

int test( int k)
{
k++;
}
