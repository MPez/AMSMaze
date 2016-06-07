#include <fstream>
#include <sstream>
#include "Maze.h"

Maze::Maze() { }

Maze::~Maze() { }

void Maze::parseInput(std::string file)
{
    std::ifstream input(file, std::ifstream::in);

    if (input)
    {
        std::string line;
        std::getline(input, line);
        std::istringstream sstream(line);
        sstream >> row >> col >> start_r >> start_c;
        GLuint intLine;

        while(std::getline(input, line))
        {
            sstream = std::basic_istringstream(line);
            std::vector<GLuint> rowLine;
            while (sstream >> intLine)
            {
                rowLine.push_back(intLine);
            }
            maze.push_back(rowLine);
        }
    }

    input.close();
}

GLuint Maze::getRow() const {
    return row;
}

GLuint Maze::getCol() const {
    return col;
}

GLuint Maze::getStart_r() const {
    return start_r;
}

GLuint Maze::getStart_c() const {
    return start_c;
}