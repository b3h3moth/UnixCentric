#include <stdio.h>
char* Bits(char c);
int AmBigEndian();
  /* create a segment of static memory with the right data */
  char a[4] = {'A','B','C','D'};
/* function main ------------------------------------------- */
int main()
{
  char* b = a;            /* b points to the beginning of a */
  short* s = (short*) s;  /* s points to the beginning of a */
  int* p = (int*) a;      /* p points to the beginning of a */
  float* f = (float*) a;  /* f points to the beginning of a */
  if (AmBigEndian())
    printf("I am big endian\n");
  else
    printf("I am little endian\n");
  /* show the data as a sequence of bits */
  printf("%s",Bits(a[0]));
  printf("%s",Bits(a[1]));
  printf("%s",Bits(a[2]));
  printf("%s",Bits(a[3]));
  putchar('\n');
  /* show the data as 4 characters */
  printf("'%c','%c','%c','%c'\n",*b,*(b+1),*(b+2),*(b+3));
  /* show the data as 2 short integers */
  printf("%d,%d\n",*s,*(s+1));
  /* show the data as 1 integer */
  printf("%d\n",*p);
  /* show the data as 1 float */
  printf("%f\n",*f);
   return 0;
}/*end main*/
/* function Bits ------------------------------------------- */
char* Bits(char c)
{
   static char ret[9];
   int i;
   i = (int) c;
   if (!AmBigEndian()) i=i>>24;
    ret[0] = ((c&128) == 128)+'0';
    ret[1] = ((c&64) == 64)+'0';
    ret[2] = ((c&32) == 32)+'0';
    ret[3] = ((c&16) == 16)+'0';
    ret[4] = ((c&8) == 8)+'0';
    ret[5] = ((c&4) == 4)+'0';
    ret[6] = ((c&2) == 2)+'0';
    ret[7] = ((c&1) == 1)+'0';
    ret[8] = '\0';
   return ret;
}/* end Bits */
/* function AmBigEndian ------------------------------------ */
int AmBigEndian()
{
  long x = 1;
  return !(*((char *)(&x)));
}/* end AmBigEndian */
