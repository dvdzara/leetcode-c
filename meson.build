project(
  'leetcode-c',
  'c',
  default_options: [
    'c_args=-Wpedantic -Wextra -Wall',
    'c_std=gnu11',
  ],
)

lib_criterion = subproject('criterion').get_variable('criterion')
headers = include_directories('src/')

problems = ['0001', '0002']

foreach p : problems
  test(
    p,
    executable(
      p,
      f'tests/@p@.c',
      link_with: library(p, f'src/@p@/solution.c'),
      include_directories: headers,
      dependencies: lib_criterion,
    ),
  )
endforeach