/*Write a program to determine the ranges of char , short , int , and long
variables, both signed and unsigned , by printing appropriate values from
standard headers and by direct computation. Harder if you compute them:
determine the ranges of the various floating-point types.*/

#include<math.h> #include<limits.h> #include<stdio.h> #include<float.h>

float two_raiseto_f(unsigned int); double two_raiseto_d(unsigned
int); long double two_raiseto_ld(unsigned int); void float_max(); void
double_max(); void float_min(); void long_double_max(); void double_min();
void fixed_range(); int header_limits_range(); int header_float_range();
void main() {
   printf("\nFixed Point\n"); printf("____________\n\n");
  printf("\nBy Calculation.\n\n"); fixed_range();
   printf("\nFrom limits.h\n\n");
  header_limits_range(); printf("\nFloating Point");
  printf("\n________________\n\n"); printf("\nBy Calculation.\n\n");
  float_max(); float_min(); double_max(); double_min(); long_double_max();

   printf("\nFrom float.h\n\n");
 header_float_range();





}



void float_max() {
     float flt=1,temp,sum;

  unsigned int len=10000,cnt=0,i,exponent=0;

  for(i=0;i<len;i++) {
    //printf("%d=%f\n",i,flt); flt*=2;

    if(isinf(flt)) {
      exponent = i; sum = temp; break;
    }
      temp=flt;
  }


  for(i=exponent;i>=0;i--) {

      while(!isinf(temp)) {
        sum=temp; temp+=two_raiseto_f(i); cnt++; if(cnt>1000)
            break;
      }
       temp=sum; if(cnt>1000)
            break;
       cnt=0;
  }

  //printf("\nfloat max almost \n\n%f\n",sum); printf("\nFloat max
  %.10e\n",sum);
}

void double_max() {
      //DOUBLE
  double flt=1,temp,sum;

  unsigned int len=10000,cnt=0,i,exponent=0;

  for(i=0;i<len;i++) {
    //printf("%d=%f\n",i,flt); flt*=2;

    if(isinf(flt)) {
      exponent = i; sum = temp; break;
    }
      temp=flt;
  }


  for(i=exponent;i>=0;i--) {

      while(!isinf(temp)) {
        sum=temp; temp+=two_raiseto_d(i); cnt++; if(cnt>1000)
            break;
      }
       temp=sum; if(cnt>1000)
            break;
       cnt=0;
  }

  //printf("\ndouble max almost \n\n%f\n",sum); printf("\nDouble max
  %0.10e\n",sum);
}



float two_raiseto_f(unsigned int exponent) {
  unsigned int i=1; float temp=1; temp = pow(2,exponent);

  return temp;
}

double  two_raiseto_d(unsigned int exponent) {
  unsigned int i=1; double temp=1;

  temp = pow(2,exponent);

  return temp;
}

void long_double_max() {
      //DOUBLE
  long double flt=1,temp,sum; long double infinity =
  two_raiseto_ld(16384); unsigned int len=100000,cnt=0,i,exponent=0;

  for(i=0;i<len;i++) {
    //printf("%d=%f\n",i,flt); flt*=2;

    if(flt==infinity) {
      exponent = i; sum = temp; break;
    }
      temp=flt;
  }


    /*char bits[]= {0xff, 0xff, 0xff, 0xff, 0xff ,0xff ,0xff ,0xff ,0xfe
    ,0x7f}; long double infinity =*(long double*)bits;*/

  printf("\nlong double max  2^(%u)",exponent); printf(" or \na little
  above 10^(4932)\n"); printf("and min is 2^-16382 (Wiki Search)\n\n");
} long double  two_raiseto_ld(unsigned int  exponent) {
  unsigned int i=1; long double temp=1; while(i<=exponent) {
    temp*=2; i++;
  }


  return temp;
}

void float_min() {
    char bits[]= {0xff,0xff,0x7f,0x00}; float smallest=*(float*)bits;
    printf("\nFloat min %.10e\n",smallest);



}

void double_min() {
    char bits[]= {0xff,0xff,0xff,0xff,0xff,0xff,0x0F,0x00}; double
    smallest=*(double*)bits; printf("\nDouble min %.10e\n",smallest);

}

void fixed_range() {
  unsigned char u_char=1,uct; unsigned short int us_int=1,usit; unsigned
  int  u_int=1,uit; unsigned long int ul_int=1,ulit; unsigned long long
  int ull_int=1,ullit;

  signed char s_char=1,sct; signed short int ss_int=1,ssit; signed
  int  s_int=1,sit; signed long int sl_int=1,slit; signed long long
  int sll_int=1,sllit;

  int k,len=130; long double cnt[10]={0,0,0,0,0,0,0,0,0,0};

      while(uct!=u_char) {
          uct = u_char; u_char=u_char<<1|1;
      } while(usit!=us_int) {
          usit = us_int; us_int=us_int<<1|1;
      } while(uit!=u_int) {
          uit = u_int; u_int=u_int<<1|1;
      } while(ulit!=ul_int) {
          ulit = ul_int; ul_int=ul_int<<1|1;
      } while(ullit!=ull_int) {
          ullit = ull_int; ull_int=ull_int<<1|1;
      }



      while(sllit!=-1) {
          sll_int = sllit; sllit=sllit<<1|1;
      }
  sllit = sll_int;
      while(sct!=-1) {
          s_char = sct; sct=sct<<1|1;
      }
  sct = s_char;
      while(ssit!=-1) {
          ss_int = ssit; ssit=ssit<<1|1;
      }
  ssit = ss_int;
      while(sit!=-1) {
          s_int = sit; sit=sit<<1|1;
      }
  sit = s_int;
      while(slit!=-1) {
          sl_int = slit; slit=slit<<1|1;
      }
  slit = sl_int;

  sl_int=sll_int=s_char=ss_int=s_int=1;

      while(sll_int>0) {
         sll_int=sll_int<<1;
      }

      while(s_char>0) {
          s_char=s_char<<1;
      }

      while(ss_int>0) {
          ss_int=ss_int<<1;
      }

      while(s_int>0) {
          s_int=s_int<<1;
      }

      while(sl_int>0) {
          sl_int=sl_int<<1;
      }







      printf("unsigned char range 0 to %d\n",u_char); printf("unsigned
      short int range 0 to %hu\n",us_int); printf("unsigned int range 0 to
      %u\n",u_int); printf("unsigned long int range 0 to %lu\n",ul_int);
      printf("unsigned long long int range 0 to %llu\n\n",ull_int);

      printf("signed char range %d to %d\n",s_char,sct); printf("signed
      short int range %hi to %hi\n",ss_int,ssit); printf("signed int
      range %i to %i\n",s_int,sit); printf("signed long int range %li
      to %li\n",sl_int,slit); printf("signed long long int range %lli
      to %lli\n",sll_int,sllit);

}


int header_limits_range() {



      printf("unsigned char range 0 to %d\n",UCHAR_MAX); printf("unsigned
      short int range 0 to %u\n",USHRT_MAX); printf("unsigned int
      range 0 to %u\n",UINT_MAX); printf("unsigned long int range 0
      to %lu\n",ULONG_MAX); printf("unsigned long long int range 0 to
      %llu\n\n",ULLONG_MAX);

      printf("signed char range %d to %d\n",SCHAR_MIN,SCHAR_MAX);
      printf("signed short int range %d to %d\n",SHRT_MIN,SHRT_MAX);
      printf("signed int range %d to %d\n",INT_MIN,INT_MAX);
      printf("signed long int range %ld to %ld\n",LONG_MIN,LONG_MAX);
      printf("signed long long int range %lld to
      %lld\n",LLONG_MIN,LLONG_MAX);



   return(0);
}

int header_float_range() {
   printf("The maximum value of float = %.10e\n", FLT_MAX); printf("The
   minimum value of float = %.10e\n", FLT_MIN);

   printf("The maximum value of double = %.10e\n", DBL_MAX); printf("The
   minimum value of double = %.10e\n", DBL_MIN);

   printf("The maximum value of long double = %.10Le\n", LDBL_MAX);
   printf("The minimum value of long double = %.10Le\n", LDBL_MIN);

   return(0);


}
