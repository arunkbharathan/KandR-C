#include<stdio.h>

void
main ()
{
  unsigned char u_char = 1;
  unsigned short int us_int = 1;
  unsigned int u_int = 1;
  unsigned long int ul_int = 1;
  unsigned long long int ull_int = 1;
  int k, len = 130;
  unsigned int cnt[5] = { 0, 0, 0, 0, 0 };
  for (k = 0; k < len; k++)
    {
      if (u_char)
	cnt[0]++;
      if (us_int)
	cnt[1]++;
      if (u_int)
	cnt[2]++;
      if (ul_int)
	cnt[3]++;
      if (ull_int)
	cnt[4]++;

      u_char <<= 1;
      us_int <<= 1;
      u_int <<= 1;
      ul_int <<= 1;
      ull_int <<= 1;
    }

  printf ("unsigned char = %u bits\n", cnt[0]);
  printf ("unsigned short int = %u bits\n", cnt[1]);
  printf ("unsigned int = %u bits\n", cnt[2]);
  printf ("unsigned long int = %u bits\n", cnt[3]);
  printf ("unsigned long long int = %u bits\n", cnt[4]);

}
