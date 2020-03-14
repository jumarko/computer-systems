#include <stdio.h>

void inplace_swap(int *x, int *y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

int main() {
  int x = 10;
  int y = 100;
  inplace_swap(&x, &y);
  printf("x=%d, y=%d", x, y);
}
