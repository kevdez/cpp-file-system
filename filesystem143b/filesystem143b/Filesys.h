#ifndef FILESYS_H
#define FILESYS_H

#include <string>
#include "Iosys.h"
#include "OFT.h"

class FileSys
{
private:
	static IOSys ios;
	static OFT oft;

	void initializeEmptyBitMap();
	bool isBlockEmptyInBitMap(int blockNumber);
	void setBlockOccupiedInBitMap(int blockNumber);
public:

	FileSys();	// constructor, initializes IOSystem
	
	void restoreIOSystem(std::string fileName);
	
	std::string create(std::string name);	// cr <name>
	std::string destroy(std::string name);	// de <name>
	std::string open(std::string name);	// op <name>
	std::string close(int index);			// cl <index>
	std::string read(int index, int count);	// rd <index> <count>
	std::string write(int index, char c, int count);	// wr <index> <char> <count>
	std::string seek(int index, int pos);	// sk <index> <pos>
	std::string directory();				// output: <file0> <file1> ... <fileN>
	std::string initialize(std::string name = NULL);	// in <disk_cont.txt>
	std::string save(std::string outputFile);	// sv <disk_cont.txt>
	
};

#endif // !FILESYS_H
