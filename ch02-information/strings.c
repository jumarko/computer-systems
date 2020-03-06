#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

// this is an example from page 85
int main() {
  char *str = "12345";
  // will print:  31 32 33 34 35 00
  show_bytes((byte_pointer) str, 6);

  // problem 2.7
  const char *m = "mnopqr";
  show_bytes((byte_pointer) m, strlen(m));
}
