
#include <stdio.h>
#define MAXLINE 1000
#define ABOVE 8  /* print above ABOVE much of characters */
int getlyne(char line_input[], int lim);
void copy(char to[], char from[]);
main()
{
    printf("\nTo quit after use press Ctrl-D 2 times.\n\n");
    char input[MAXLINE];
    int index[100];
    int len = 0,c=0,i=0,j=0;
    while((len = getlyne(input,MAXLINE)) > 0)
    {
        if(len>MAXLINE)
        {
            printf("\nLine length %d larger than MAXLINE %d.\nIncrease array limit. \n\nProgram output not correct",len,MAXLINE);
            break;
        }

index[0]=0;j=1;
        for(i = 0; i<len; i++)
           {
           if(input[i] == '\n')
                    {

                        index[j] = i; j++;}

                    }

                    for(i=0 ; i<j; i++)
        {
        for(c=index[i]; c<index[i] ; c++)
           {
                if(input[index[i]-c] > ' ')
                continue;

           else if((input[index[i]-c]) == ' '  || (input[index[i]-c]) == '\t')
                input[index[i]-c] = '\0';
                }


        }


break;
    }
    return 0;
}

int getlyne(char line_input[], int lim)
{
    int i;
    char c;
    for(i=0 ; (c=getchar()) != EOF ; ++i )
        line_input[i] = c;

    line_input[i] = '\0';

    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
int i;
i = 0;
while ((to[i] = from[i]) != '\0')
++i;
}
