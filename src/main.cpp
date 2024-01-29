#include "../include/calculate_inertia.hpp"

int main()
{
    Coordinates p1 = {0.0f, 0.0f};
    Coordinates p2 = {20.0f, 0.0f};
    Coordinates p3 = {20.0f, 200.0f};
    Coordinates p4 = {0.0f, 200.0f};
    Coordinates p5 = {0.0f, 0.0f};

    std::vector<Coordinates> figureCoordinates = {p1, p2, p3, p4, p5};

    CalculationData figure = calculate_inertia(figureCoordinates);

    std::cout << "figure area: " << figure.area << '\n';
    std::cout << "figure Centroid x sx: " << figure.sx / figure.area << '\n';
    std::cout << "figure Centroid y sy: " << figure.sy / figure.area << '\n';

    std::cout << "figure ix: " << figure.ix << '\n';
    std::cout << "figure iy: " << figure.iy << '\n';
    std::cout << "figure ixy: " << figure.ixy << '\n';

    return 0;
}