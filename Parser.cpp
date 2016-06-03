#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class Parser
{
private:
	int row;
	int col;
	float start_r;
	float start_c;
	std::vector<int> maze;

public:
	Parser() {}
	~Parser() {}

	int getRow()
	{
		return row;
	}

	int getCol()
	{
		return col;
	}

	float getStart_r()
	{
		return start_r;
	}

	float getStart_c()
	{
		return start_c;
	}

	std::vector<int> parseInput(std::string file) 
	{
		std::ifstream input(file, std::ifstream::in);

		char s[256];
		input.getline(s, 256);
		row = atoi(s);
		input.getline(s, 256);
		col = atoi(s);
		input.getline(s, 256);
		start_r = atof(s);
		input.getline(s, 256);
		start_c = atof(s);

		while(input.getline(s, col+1))
		{
			for (int i = 0; i < col; ++i)
			{
				maze.push_back(s[i] - '0');
			}
		}

		input.close();

		return maze;
	}
	
};