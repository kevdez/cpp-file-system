#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Driver.h"

using namespace std;

Driver::Driver()
{
	fs = FileSys();
}

// read from console, output to console
void Driver::runCL()
{
	getline(cin, currentCommand);
	while (currentCommand != "-1")
	{
		parseAndExecute();
		getline(cin, currentCommand);
	}
}

// read from file, output to console
void Driver::runInputFile(std::string inputFile)
{
	ifstream infile;
	if (inFile.is_open())
	{
		while (getline(inFile, currentCommand))
		{
			parseAndExecute();
			cout << outputString << endl;
		}
		inFile.close();
	}
	else
	{
		cout << "Unable to open " << inputFile << endl;
	}
}

// read from file, output to file
void Driver::runInNOut(std::string inputFile, std::string outputFile)
{
	ifstream inFile(inputFile); 
	ofstream outFile(outputFile);
	if (inFile.is_open())
	{
		while (getline(inFile, currentCommand))
		{
			parseAndExecute();
			outFile << outputString << endl;
		}
		inFile.close();
		outFile.close();

	}
	else
	{
		cout << "Unable to open " << inputFile << endl;
	}
	
}

void Driver::parseAndExecute()
{
	vector<string> tokens;
	istringstream iss(currentCommand);
	string word;

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
			int index = atoi(tokens.at(1).c_str());
			int count = atoi(tokens.at(2).c_str());
			outputString = fs.read(index, count);
		}
		else
			error();
	}
	else if (tokens.at(0) == "wr")	// write
	{
		if (tokens.size() == 4)
		{
			int index = atoi(tokens.at(1).c_str());
			char letter = tokens.at(2)[0];
			int count = atoi(tokens.at(3).c_str());
			outputString = fs.write(index, letter, count);
		}
		else
			error();
	}
	else if (tokens.at(0) == "sk")	// seek
	{
		if (tokens.size() == 3)
		{
			int index = atoi(tokens.at(1).c_str());
			int pos = atoi(tokens.at(2).c_str());
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