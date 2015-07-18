/*Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2 . Allow for letters of either case
and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z . Arrange that a
leading or trailing - is taken literally.*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define lim 1000
void expand(char s1[],char s2[]);

main()
{
	int i;
	char c,s1[lim]="",s2[lim]="";
		
	printf("\nEnter a string with a-z,0-9 etc..:\n");
	for (i=0; i < lim-1 && (c=getchar()) != EOF; ++i)
		s1[i] = c;
	s1[i--] = '\0';

	expand(s1,s2);
	printf("\n%s\n",s2);
	return 0;
}

void expand(char s1[],char s2[])
{
	int i,k;
	char c;
	for(i=0,k=0; s1[i] != '\0'; i++,k++)
	{
		if(s1[i] == '-' && (s1[i-1] != s1[i+1]) )
		{
			if(isdigit(s1[i-1]) && isdigit(s1[i+1]))
			
				if(s1[i-1]<s1[i+1])
				{
					for(c=s1[i-1]+1 ;c != s1[i+1];c++,k++)
						s2[k] = c;
					s2[k] = s1[++i];			
				}
				else
				{
					for(c=s1[i-1]-1 ;c != s1[i+1];c--,k++)
						s2[k] = c;
					s2[k] = s1[++i];	
				}

			else if(islower(s1[i-1]) && islower(s1[i+1]))
				if(s1[i-1]<s1[i+1])
				{
					for(c=s1[i-1]+1 ;c != s1[i+1];c++,k++)
						s2[k] = c;
					s2[k] = s1[++i];			
				}
				else
				{
					for(c=s1[i-1]-1 ;c != s1[i+1];c--,k++)
						s2[k] = c;
					s2[k] = s1[++i];	
				}
			

			else if(isupper(s1[i-1]) && isupper(s1[i+1]))
				if(s1[i-1]<s1[i+1])
				{
					for(c=s1[i-1]+1 ;c != s1[i+1];c++,k++)
						s2[k] = c;
					s2[k] = s1[++i];			
				}
				else
				{
					for(c=s1[i-1]-1 ;c != s1[i+1];c--,k++)
						s2[k] = c;
					s2[k] = s1[++i];	
				}
			else
				s2[k] = s1[i];
		}
		else
			s2[k] = s1[i];

	}
	s2[k] = '\0';
}
