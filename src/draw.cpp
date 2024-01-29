#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "../include/calculate_inertia.hpp"
#include <vector> 

Coordinates p1 = {0.0f, 0.0f};
Coordinates p2 = {20.0f, 0.0f};
Coordinates p3 = {20.0f, 20.0f};
Coordinates p4 = {0.0f, 20.0f};
Coordinates p5 = {0.0f, 0.0f};
Coordinates p6 = {0.0f, 20.0f};

std::vector<Coordinates> figureCoordinates = {p1, p2, p3,p4,p5,p6};

void draw(std::vector<Coordinates> figure)
{
 
    glBegin(GL_LINE_STRIP);
    for (size_t i = 0; i<figure.size(); i++)
        {   
            glVertex2f(figure.at(i).x,figure.at(i).y);
GIT
        }
    glEnd();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity();
    glutSwapBuffers();
    }

void display()
{   glMatrixMode ( GL_PROJECTION );
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glLoadIdentity();
    draw(figureCoordinates);
}


void keybord(unsigned char button, int x, int y)
{
    switch (button)

    {
    case 27:
        exit(0);
    }
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500,500); /* 500 x 500 pixel window */
    glutInitWindowPosition(0,0);    
    glutCreateWindow("OpenGL Test");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keybord);
    glClearColor(0,0,0,1);
    glutMainLoop();
    
    return 0;
}









