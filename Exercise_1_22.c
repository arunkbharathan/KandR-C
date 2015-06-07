#include <stdio.h>
#define MAXLINE 4000
#define CPL 20  //coloumn per line

int getlyne(char line_input[], int lim);
int fold(char input[],char output[],int k,int len);
main()
{

    char input[MAXLINE],output[MAXLINE];
    int index[100];
    int len = 0,c=0,i=0,j=0,k=0;
    for(i=0;i<100;i++)
    index[i]=-1;
    while((len = getlyne(input,MAXLINE)) > 0)
    {
        if(len>MAXLINE)
        {
            printf("\nLine length %d larger than MAXLINE %d.\nIncrease array limit. \n\nProgram output not correct",len,MAXLINE);
            break;
        }
        if(len < CPL)
        {printf("\n%s",input);break;}

 k=fold(input,output,k,len);








}
output[k]='\0';
printf("\n%s",output);
return 0;
    }


int getlyne(char s[],int lim)
{
int c, i;

for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
s[i] = c;
if (c == '\n') {
s[i] = c;
++i;
}
s[i] = '\0';
return i;
}

int fold(char input[],char output[],int k,int len)
{
    int j=0,i=0,t=0,n=0,s=0,b=0,cpos=0;char y;
    for(i=CPL;i<len;i+=CPL)
{
        if(input[i] == ' ' || input[i] == '\t'|| input[i] == '\n')
            {input[i] = '\n';}
        else
            {
                while(input[i] > ' ')
                {
                    i--;
                }
                input[i]='\n';
            }


}


for(i=k;t<(len-1);i++)
{
    if(i>k)
        t=i-k;
    else
        t=k-i;
    output[i] = input[t];

        }
    k=t+k;
return k+1;
}

