#include "../include/calculate_inertia.hpp"
#include "../include/read_coordinates.hpp"


int main()
{
    std::vector<Coordinates> figureCoordinates = getCoordinatesFromFile("../data/figure_1.txt");

    CalculationData figure = calculate_inertia(figureCoordinates);

    std::cout << "figure area: " << figure.area << '\n';
    std::cout << "figure Centroid x sx: " << figure.sx / figure.area << '\n';
    std::cout << "figure Centroid y sy: " << figure.sy / figure.area << '\n';

    std::cout << "figure ix: " << figure.ix << '\n';
    std::cout << "figure iy: " << figure.iy << '\n';
    std::cout << "figure ixy: " << figure.ixy << '\n';

    return 0;
}