// { dg-options "-Wcatch-value=2" }
// { dg-require-effective-target exceptions_enabled }

struct A { virtual ~A() {} };
struct B : A {};
struct C {};
struct D : C {};

void foo()
{
  try {}
  catch (D)    {}  // { dg-warning "catching type" }
  catch (C)    {}  // { dg-warning "catching type" }
  catch (B)    {}  // { dg-warning "catching polymorphic type" }
  catch (A)    {}  // { dg-warning "catching polymorphic type" }
  catch (A*)   {}
  catch (int)  {}

  try {}
  catch (D&)   {}
  catch (C&)   {}
  catch (B&)   {}
  catch (A&)   {}
  catch (A*)   {}
  catch (int&) {}
}

template<typename T> void foo1()
{
  try {}
  catch (T) {}  // { dg-warning "catching" }
}

template<typename T> void foo2()
{
  try {}
  catch (T*) {}

  try {}
  catch (T&) {}

  try {}
  catch (const T&) {}
}

void bar()
{
  foo1<int&>();
  foo1<const A&>();
  foo1<B&>();
  foo1<const C&>();
  foo1<D&>();

  foo1<int>();
  foo1<A>();  // { dg-message "required" }
  foo1<B>();  // { dg-message "required" }
  foo1<C>();  // { dg-message "required" }
  foo1<D>();  // { dg-message "required" }

  foo2<int>();
  foo2<A>();
  foo2<B>();
  foo2<C>();
  foo2<D>();
}
