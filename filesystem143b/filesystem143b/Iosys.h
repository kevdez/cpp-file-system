#ifndef IOSYS_H
#define IOSYS_H


class IOSys
{
private:

	// ldisk[L][B]
	// L: number of logical blocks on ldisk
	// B: block length (in bytes)
	//		64B = 16 int
	static char ldisk[64][64];

public:
	IOSys();

	void read_block(int i, char* p);
	void write_block(int i, char* p);

};


#endif // !IOSYS_H
