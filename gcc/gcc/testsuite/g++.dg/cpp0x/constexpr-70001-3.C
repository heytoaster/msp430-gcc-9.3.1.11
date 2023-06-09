// PR c++/70001

// This is still slow to compile, only run it once.
// { dg-do compile { target c++14_only } }

#include <array>
#include <complex>

typedef std::complex<double> cd;

const int LOG = 5;
const int N = (1 << LOG);

std::array<cd, N> a;
std::array<cd, N> b;

void
foo (std::array<cd, N> &arr)
{
  std::array<std::array<cd, N>, LOG + 1> f;
}

int
main ()
{
  foo (a);
  foo (b);
}
