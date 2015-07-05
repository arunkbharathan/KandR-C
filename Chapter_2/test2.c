#include<math.h>
#include<stdio.h>

float two_raiseto_f(unsigned int);
double two_raiseto_d(unsigned int);
long double two_raiseto_ld(unsigned int);
void float_max();
void double_max();
void float_min();
void long_double_max();
void double_min();
void main()
{
  float_max();
  float_min();
  double_max();
  double_min();
  long_double_max();
 
  
  
  

    
}



void float_max()
{
     float flt=1,temp,sum;
   
  unsigned int len=10000,cnt=0,i,exponent=0;
  
  for(i=0;i<len;i++)
  {
    //printf("%d=%f\n",i,flt);
    flt*=2;
    
    if(isinf(flt))
    {
      exponent = i;
      sum = temp;
      break;
    }
      temp=flt;
  }
  
  
  for(i=exponent;i>=0;i--)
  {   
      
      while(!isinf(temp))
      {
        sum=temp;
        temp+=two_raiseto_f(i);
        cnt++;
        if(cnt>1000)
            break;
      }
       temp=sum;
       if(cnt>1000)
            break;
       cnt=0;
  }

  printf("\nfloat max almost \n\n%f\n",sum);
  printf("or \n%e\n",sum);
}

void double_max()
{
      //DOUBLE
  double flt=1,temp,sum;
   
  unsigned int len=10000,cnt=0,i,exponent=0;
  
  for(i=0;i<len;i++)
  {
    //printf("%d=%f\n",i,flt);
    flt*=2;
    
    if(isinf(flt))
    {
      exponent = i;
      sum = temp;
      break;
    }
      temp=flt;
  }
  
  
  for(i=exponent;i>=0;i--)
  {   
      
      while(!isinf(temp))
      {
        sum=temp;
        temp+=two_raiseto_d(i);
        cnt++;
        if(cnt>1000)
            break;
      }
       temp=sum;
       if(cnt>1000)
            break;
       cnt=0;
  }

  printf("\ndouble max almost \n\n%f\n",sum);
  printf("or \n%e\n",sum);
}



float two_raiseto_f(unsigned int exponent)
{
  unsigned int i=1;
  float temp=1;
  temp = pow(2,exponent);
  
  return temp;
}

double  two_raiseto_d(unsigned int exponent)
{
  unsigned int i=1;
  double temp=1;

  temp = pow(2,exponent);
  
  return temp;
}

void long_double_max()
{
      //DOUBLE
  long double flt=1,temp,sum;
  long double infinity = two_raiseto_ld(16384); 
  unsigned int len=100000,cnt=0,i,exponent=0;
  
  for(i=0;i<len;i++)
  {
    //printf("%d=%f\n",i,flt);
    flt*=2;
    
    if(flt==infinity)
    {
      exponent = i;
      sum = temp;
      break;
    }
      temp=flt;
  }
  
  
    /*char bits[]= {0xff, 0xff, 0xff, 0xff, 0xff ,0xff ,0xff ,0xff ,0xfe ,0x7f};
    long double infinity =*(long double*)bits;*/

  printf("\nlong double max a little above 2^(%u)\n\n",exponent);
  printf("or \na little above 10^(4931)\n");
}
long double  two_raiseto_ld(unsigned int  exponent)
{
  unsigned int i=1;
  long double temp=1;
  while(i<=exponent)
  {
    temp*=2;
    i++;
  }
  
  
  return temp;
}

void float_min()
{
    char bits[]= {0xff,0xff,0x7f,0x00};
    float smallest=*(float*)bits;
    printf("\nfloat min %e\n",smallest);
    
   
 
}

void double_min()
{
    char bits[]= {0xff,0xff,0xff,0xff,0xff,0xff,0x0F,0x00};
    double smallest=*(double*)bits;
    printf("\ndouble min %e\n",smallest);
    
   
 
}
