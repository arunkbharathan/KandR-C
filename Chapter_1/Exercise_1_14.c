/*Write a program to print a histogram of the frequencies of different characters
in its input.*/
#include <stdio.h>
/* count digits, white space, others */

main ()
{
  int c, i;
  int nchara[128], holdindex[128];
  int pwords[128], dots[128];

  for (i = 0; i < 128; ++i)
    nchara[i] = 0;
  while ((c = getchar ()) != EOF)
    if (c >= ' ' && c <= '~')
      ++nchara[c];
  c = 0;
  for (i = 0; i < 128; ++i)
    {
      if (nchara[i] > 0)
	{
	  holdindex[c] = i;
	  c++;
	}
    }

/*
for (i = 0; i < 36; ++i)
printf(" %2d", nchara[i]);
putchar('\n');
for (i = 0; i < 36; ++i)
printf("  %c",('a'+i));           */

  putchar ('\n');



  int sum = 0;
  int count = 0;
  for (i = 0; i < 128; ++i)
    {
      pwords[i] = nchara[i] - 100;
    }
  while ((count - 100) < 0)
    {
      for (i = 0; i < c; ++i)
	{
	  if (pwords[holdindex[i]] >= 0)
	    dots[i] = '*';
	  else
	    dots[i] = ' ';

	  sum += dots[i];

	}

      if (sum > (c * 32))
	{
	  for (i = 0; i < c; ++i)
	    printf ("  %c", dots[i]);
	  putchar ('\n');
	}
      sum = 0;
      count++;
      for (i = 0; i < 128; ++i)
	{
	  pwords[i]++;
	}
    }

  for (i = 0; i < c; ++i)
    printf ("  %c", (holdindex[i]));

  putchar ('\n');
/*
for (i = 0; i < c; ++i)
printf("  %c",(nchara[(holdindex[i])]));
*/

  putchar ('\n');
  return 0;
}
