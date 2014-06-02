#ifndef FILESYS_H
#define FILESYS_H

#include <string>
#include "Iosys.h"

class FileSys
{
private:
	static IOSys iosys;
	
public:

	FileSys();	// constructor, initializes IOSystem
	
	void create(std::string name);	// cr <name>
	void destroy(std::string name);	// de <name>
	void open(std::string name);	// op <name>
	void close(int index);			// cl <index>
	void read(int index, int count);	// rd <index> <count>
	void write(int index, char c, int count);	// wr <index> <char> <count>
	void seek(int index, int pos);	// sk <index> <pos>
	void directory();				// output: <file0> <file1> ... <fileN>
	void initialize(std::string name=NULL);	// in <disk_cont.txt>
	void save(std::string outputFile);	// sv <disk_cont.txt>
	
};

#endif // !FILESYS_H
