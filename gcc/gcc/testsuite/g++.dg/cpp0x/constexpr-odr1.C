// PR c++/92062 - ODR-use ignored for static member of class template.
// { dg-do run { target c++11 } }
// { dg-skip-if "&x could be NULL" { keeps_null_pointer_checks } }

template<int> struct A {
  static const bool x;
  static_assert(&x, ""); // odr-uses A<...>::x
};

int g;

template<int I>
const bool A<I>::x = (g = 42, false);

void f(A<0>) {}        // A<0> must be complete, so is instantiated
int main()
{
  if (g != 42)
    __builtin_abort ();
}
