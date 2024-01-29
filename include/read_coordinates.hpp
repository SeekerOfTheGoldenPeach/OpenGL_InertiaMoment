#pragma once
#include <iostream>
#include <fstream>
#include "./calculate_inertia.hpp"
#include <vector>

std::string readFigureCoordinates(std::string coordinatesPath);
std::vector<Coordinates> getCoordinatesFromFile(std::string pathToFile);
