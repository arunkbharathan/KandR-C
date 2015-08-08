//Write a program to print all input lines that are longer than 80 characters.
#include <stdio.h>
#define MAXLINE 1000
#define ABOVE 8			/* print above "ABOVE" number of characters */
int getlyne (char line_input[], int lim);

main ()
{
  printf ("\nTo quit after use press Ctrl-D 2 times.\n\n");
  char input[MAXLINE];
  int len = 0, count = 0, i = 0, j = 0;
  while ((len = getlyne (input, MAXLINE)) > 0)
    {
      if (len > MAXLINE)
	{
	  printf
	    ("\nLine length %d larger than MAXLINE %d.\nIncrease array limit. \n\nProgram output not correct",
	     len, MAXLINE);
	  break;
	}
      for (i = 0; i < len; i++)
	{
	  if (input[i] != '\n')
	    count++;
	  else
	    {
	      putchar ('\n');
	      if (count >= ABOVE)
		for (j = i - count; j < i; ++j)
		  {
		    putchar (input[j]);
		  }
	      count = 0;
	      putchar ('\n');
	    }
	}
    }
  return 0;
}

int
getlyne (char line_input[], int lim)
{
  int i;
  char c;
  for (i = 0; (c = getchar ()) != EOF; ++i)
    line_input[i] = c;

  line_input[i] = '\0';

  return i;
}
