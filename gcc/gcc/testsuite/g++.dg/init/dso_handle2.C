// PR c++/58846
// { dg-options "-fuse-cxa-atexit" }
// { dg-require-effective-target cxa_atexit }

extern "C" { char* __dso_handle; }

struct A
{
  ~A();
};

A a;  // { dg-error "conflicting declaration" }
