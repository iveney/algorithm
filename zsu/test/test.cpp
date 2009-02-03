#include <stdio.h>

const int G_row = 10;
const int G_column = 20;

int main()
{
	int **GG;
	GG = new int*[G_row];
	int i;
	for(i = 0; i < (G_row); i++)
		GG[i] = new int[G_column];

	for (i = 0; i < (G_row); i++)
	{
		delete [] GG[i];
	}
	delete [] GG;
	GG = NULL;
	return 0;
}
