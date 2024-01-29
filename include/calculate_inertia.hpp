#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <cmath>
#include <vector>

struct Coordinates
{
    GLfloat x;
    GLfloat y;
};

struct CalculationData
{
    GLfloat area;
    GLfloat sx;
    GLfloat sy;
    GLfloat ix;
    GLfloat iy;
    GLfloat ixy;
};

CalculationData calculate_inertia(std::vector<Coordinates> figureCoordinates);

