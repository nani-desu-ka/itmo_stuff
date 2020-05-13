#include <iostream>
#include <vector>
#include <algorithm>
#include "Interfaces.hpp"
#include "side_lib.hpp"
#include "Circle.hpp"
#include "Equil_triangle.hpp"

std::vector <Figure *> shapes;
int order = 0;

void comm_list () {
    std::cout << "==========СПИСОК КОМАНД==========\n";
    std::cout << "Добавить новую фигуру - 1\n";
    std::cout << "Вывести полную информацию обо всех фигурах - 2\n";
    std::cout << "Вывести суммарную площадь фигур - 3\n";
    std::cout << "Вывести суммарный периметр фигур - 4\n";
    std::cout << "Вывести цетр масс системы - 5\n";
    std::cout << "Вывести занимаемую память памяти - 6\n";
    std::cout << "Сортировать объекты по массе - 7\n";
    std::cout << "=================================\n";
    std::cout << "Завершить программу - 0\n\n";
}

bool command_input () {
    int temp_comm;
    std::cout << "Введите команду\n~> ";
    std::cin >> temp_comm;
    switch (temp_comm) {
        case p_exit: {
            return true;
        } case new_shape: {
            int shape;
            std::cout << "=======Выберите фигуру=======\n";
            std::cout << "Круг - 0\n";
            std::cout << "Равнобедренный треугольник - 1\n";
            std::cout << "Отмена - другие значения\n";
            std::cout << "=============================\n";
            std::cout << "~> ";
            std::cin >> shape;
            if (shape == circle) {
                shapes.push_back(new Circle);
            } else if (shape == equil_triangle) {
                shapes.push_back(new Equil_triangle);
            } else {
                break;
            }
            shapes[order]->initFromDialog();
            order++;
            std::cout << '\n';
            break;
        } case all_shapes_info: {
            for (Figure *& figure : shapes) {
                std::cout << figure << ": " << figure->classname() << '\n';
                figure->draw();
                std::cout << '\n';
            }
            std::cout << '\n';
            break;
        } case all_shapes_square: {
            double total = 0;
            for (Figure *& figure : shapes) {
                total += figure->square();
            }
            std::cout << "Общая площадь: " << total << '\n';
            std::cout << '\n';
            break;
        } case all_shapes_perimeter: {
            double total = 0;
            for (Figure *& figure : shapes) {
                total += figure->perimeter();
            }
            std::cout << "Общая площадь: " << total << '\n';
            std::cout << '\n';
            break;
        } case mass_center: {
            CVector2D mass_center = CVector2D();
            double mass_sum = 0;
            for (Figure *& figure : shapes) {
                mass_sum += figure->mass();
                mass_center.x += figure->mass() * figure->position().x;
                mass_center.y += figure->mass() * figure->position().y;
            }
            mass_center.x /= mass_sum;
            mass_center.y /= mass_sum;
            std::cout << "Центр масс: {" << mass_center.x << ", " << mass_center.y << "}\n";
            std::cout << '\n';
            break;
        } case memory_size: {
            unsigned int mem_size = 0;
            for (Figure *& figure : shapes) {
                mem_size += figure->size();
            }
            std::cout << "Размер занимаемой памяти: " << mem_size << '\n';
            std::cout << '\n';
            break;
        } case mass_sort: {
            std::sort(shapes.begin(), shapes.end(), [](Figure * a, Figure * b) { return a->mass() < b->mass(); });
            std::cout << "=======Фигуры отсортированы=======\n";
            std::cout << '\n';
            break;
        } case command_list: {
            comm_list();
            break;
        } default: {
            std::cout << "=========Введена несуществующая команда=========\n";
            std::cout << '\n';
        }
    }
    return false;
}