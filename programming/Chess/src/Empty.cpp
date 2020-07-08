#include "Empty.hpp"
#include "Board.hpp"

void Empty::show_fields() {}
void Empty::hide_fields() {}
void Empty::transition(int) {}
void Empty::set_index(int) {}
void Empty::show() {}

figures Empty::type() {
    return empty;
}