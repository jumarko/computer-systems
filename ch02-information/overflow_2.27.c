#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y) {
  return (x + y) >= x;
}

int main() {
  unsigned long x = ULONG_MAX;
  printf("uadd_ok: %d", uadd_ok(x, 1));
  printf("\nx: %lu", x);
  // this will print 0! 
  printf("\nSum: %lu", x + 1);
}
