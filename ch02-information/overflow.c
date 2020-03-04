#include <stdio.h>

int main() {
  // notice that this particular usage generates a warning in compiler:
  // overflow.c:7:32: warning: overflow in expression; result is -884901888 with type 'int' [-Winteger-overflow]
  //  printf("%d", 200 * 300 * 400 * 500);
  //                                 ^
  //                                 1 warning generated.
  //
  printf("%d", 200 * 300 * 400 * 500);
  return 0;
}
