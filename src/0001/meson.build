solution_lib = library('0001', 'solution.c')
current_dir = include_directories('.')

test('01', executable('01', 'tests/01.c', link_with: solution_lib, include_directories: current_dir))
test('02', executable('02', 'tests/02.c', link_with: solution_lib, include_directories: current_dir))
