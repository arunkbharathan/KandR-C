/*Exercise 4-13. Write a recursive version of the function reverse(s) , which reverses the
string s in place.*/
#include<stdio.h>
#include<string.h>

void reverse(char s[]);


int main()
{
	char s[]="-2382";
	reverse(s);
	printf("\nReverse string =%s\n",s);
	return 0;
}

void reverse(char s[])
{
	static int i = 0;
	int j,t;
	j = strlen(s)-1-i;
	if(i < j)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++;
		reverse(s);
	}
}
