#include <stdio.h>
#include <stdlib.h>

int safe_maloc(int ele_cnt, size_t ele_size) {
  // we cannot safely do the following because it could overflow the total size
  // void *result = malloc(ele_cnt * ele_size);

  // => we should check for overflow and abort in that case
  unit64_t required_size = ele_cnt * (unit64_t) ele_size;
  size_t request_size (size_t) required_size;
  if (required_size != ele_size) {
    // overflow must occured
    return NULL
  }
  void *result = malloc(request_size);
  return result;
}
