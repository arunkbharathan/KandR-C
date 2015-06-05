
#include <stdio.h>
#define MAXLINE 1000

int getlyne(char line_input[], int lim);

main()
{

    char input[MAXLINE];
    int index[100];
    int len = 0,c=0,i=0,j=0;
    for(i=0;i<100;i++)
    index[i]=-1;
    while((len = getlyne(input,MAXLINE)) > 0)
    {
        if(len>MAXLINE)
        {
            printf("\nLine length %d larger than MAXLINE %d.\nIncrease array limit. \n\nProgram output not correct",len,MAXLINE);
            break;
        }

index[0]=0;c=1;
        for(i=0;i<len;i++)
        {
           if(input[i]=='\n')
              {index[c]=i;c++;}
        }
        for(j=1;j<c;++j)
        { putchar('\n');
        for(i=index[j]-1;i>=(index[j-1]+1);i--)
            putchar(input[i]);
            if(j==1)
            putchar(input[index[j-1]]);
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

