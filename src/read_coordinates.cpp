#include "../include/read_coordinates.hpp"

std::string readFigureCoordinates(std::string coordinatesPath)
{
    std::string myText = "";
    std::string output = "";

    std::ifstream MyReadFile(coordinatesPath);

    while (getline(MyReadFile, myText))
    {
        output.append(myText);
    }

    MyReadFile.close();
    return output;
}
std::vector<Coordinates> getCoordinatesFromFile(std::string pathToFile)
{
    bool foundx = false;
    std::string tmp;
    std::string inputCoordinates;
    Coordinates point;
    std::vector<Coordinates> output;

    inputCoordinates = readFigureCoordinates(pathToFile);

    for (auto i : inputCoordinates)
    {
        if (i != ',' && i != ';' && i != ' ')
        {
            tmp += i;
        }
        else if (i == ',' && foundx == false)
        {
            point.x = GLfloat(std::stof(tmp));
            tmp = "";
            foundx = true;
        }
        else if (i == ';' && foundx == true)
        {
            point.y = GLfloat(std::stof(tmp));
            output.push_back(point);
            tmp = "";
            foundx = false;
        }
    }
    return output;
}