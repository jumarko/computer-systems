#include <stdio.h>
#include <limits.h>

/* Checks whether two's-complement addition will NOT overflow */
int tadd_ok(int x, int y) {
  int sum = x + y;
  // first checks there's no negative overflow (sum > 0), then there's no positive overflow (sum < 0)
  // Notice that (for 4-bit numbers) -8 -8 = -16 + 16 = 0 
  //   => so the negative overflow check has to be sum >= 0 (not just sum > 0)
  return (sum >= 0 && (x > 0 || y > 0)) 
      || (sum < 0 && (x < 0 || y < 0));
}

int tsub_ok(int x, int y) {
  return tadd_ok(x, -y);
}

void print_result(x, y) {
  printf("\ntsub_ok: %s", tsub_ok(x, y) == 0 ? "FALSE" : "TRUE");
  printf("\nx: %d", x);
  printf("\ny: %d", y);
  printf("\nSum: %d\n", x - y);
}

int main() {
  print_result(INT_MAX, 1);

  print_result(INT_MAX, INT_MAX);

  print_result(INT_MIN, 1);

  print_result(INT_MIN, -1);

  // THIS IS INCORRECT!
  // in fact, any time y is INT_MIN and x negative, the function tsub_okk should return 1.
  // tsub_ok: FALSE
  // x: -2147483648
  // y: -2147483648
  // Sum: 0
  print_result(INT_MIN, INT_MIN);
// why this prints  -2147483648 ??
// => because INT_MIN is special: it is its own "additive inverse" - see book p. 131
  // -INT_MIN=-2147483648
  // -(INT_MIN+1)=2147483647% 
  printf("\n-INT_MIN=%d", -(INT_MIN));
  printf("\n-(INT_MIN+1)=%d", -(INT_MIN+1));
}
