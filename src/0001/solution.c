// Copyright [2024] Davide Zarantonello

#include "src/0001/solution.h"

#include <stdlib.h>

int* two_sum(const int* nums, int nums_size, int target, int* return_size) {
  *return_size = 2;
  int* result = calloc(2, sizeof(int));

  for (int i = 0; i < nums_size; ++i) {
    for (int j = 0; j < nums_size; ++j) {
      if (i != j && nums[i] + nums[j] == target) {
        result[0] = i;
        result[1] = j;
        return result;
      }
    }
  }

  return result;
}
