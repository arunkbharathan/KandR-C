#include <stdio.h>
#define square(A) ((A)*(A))
int main()
{
    int x=5;
    
    printf("\n");
    printf("Square of  %d is %d",x,square(x));
       
    printf("\n");
    return 0;
}
int sqr(int A)
{
    return A*A;
}
