/* { dg-do link } */
/* { dg-skip-if "" { *-*-* } { "-mcpu=msp430" "-mdata-region=upper" "-mdata-region=either" } } */
/* { dg-options "-mlarge -mdata-region=lower -muse-lower-region-prefix" } */

#define NO_REGION_ATTRIBUTES
#include "cpux-insns.C"

char use_qi(char a)
{
  while(a);
  return a;
}

int use_hi(int a)
{
  while(a);
  return a;
}

long use_si(long a)
{
  while(a);
  return a;
}

int
main (void)
{
  while(1);
  return 0;
}

