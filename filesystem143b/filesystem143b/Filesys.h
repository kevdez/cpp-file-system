#ifndef FILESYS_H
#define FILESYS_H

#include <string>
#include "Iosys.h"

class FileSys
{
private:
	IOSys iosys;
	
public:
	FileSys();
	
	void create(std::string name);
	void destroy(std::string name);
	void open(std::string name);
	void close(int index);
	void read(int index, int count);
	void write(int index, char c, int count);
	void seek(int index, int pos);
	void directory();
	void initialize(std::string name = null);
	void save(std::string outputFile
	
};


#endif // !FILESYS_H
