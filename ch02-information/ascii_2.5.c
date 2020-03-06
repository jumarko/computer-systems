#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

void show_int(int x) {
  printf("int: ");
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(int x) {
  printf("float: ");
  show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
  printf("pointer: ");
  show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float) val;
  int *pval = &ival;
  show_int(ival);
  show_float(fval);
  // this will be different every time you run the program
  show_pointer(pval);
}

int main() {
  int a = 0x12345678;
  byte_pointer ap = (byte_pointer) &a;
  show_bytes(ap, 1);
  show_bytes(ap, 2);
  show_bytes(ap, 3);
}
