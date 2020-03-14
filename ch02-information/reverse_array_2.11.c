#include <stdio.h>

// just helper from previous exercise
void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

// practice problem 2.11 on page 91
void reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt-1;
      // Here we had to change <= TO < to fix the bug
       first < last;
       first++, last--) {
    inplace_swap(&a[first], &a[last]);
  }
}

int main() {
  int nums[4] = {1, 2, 3, 4};
  int nums2[5] = {1, 2, 3, 4, 5};

  printf("reverse 1-4 array:");
  reverse_array(nums, 4);
  for (int i=0; i< 4; i++) {
    printf("%d", nums[i]);
  }
  printf("\n");

  printf("reverse 1-5 array:");
  reverse_array(nums2, 5);
  for (int i=0; i< 5; i++) {
    printf("%d", nums2[i]);
  }
  printf("\n");
}
