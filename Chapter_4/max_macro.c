#include <stdio.h>
#define max(A, B) ((A) > (B) ? (A) : (B))
int main()
{
    int x=5,y=10;
    
    printf("\n");
    printf("Max of  %d and %d is %d",x+1,y+1,max(x+1,y+1));
       
    printf("\n");
    return 0;
}
