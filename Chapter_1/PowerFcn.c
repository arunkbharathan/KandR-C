#include <stdio.h>
int power ();
/* test power function */
main ()
{
  int i;
  for (i = 0; i < 10; ++i)
    printf ("%6d %6d %6d\n", i, power (2, i), power (-3, i));
  return 0;
}

/* power: raise base to n-th power; n >= 0 */
/* power: raise base to n-th power; n >= 0 */
/*
(old-style version) */
power (base, n)
     int base, n;
{
  int i, p;
  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * base;
  return p;
}
