#include <iostream>
#include <string>
#include <sstream>
#include "Driver.h"
#include "Filesys.h"
#include "Iosys.h"

using namespace std;


int main( int argc, const char* argv[] )
{
	Driver driver;
	cout << endl;

	if (argc == 1)		// no arguments, besides default program name arg
	{	
		printf("NO argument. Running command line version.\nEnter \"-1\" to quit.\n\n");
		//driver = Driver();
		//driver.runCL();
	}
	else if (argc == 2)	// one argument, the input file
	{
		printf("ONE argument. Running input file version.\n\n");
		//driver.runInputFile(argv[1]);
	}
	else if (argc == 3)	// two arguments, input and output files
	{
		printf("TWO arguments. Running input + output file version.\n\n");
		//driver.runInNOut(argv[1], argv[2]);
	}
	else
	{
		cout << "Error: Too many arguments.\nOnly accepts 0, 1, or 2 arguments.\n\n" << endl;
	}

	return 0;
}
