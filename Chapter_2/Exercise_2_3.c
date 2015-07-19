/*Write a function htoi(s) , which converts a string of hexadecimal digits
(including an optional 0x or 0X ) into its equivalent integer value. The allowable digits are 0
through 9 , a through f , and A through F .*/

#include<stdio.h>
#include<ctype.h>
int alpha_to_digit(int);
unsigned long int htoi(char s[]);

int main()
{
  int i=0,lim=20;
  char c,s[1000];
  
  printf("\nEnter a valid HEX value= ");  
  for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
      s[i] = c;
  s[i] = '\0';
  
  printf("\nDecimal Value of hex %s is %lu\n",s,htoi(s));  
  return 0;
}


int alpha_to_digit(int c)
{
  if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))

    if (c >= 'A' && c <= 'F')
      return c + 'a' - 'A' - 87;
    else
      return c - 87;
  
  else
    
    return -1;
}

/* atoi: convert s to integer */
unsigned long int htoi(char s[])
{
  unsigned long int val=0,pos=1;
  int n,len;
  for (len = 0; s[len] != '\0'; ++len);
  len--;
  while(len >= 0)
  {
    if(isdigit(s[len]))
      n = s[len] - '0';
    else
      if((n=alpha_to_digit(s[len])) == -1)
        break;
    
    val+=n*pos;
    pos<<=4;
    len--;
  }
  return val;
}
