#include <iostream>
#include <sstream>
#include <string>
#include "Driver.h"

using namespace std;

Driver::Driver()
	:fs(FileSys())
{
}

void Driver::run()
{

	cin >> currentCommand;
}