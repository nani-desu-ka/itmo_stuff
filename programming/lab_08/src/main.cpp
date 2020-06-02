#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>

void Update() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glOrtho(-1, 1, -1, 1, -1, 1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(GLUT_INIT_WINDOW_HEIGHT, GLUT_INIT_WINDOW_HEIGHT);
    glutInitWindowPosition(GLUT_INIT_WINDOW_WIDTH / 2, GLUT_INIT_WINDOW_HEIGHT / 2);
    glutCreateWindow("Custom Rubik's Cube");
    glutDisplayFunc(Update);
    glutMainLoop();
    std::cout << "==========Shutting down==========\n";
    return 0;
}
