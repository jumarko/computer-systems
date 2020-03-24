#include <stdio.h>
#include <limits.h>

// my original implementation
int tadd_ok(int x, int y) {
  int sum = x + y;
  // first checks there's no negative overflow (sum > 0), then there's no positive overflow (sum < 0)
  // Notice that (for 4-bit numbers) -8 -8 = -16 + 16 = 0 
  //   => so the negative overflow check has to be sum >= 0 (not just sum > 0)
  return (sum >= 0 && (x > 0 || y > 0)) 
      || (sum < 0 && (x < 0 || y < 0));
}

// new suggested shorter impl => correct?
int tadd_ok2(int x, int y) {
  int sum = x + y;
  // this doesn't work because x+y - x = y ALWAYS HOLDS (two's-complement addition forms Abelian group)
  return (sum-x == y) && (sum-y == x);
}

void print_result(int x, int y, int (*f)(int, int)) {
  printf("\ntadd_ok: %s", f(x, y) == 0 ? "FALSE" : "TRUE");
  printf("\nx: %d", x);
  printf("\nSum: %d\n", x + y);
}

int main() {
  // tadd_ok: FALSE
  // x: 2147483647
  // Sum: -2147483648% 
  print_result(INT_MAX, 1, &tadd_ok);

  // tadd_ok: FALSE
  // x: 2147483647
  // Sum: -2
  print_result(INT_MAX, INT_MAX, &tadd_ok);

  // tadd_ok: TRUE
  // x: -2147483648% 
  // Sum: -2147483647% 
  print_result(INT_MIN, 1, &tadd_ok);

  // tadd_ok: FALSE
  // x: -2147483648% 
  // Sum: 2147483647
  print_result(INT_MIN, -1, &tadd_ok);

  // tadd_ok: FALSE
  // x: -2147483648
  // Sum: 0
  print_result(INT_MIN, INT_MIN, &tadd_ok);


  printf("\n ALTERNATIVE IMPLEMENTATION ALWAYS PASSES!!! \n");


  // tadd_ok: TRUE
  // x: 2147483647
  // Sum: -2147483648% 
  print_result(INT_MAX, 1, &tadd_ok2);

  // tadd_ok: TRUE
  // x: 2147483647
  // Sum: -2
  print_result(INT_MAX, INT_MAX, &tadd_ok2);

  // tadd_ok: TRUE
  // x: -2147483648% 
  // Sum: -2147483647% 
  print_result(INT_MIN, 1, &tadd_ok2);

  // tadd_ok: TRUE
  // x: -2147483648% 
  // Sum: 2147483647
  print_result(INT_MIN, -1, &tadd_ok2);

  // tadd_ok: TRUE
  // x: -2147483648
  // Sum: 0
  print_result(INT_MIN, INT_MIN, &tadd_ok2);
}
