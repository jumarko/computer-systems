#include <stdio.h>

// fill in the following macro definitions
// you cannot use any include files such as math.h
// note that largest finite number represented by double is around 1.8x10^308
// See also https://stackoverflow.com/questions/15114140/writing-binary-number-system-in-c-code

// this is really stupid simple but I couldn't get it
#define POS_INFINITY 1e400
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1.0/POS_INFINITY)

int main() {
  printf("\nPos infinity: %f", POS_INFINITY);
  printf("\nNeg infinity: %f", NEG_INFINITY);
  printf("\nNeg zero: %f", NEG_ZERO);
}
