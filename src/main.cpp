#include "../include/calculate_inertia.hpp"
#include "../include/read_coordinates.hpp"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <vector> 

void draw(std::vector<Coordinates> figure)
{
    glBegin(GL_LINE_STRIP);
    for (size_t i = 0; i<figure.size(); i++)
        {   
            glVertex2f(figure.at(i).x,figure.at(i).y);
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
    std::vector<Coordinates> figureCoordinates = getCoordinatesFromFile("../data/figure_1.txt");
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
    std::vector<Coordinates> figureCoordinates = getCoordinatesFromFile("../data/figure_1.txt");

    CalculationData figure = calculate_inertia(figureCoordinates);

    std::cout << "figure area: " << figure.area << '\n';
    std::cout << "figure Centroid x sx: " << figure.sx / figure.area << '\n';
    std::cout << "figure Centroid y sy: " << figure.sy / figure.area << '\n';

    std::cout << "figure ix: " << figure.ix << '\n';
    std::cout << "figure iy: " << figure.iy << '\n';
    std::cout << "figure ixy: " << figure.ixy << '\n';

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
