// PR c++/88482
// { dg-do compile }
// { dg-require-effective-target exceptions_enabled }

extern "C" void __cxa_throw (void *, void *, void (*) (void *));
int __cxa_get_exception_ptr;		// { dg-error "declared incorrectly" }
extern "C" void *__cxa_begin_catch (void *);
extern "C" void __cxa_end_catch ();
extern "C" void __cxa_rethrow ();
extern "C" void *__cxa_allocate_exception (__SIZE_TYPE__);
int __cxa_free_exception;		// { dg-error "declared incorrectly" }

struct S { S (); S (const S &); ~S (); };

int
foo (int x)
{
  if (x > 27)
    throw 19;
  try
    {
      if (x > 15)
	throw S ();
    }
  catch (S s)
    {
      throw;
    }
  return x + 3;
}
