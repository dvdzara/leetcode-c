#include <stdbool.h>

bool int_array_equal(const int array_size, const int array1[],
                     const int array2[]) {
  for (int i = 0; i < array_size; ++i) {
    if (array1[i] != array2[i]) {
      return false;
    }
  }

  return true;
}
