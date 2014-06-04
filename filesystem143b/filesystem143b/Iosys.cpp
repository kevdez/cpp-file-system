#include"Iosys.h"

IOSys::IOSys()
{
	for (int i = 0; i < 64; i++)
		for (int j = 0; j < 64; j++)
			ldisk[i][j] = -1;
}

void IOSys::read_block(int i, char* p)
{
	p = &(ldisk[i][0]);
}

void IOSys::write_block(int i, char* p)
{
	ldisk[i][0] = *p;
}

