#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>

double rotate_y = 0;
double rotate_x = 0;

void specialKeys( int key, int x, int y ) {
    if (key == GLUT_KEY_RIGHT) rotate_y += 2;
    else if (key == GLUT_KEY_LEFT) rotate_y -= 2;
    else if (key == GLUT_KEY_UP) rotate_x += 2;
    else if (key == GLUT_KEY_DOWN) rotate_x -= 2;
    glutPostRedisplay();
}

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glLoadIdentity();
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(GLUT_INIT_WINDOW_WIDTH / 2, GLUT_INIT_WINDOW_HEIGHT / 2);
    glutCreateWindow("Custom Rubik's Cube");
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    std::cout << "==========Shutting down==========\n";
    return 0;
}
