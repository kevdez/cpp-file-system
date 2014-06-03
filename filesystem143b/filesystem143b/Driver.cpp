#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Driver.h"

Driver::Driver()
	:fs(FileSys())
{
}

void Driver::runCL()
{
	std::getline(std::cin, currentCommand);
	while (currentCommand != "-1")
	{
		parseAndExecute();
		std::getline(std::cin, currentCommand);
	}
}

void Driver::runInputFile(std::string inputFile)
{
	std::ifstream infile;
}

void Driver::runInNOut(std::string inputFile, std::string outputFile)
{
	std::ifstream inFile;
	std::ofstream outFile;
}

void Driver::parseAndExecute()
{
	std::vector<std::string> tokens;
	std::istringstream iss(currentCommand);
	std::string word;

	while (iss >> word)
	{
		tokens.push_back(word);
	}

	if (tokens.at(0) == "cr")	// create
	{
		if (tokens.size() == 2)
		{
			word = tokens.at(1);
			outputString = fs.create(word);
		}
		else
			error();
	}
	else if (tokens.at(0) == "de")	// destroy
	{
		if (tokens.size() == 2)
		{
			word = tokens.at(1);
			outputString = fs.destroy(word);
		}
		else
			error();
	}
	else if (tokens.at(0) == "op")	// open
	{
		if (tokens.size() == 2)
		{
			word = tokens.at(1);
			outputString = fs.open(word);
		}
		else
			error();
	}
	else if (tokens.at(0) == "cl")	// close
	{
		if (tokens.size() == 2)
		{
			int index = atoi(tokens.at(1).c_str());
			outputString = fs.close(index);
		}
		else
			error();
	}
	else if (tokens.at(0) == "rd")	// read
	{
		if (tokens.size() == 3)
		{
			int index = std::atoi(tokens.at(1).c_str());
			int count = std::atoi(tokens.at(2).c_str());
			outputString = fs.read(index, count);
		}
		else
			error();
	}
	else if (tokens.at(0) == "wr")	// write
	{
		if (tokens.size() == 4)
		{
			int index = std::atoi(tokens.at(1).c_str());
			std::string s = tokens.at(2);
			char letter = s[0];
			int count = std::atoi(tokens.at(3).c_str());
			outputString = fs.write(index, letter, count);
		}
		else
			error();
	}
	else if (tokens.at(0) == "sk")	// seek
	{
		if (tokens.size() == 3)
		{
			int index = std::atoi(tokens.at(1).c_str());
			int pos = std::atoi(tokens.at(2).c_str());
			outputString = fs.seek(index, pos);
		}
		else
			error();
	}
	else if (tokens.at(0) == "dr")	// directory
	{
		if (tokens.size() == 1)
			outputString = fs.directory();
		else
			error();

	}
	else if (tokens.at(0) == "in")	// initialize
	{
		if (tokens.size() == 1)
			outputString = fs.initialize();
		else if (tokens.size() == 2)
		{
			word = tokens.at(1);
			outputString = fs.initialize(word);
		}
		else
			error();
	}
	else if (tokens.at(0) == "sv")	// save
	{
		if (tokens.size() == 2)
		{
			word = tokens.at(1);
			outputString = fs.save(word);
		}
		else
			error();
	}
	else
		error();
}

void Driver::error()
{
	outputString = "error";
}