#pragma once

void comm_list ();
bool command_input ();

enum command {
    p_exit,
    new_shape,
    all_shapes_info,
    all_shapes_square,
    all_shapes_perimeter,
    mass_center,
    memory_size,
    mass_sort,
    command_list,
};

enum Shape {
    circle,
    equil_triangle,
};
