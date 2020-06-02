#include "Corner_element.hpp"
#include <GL/freeglut.h>
#include <GL/gl.h>

void corner_element::draw() {
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0 );
        glVertex3f(0.5, -0.5, -0.5 );
        glVertex3f(0.5, 0.5, -0.5 );
        glVertex3f(-0.5, 0.5, -0.5 );
        glVertex3f(-0.5, -0.5, -0.5 );
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0 );
        glVertex3f(0.5, -0.5, 0.5 );
        glVertex3f(0.5, 0.5, 0.5 );
        glVertex3f(-0.5, 0.5, 0.5 );
        glVertex3f(-0.5, -0.5, 0.5 );
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 1.0 );
        glVertex3f(0.5, -0.5, -0.5 );
        glVertex3f(0.5, 0.5, -0.5 );
        glVertex3f(0.5, 0.5, 0.5 );
        glVertex3f(0.5, -0.5, 0.5 );
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0 );
        glVertex3f(-0.5, -0.5, 0.5 );
        glVertex3f(-0.5, 0.5, 0.5 );
        glVertex3f(-0.5, 0.5, -0.5 );
        glVertex3f(-0.5, -0.5, -0.5 );
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 1.0 );
        glVertex3f(0.5, 0.5, 0.5 );
        glVertex3f(0.5, 0.5, -0.5 );
        glVertex3f(-0.5, 0.5, -0.5 );
        glVertex3f(-0.5, 0.5, 0.5 );
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0 );
        glVertex3f(0.5, -0.5, -0.5 );
        glVertex3f(0.5, -0.5, 0.5 );
        glVertex3f(-0.5, -0.5, 0.5 );
        glVertex3f(-0.5, -0.5, -0.5 );
    glEnd();
}