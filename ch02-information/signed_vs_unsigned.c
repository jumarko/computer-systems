// example from p. 106
// "suprising" conversions between signed and usngined integers
#include<stdio.h>

/* this yields:
     v = -12345, uv = 53191
     u = 4294967295, tu = -1
*/
int main() {
  short int v = -12345;
  unsigned short uv = (unsigned short) v;
  printf("v = %d, uv = %u\n", v, uv);

  unsigned u = 4294967295u; // UMax
  int tu = (int) u;
  printf("u = %u, tu = %d\n", u, tu);

  // page 111 - formatting: printf doesn't take any type information into consideration!!
  int x = -1;
  unsigned int un = 2147483638; // 2^31
  printf("x = %u = %d\n", x, x);
  printf("x = %u = %d\n", un, un);
}
