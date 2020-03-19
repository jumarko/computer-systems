// Practice problem 2.26 on p. 119
// strlonger function is buggy and needs to be fixed

#include<stdio.h>
#include<string.h>

// this is strlen prototype
// size_t strlen(const char *s);

int strlonger(char *s, char *t) {
  // debug printlns
  printf("s: %lu\n", strlen(s)); 
  printf("t: %lu\n", strlen(t)); 
  // this will print s-t: 18446744073709551615
  // for s = 4, t = 5
  printf("s-t: %lu\n", strlen(s) - strlen(t)); 
  return strlen(s) - strlen(t) > 0;
}

int strlonger2(char *s, char *t) {
  return strlen(s) > strlen(t);
}

int main() {
  char *a = "ahoj";
  char *b = "hello";
  // printf("a > b: %d\n", strlonger(a, b));
  // printf("b > a: %d\n", strlonger(b, a));
  // printf("a > a: %d\n", strlonger(a, a));

  printf("a > b: %d\n", strlonger2(a, b));
  printf("b > a: %d\n", strlonger2(b, a));
  printf("a > a: %d\n", strlonger2(a, a));
}
