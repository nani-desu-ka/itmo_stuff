#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "Board.hpp"
#include "Enums.hpp"
#include "Player.hpp"
#include "Turn.hpp"

double rotate_y = 0;
double rotate_x = 0;

Board temp_board;
Player white_player(&temp_board);
Player black_player(&temp_board);
std::vector<Player *> actual_player;

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) rotate_y += 4;
    else if (key == GLUT_KEY_LEFT) rotate_y -= 4;
    else if (key == GLUT_KEY_UP) rotate_x += 4;
    else if (key == GLUT_KEY_DOWN) rotate_x -= 4;
    else if (key == GLUT_KEY_CTRL_L) {
        actual_player.clear();
        std::cout << "==========Shutting down==========\n";
        exit(EXIT_SUCCESS);
    }
    glutPostRedisplay();
}

void display() {
    glClearColor(0.5, 0.5, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glScalef(0.7, 0.7, 0.7);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glScalef(0.2, 0.2, 0.2);
    temp_board.draw();
    white_player.show();
    black_player.show();
    glFlush();
    glutSwapBuffers();
}

void simpleKeys(unsigned char key, int x, int y) {
    if (!end_game) {
        if (key == 'w' || key == 'W') actual_player[turn]->change_pos(up);
        else if (key == 'a' || key == 'A') actual_player[turn]->change_pos(left);
        else if (key == 's' || key == 'S') actual_player[turn]->change_pos(down);
        else if (key == 'd' || key == 'D') actual_player[turn]->change_pos(right);
        else if (key == ' ') {
            actual_player[turn]->pick();
            if (!first_mirror) {
                actual_player[turn]->mirror();
                rotate_y += 180;
                glRotatef(rotate_y, 0.0, 1.0, 0.0);
                if (end_game) {
                    temp_board.finisher();
                }
                display();
                for (int i = 0; i < 60; i++) {
                    rotate_y += 3;
                    display();
                }
            }
        }
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    std::cout << "===========Starting...===========\n";
    actual_player.push_back(&white_player);
    black_player.mirror();
    actual_player.push_back(&black_player);
    black_player.give_figure(castle, 63);
    black_player.give_figure(queen, 59);
    white_player.give_figure(queen, 3);
    black_player.give_figure(hideo_kojima, 60);
    white_player.give_figure(hideo_kojima, 4);
    white_player.board_prepare();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(GLUT_INIT_WINDOW_WIDTH / 2, GLUT_INIT_WINDOW_HEIGHT / 2);
    glutCreateWindow("Custom Chess");
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(simpleKeys);
    glutMainLoop();
    return 0;
}
