#ifndef DRIVER_H
#define DRIVER_H

#include<string>
#include "Filesys.h"

class Driver
{
private:
	FileSys fs;
	std::string currentCommand;
	std::string outputString;

	void parseAndExecute();	// figures out the command and executes on FS
	void error();
public:
	Driver();	// constructor, init the FS

	void runCL();	// command line UI
	void runInputFile(std::string inputFile); // input file -> output console
	void runInNOut(std::string inputFile, std::string outputFile); // input file -> output file
};

#endif // !DRIVER_H