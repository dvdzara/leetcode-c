lib_solution = library('0001', 'solution.c')

test('0001n', executable('0001', 'tests/main.c',
    link_with: [lib_solution, lib_array_equal],
    include_directories: [headers_lib]
))
