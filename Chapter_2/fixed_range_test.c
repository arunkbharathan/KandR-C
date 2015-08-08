#include <stdio.h>
void
main ()
{
  unsigned char u_char = 1, uct;
  unsigned short int us_int = 1, usit;
  unsigned int u_int = 1, uit;
  unsigned long int ul_int = 1, ulit;
  unsigned long long int ull_int = 1, ullit;

  signed char s_char = 1, sct;
  signed short int ss_int = 1, ssit;
  signed int s_int = 1, sit;
  signed long int sl_int = 1, slit;
  signed long long int sll_int = 1, sllit;

  int k, len = 130;
  long double cnt[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  while (uct != u_char)
    {
      uct = u_char;
      u_char = u_char << 1 | 1;
    }
  while (usit != us_int)
    {
      usit = us_int;
      us_int = us_int << 1 | 1;
    }
  while (uit != u_int)
    {
      uit = u_int;
      u_int = u_int << 1 | 1;
    }
  while (ulit != ul_int)
    {
      ulit = ul_int;
      ul_int = ul_int << 1 | 1;
    }
  while (ullit != ull_int)
    {
      ullit = ull_int;
      ull_int = ull_int << 1 | 1;
    }



  while (sllit != -1)
    {
      sll_int = sllit;
      sllit = sllit << 1 | 1;
    }
  sllit = sll_int;
  while (sct != -1)
    {
      s_char = sct;
      sct = sct << 1 | 1;
    }
  sct = s_char;
  while (ssit != -1)
    {
      ss_int = ssit;
      ssit = ssit << 1 | 1;
    }
  ssit = ss_int;
  while (sit != -1)
    {
      s_int = sit;
      sit = sit << 1 | 1;
    }
  sit = s_int;
  while (slit != -1)
    {
      sl_int = slit;
      slit = slit << 1 | 1;
    }
  slit = sl_int;

  sl_int = sll_int = s_char = ss_int = s_int = 1;

  while (sll_int > 0)
    {
      sll_int = sll_int << 1;
    }

  while (s_char > 0)
    {
      s_char = s_char << 1;
    }

  while (ss_int > 0)
    {
      ss_int = ss_int << 1;
    }

  while (s_int > 0)
    {
      s_int = s_int << 1;
    }

  while (sl_int > 0)
    {
      sl_int = sl_int << 1;
    }







  printf ("unsigned char range 0 to %d\n", u_char);
  printf ("unsigned short int range 0 to %u\n", us_int);
  printf ("unsigned int range 0 to %u\n", u_int);
  printf ("unsigned long int range 0 to %lu\n", ul_int);
  printf ("unsigned long long int range 0 to %llu\n\n", ull_int);

  printf ("signed char range %d to %d\n", s_char, sct);
  printf ("signed short int range %d to %d\n", ss_int, ssit);
  printf ("signed int range %d to %d\n", s_int, sit);
  printf ("signed long int range %ld to %ld\n", sl_int, slit);
  printf ("signed long long int range %lld to %lld\n", sll_int, sllit);

}
