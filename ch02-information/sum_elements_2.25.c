/* Practice problem 2.25 on page 119
 * There's a subtle error in this code due to implicit casting and using unsigned data type.
 */
#include<stdio.h>

float sum_elements(float a[], unsigned length) {
  int i;
  float result = 0;
  // Issue is here due to usage of length-1 which leads to "underflow" to the unsigned int max number! 
  // for (i = 0; i <= length-1; i++) {
  // correct version (another alternative is to declare length as int)
  for (i = 0; i < length; i++) {
   //  result += a[i];
  }
  return result;
}

int main() {
  float a[0];
  printf("array sum: %f\n", sum_elements(a, 0));
}
