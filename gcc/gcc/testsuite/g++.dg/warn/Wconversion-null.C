// { dg-do link  }
// { dg-options "-Wconversion -Wno-conversion-null -Wno-pointer-arith" }

#include <cstddef>

void g(__INTPTR_TYPE__) {}
extern void g(void*);

template <int I>
void h() {}

void k(int) {}

template <class T>
void l(T);

template <>
void l(__INTPTR_TYPE__) {}

int main()
{
  int i = NULL; //  converting NULL to non-pointer type
  float z = NULL; //  converting NULL to non-pointer type
  int a[2];

  i != NULL; //  NULL used in arithmetic
  NULL != z; //  NULL used in arithmetic
  k != NULL; // No warning: decay conversion
  NULL != a; // Likewise.
  -NULL;     //  converting NULL to non-pointer type
  +NULL;     //  converting NULL to non-pointer type
  ~NULL;     //  converting NULL to non-pointer type
  a[NULL] = 3; //  converting NULL to non-pointer-type
  i = NULL;  //  converting NULL to non-pointer type
  z = NULL;  //  converting NULL to non-pointer type
  k(NULL);   //  converting NULL to int
  g(NULL);   //  converting NULL to int
  h<NULL>(); // No warning: NULL bound to integer template parameter
  l(NULL);   //  converting NULL to int
  NULL && NULL; // No warning: converting NULL to bool is OK
}
