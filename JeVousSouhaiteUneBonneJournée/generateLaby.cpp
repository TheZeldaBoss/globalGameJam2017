#include "generateLaby.h"
#include "main.h"
#include <iostream>
#include <fstream>

Labyrinth::Labyrinth(std::string filename)
{
	std::ifstream flux;
	std::string str;
	std::vector<int> *vecLine;
	vecLine = new std::vector<int>;
	int actualNb = 0;
	flux.open(filename);
	if (!flux.is_open())
		std::cerr << "Error while opening file" << std::endl;
	while (getline(flux, str))
	{
		for (unsigned int i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
				actualNb = actualNb * 10 + (str[i] - '0');
			else if (actualNb != 0)
			{
				vecLine->push_back((actualNb + 1) % 2);
				actualNb = 0;
			}
		}
		if (actualNb != 0)
		{
			vecLine->push_back((actualNb + 1) % 2);
			actualNb = 0;
		}
		this->labyrinthData.push_back(*vecLine);
		vecLine->clear();
	}
}

int Labyrinth::getOutX()
{
	return (this->outX);
}

int Labyrinth::getOutY()
{
	return (this->outY);
}

std::vector<std::vector<int>> Labyrinth::getData()
{
	return (this->labyrinthData);
}