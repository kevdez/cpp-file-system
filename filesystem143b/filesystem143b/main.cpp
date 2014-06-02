#include <iostream>
#include <string>
#include <sstream>
#include "Driver.h"

using namespace std;


int main( int argc, const char* argv[] )
{
	Driver driver;
	printf( "\nHi! Put in some words!\n\n" );
	if (argc == 1)		// no arguments, besides default program name arg
	{	
		driver = Driver();
		driver.runCL();
	}
	else if (argc == 2)	// one argument, the input file
	{
		driver.runInputFile(argv[1]);
	}
	else if (argc == 3)	// two arguments, input and output files
	{
		driver.runInNOut(argv[1], argv[2]);
	}
	else
	{
		cout << "Error: Too many arguments.\nOnly accepts 0, 1, or 2 arguments." << endl;
	}

	// Prints each argument on the command line.
	/*for( int i = 0; i < argc; i++ )
	{
		printf( "arg %d: %s\n", i, argv[i] );
	}*/

	return 0;
}
