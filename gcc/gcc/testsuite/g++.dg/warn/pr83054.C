// PR ipa/83054
// { dg-options "-O3 -Wsuggest-final-types" }
// { dg-do compile }
// { dg-require-effective-target exceptions_enabled }

extern "C" int printf (const char *, ...);
struct foo // { dg-warning "final would enable devirtualization of 5 calls" }
{
  static int count;
  void print (int i, int j) { printf ("foo[%d][%d] = %d\n", i, j, x); }
  int x;
  foo () {
    x = count++;
    printf("this %d = %x\n", x, (void *)this);
  }
  virtual ~foo () {
    printf("this %d = %x\n", x, (void *)this);
    --count;
  }
};
int foo::count;


int main ()
{
  {
    foo array[3][3];
    for (int i = 0; i < 3; i++)
      {
	for (int j = 0; j < 3; j++)
	  {
	    printf("&a[%d][%d] = %x\n", i, j, (void *)&array[i][j]);
	  }
      }
      // The count should be nine, if not, fail the test.
      if (foo::count != 9)
	return 1;
  }
  if (foo::count != 0)
    return 1;
  return 0;
}
