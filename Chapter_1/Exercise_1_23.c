/*Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.*/
#include <stdio.h>
#define MAXLINE 4000


int getlyne (char line_input[], int lim);
int rmcomment (char input[], char output[], int k, int len);
int c2 = 0;
main ()
{

  char input[MAXLINE], output[MAXLINE];
  int index[100];
  int len = 0, c = 0, i = 0, j = 0, k = 0;
  for (i = 0; i < 100; i++)
    index[i] = -1;
  while ((len = getlyne (input, MAXLINE)) > 0)
    {
      if (len > MAXLINE)
	{
	  printf
	    ("\nLine length %d larger than MAXLINE %d.\nIncrease array limit. \n\nProgram output not correct",
	     len, MAXLINE);
	  break;
	}


      k = rmcomment (input, output, k, len);








    }
  output[k] = '\0';
  printf ("\n%s\n", output);
  return 0;
}


int
getlyne (char s[], int lim)
{
  int c, i;

  for (i = 0; (c = getchar ()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
    {
      s[i] = c;
      ++i;
    }
  s[i] = '\0';
  return i;
}

int
rmcomment (char input[], char output[], int k, int len)
{
  int i = 0, j = 0, a = 0, d = 0, c1 = 0, alr = 0, n = 0;
  char x, y;
  extern int c2;
  if (c2 == 1)
    {
      alr = 1;
    }
  for (i = 0; i < len; i++)
    {

      y = input[i];

      if (y == '\'' && x != '\\' && d == 0 && c1 == 0 && c2 == 0 && alr == 0)
	{
	  a++;
	  a = a % 2;
	}
      if (y == '"' && x != '\\' && a == 0 && c1 == 0 && c2 == 0 && alr == 0)
	{
	  d++;
	  d = d % 2;
	}
      if (x == '/' && y == '/' && a == 0 && d == 0 && c2 == 0 && alr == 0)
	{
	  c1++;
	  c1 = c1 % 2;
	  input[i - 1] = '\n';
	  input[i] = '\0';
	  break;
	}
      if (x == '/' && y == '*' && a == 0 && d == 0 && c1 == 0 && alr == 0)
	{
	  c2++;
	  c2 = c2 % 2;
	  j = i - 1;
	}
      if (x == '*' && y == '/' && c2 == 1)
	{
	  c2++;
	  c2 = c2 % 2;
	  alr = 0;
	  for (n = j; n <= i; n++)
	    {
	      input[n] = ' ';
	    }
	}

      x = y;
    }
  if (c2 == 1)
    {
      input[j] = '\n';
      input[j + 1] = '\0';
    }



  i = 0;


  while (input[i] != '\0')
    {
      output[k] = input[i];
      k++;
      i++;
    }

  return k;
}
