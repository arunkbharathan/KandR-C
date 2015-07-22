/*Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t .
(Block structure will help.)*/

#include <stdio.h>
#define swap(t, x, y) ((t)=(x));((x)=(y));((y)=(t));

int main()
{
   int t,x=5,y=10;
   printf("\nBefore Swap:%d %d\n",x,y);
   swap(t, x, y);
   printf("\nAfter Swap:%d %d\n",x,y);
   
   return 0;
}
