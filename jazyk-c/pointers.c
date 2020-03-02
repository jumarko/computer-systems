#include <stdio.h>

int main() {
  int a = 8;
  int *pa = &a;
  printf("hello, world");

  printf("\na = %d", a);
  printf("\n*pa = %d", *pa);
  printf("\n*(&a) = %d", *(&a));

  printf("\npa = %d", pa);
  printf("\n&a = %d", &a);

  printf("\n&pa = %d", &pa);

  // notice that not all invalid access leads to segmentation faults!
  // this will likely print 0
  printf("\n%d", *(pa - 1000));
}
