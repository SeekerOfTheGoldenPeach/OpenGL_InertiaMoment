#include "../include/calculate_inertia.hpp"

CalculationData calculate_inertia(std::vector<Coordinates> figureCoordinates)
{
    CalculationData figure = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    GLfloat x1 = 0.0f;
    GLfloat y1 = 0.0f;
    GLfloat x2 = 0.0f;
    GLfloat y2 = 0.0f;

    GLfloat d = 0.0f;

    for (auto i = 0; i < figureCoordinates.size() - 1; i++)
    {
        x1 = figureCoordinates.at(i).x;
        y1 = figureCoordinates.at(i).y;

        x2 = figureCoordinates.at(i + 1).x;
        y2 = figureCoordinates.at(i + 1).y;

        d = x1 * y2 - x2 * y1;

        figure.area += 0.5f * d;

        figure.sx += d / 6 * (y1 + y2);
        figure.sy += d / 6 * (x1 + x2);

        figure.ix += d / 12 * (pow(y1, 2) + y1 * y2 + pow(y2, 2));  // wrong result
        figure.iy += d / 12 * (pow(x1, 2) + x1 * x2 + pow(x2, 2));  // wrong result

        figure.ixy += d / 24 * (x1 * (2 * y1 + y2) + x2 * (y1 + 2 * y2));  // wrong result
    }
    return figure;
}
