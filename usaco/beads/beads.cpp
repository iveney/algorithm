/*
ID: iveney1
PROG: beads
LANG: C++
*/
#include <cstdio>
using namespace std;

const int MAX = 400;
int	N;
char beads[MAX];
/*
          getRight
          |
0 1 2 3 4 5 6 7 8 9
        |
		getLeft
*/

int getLeft(int start,int maxLen)
{
	if(maxLen <= 0 )return 0;
	int count=1,read = 1;
	int i=start;
	char ch = beads[start];
	while( read+1 <= maxLen && read < N )
	{
		i--;read++;
		if(i<0) i+=N;	// loop to tail
		if( ch == 'w' )
		{
			count++;
			if(beads[i] == 'r')
				ch = 'r';
			else if(beads[i] == 'b')
				ch = 'b';
		}
		else if( ch == beads[i] || beads[i] == 'w' )
		{
			count++;
		}
		else
			break;
	}
	return count;
}

int getRight(int start)
{
	int count = 1,read = 1;
	int i =start;
	char ch = beads[start];
	while( read < N )
	{
		i++;read++;
		if(i>=N) i-=N;
		if(ch == 'w')
		{
			count++;
			if(beads[i] == 'r')
				ch = 'r';
			else if(beads[i] == 'b')
				ch = 'b';
		}
		else if( ch == beads[i] || beads[i] == 'w' )
		{
			count++;
		}
		else
			break;
	}
	return count;
}



int main() {
	FILE* in = fopen("beads.in","r");
	FILE* out = fopen("beads.out","w");

	fscanf(in,"%d%s",&N,beads);
	int max = 0,cut=-1;
	for(int i = 0;i<N;i++)
	{
		int right = getRight(i);
		int left_start = (i-1<0)?(i-1+N):(i-1);
		int left = getLeft(left_start,N-right);
		if(max < left+right)
		{
			max = left+right;
			cut = i;
		}
	}

	//printf("%d\t%d\n",max,cut);
	fprintf(out,"%d\n",max);

    return 0;
}