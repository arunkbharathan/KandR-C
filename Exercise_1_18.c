
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


        for(i=len;i>=0;i--)
        {
           if(input[i]=='\n')
              {index[c]=i;c++;}
        }
        index[c]=0;
             for(i=0;i<=c+1;i++)
             printf("%d==>%d\n",i,index[i]);
 putchar('\n');
        for(i=0;i<c;i++)
      {  for(j=index[i]-1;j>index[i+1]+1;j--)
        {  /*putchar(input[j]);*/
            if(input[j] > ' ')
                {

                continue;
                }
            else if((input[j] == ' ') || (input[j] == '\t') )
            {
                input[j]='\0';
             /*   putchar(j);*/

            }

        }
        putchar('\n');
        }

    /*    putchar('\n');
        for(i=0;i<len;i++)
            putchar(input[i]);*/

for(i=0;i<len;i++)
{putchar(input[i]);}



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

