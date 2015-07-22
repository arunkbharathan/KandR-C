#include <stdio.h>

#define swap(t, x, y)   {   t z;   \
                            z = y; \
                             y = x; \
                             x = z; }
                             
int main()
{
   int x=5,y=10;
   printf("\nBefore Swap:%d %d\n",x,y);
   swap(int, x, y);
   printf("\nAfter Swap:%d %d\n",x,y);
   
   return 0;
}
