project(
  'leetcode-c',
  'c',
  # Needed to compile gtest.
  'cpp',
  default_options: [
    'c_args=-Wpedantic -Wextra -Wall',
    # Standard used by leetcode.
    'c_std=gnu11',
  ],
)

problems = ['0001', '0002']

foreach p : problems
  test(
    p,
    executable(
      p,
      f'tests/@p@.c',
      link_with: library(p, f'src/@p@/solution.c'),
      include_directories: include_directories(f'src/@p@'),
      dependencies: subproject('gtest').get_variable('gtest_dep'),
    ),
  )
endforeach