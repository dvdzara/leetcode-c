#include <stdio.h>
#include <stdlib.h>

#include "../solution.h"
#include "array_equal/lib.h"
#include "sizeof_array/lib.h"

struct ProblemArgs {
  int target;
  int nums_size;
  int *nums;
};

struct TestCase {
  struct ProblemArgs args;
  int *correct_result;
};

int main() {
  const int nums1[] = {2, 7, 11, 15};
  const int correct_result1[] = {0, 1};
  const int nums2[] = {3, 2, 4};
  const int correct_result2[] = {1, 2};
  const int nums3[] = {3, 3};
  const int correct_result3[] = {0, 1};

  const struct TestCase cases[] = {
      {{9, sizeof_array(int, nums1), &nums1}, &correct_result1},
      {{6, sizeof_array(int, nums2), &nums2}, &correct_result2},
      {{6, sizeof_array(int, nums3), &nums3}, &correct_result3},
  };

  const int correct_result_size = 2;
  const int cases_size = sizeof_array(struct TestCase, cases);

  for (int i = 0; i < cases_size; ++i) {
    int result_size = 0;
    const int *result = two_sum(cases[i].args.nums, cases[i].args.nums_size,
                                cases[i].args.target, &result_size);

    if (!int_array_equal(correct_result_size, result,
                         cases[i].correct_result)) {
      printf("[%d, %d] !== [%d, %d]\n", result[0], result[1],
             cases[i].correct_result[0], cases[i].correct_result[1]);

      free((void *)result);
      return 1;
    }

    free((void *)result);
  }

  return 0;
}
