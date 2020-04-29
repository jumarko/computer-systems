#include <stdio.h>
#include <limits.h>

/* Determine whether arguments can be multiplied without overflow */
int tmult_ok(int x, int y) {
  int p = x * y;
  // either x is zero, or dividing p by x gives y
  return !x || p/x == y;
}

int main() {
  printf("\nINT_MAX * INT_MAX = %d", INT_MAX * INT_MAX);
  printf("\nINT_MIN * INT_MIN = %d", INT_MIN * INT_MIN);
  printf("\nINT_MAX * 2 = %d", INT_MAX * 2);
}
