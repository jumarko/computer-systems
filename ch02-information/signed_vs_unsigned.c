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
}
