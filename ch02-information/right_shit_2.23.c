#include<stdio.h>

int fun1(unsigned word) {
  return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
  return ((int) (word << 24)) >> 24;
}

void print_both(unsigned num) {
  printf("\nfun1(%u) = %d)", num, fun1(num));
  printf("\nfun2(%u) = %d)", num, fun2(num));
}

int main() {
  print_both(0x00000076);
  print_both(0x87654321);
  print_both(0x000000C9);
  print_both(0xEDCBA987);
}
