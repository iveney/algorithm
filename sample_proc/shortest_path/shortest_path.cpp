/*
	read from file testcase.in
	first line is the size of graph
	second line is the source point
	afterwards, 'from' 'to' 'dist' are three integers which represent
	there is an edge between 'from' and 'to' and the distance is 'dist'

	calculate the shortest path
*/

#include <stdio.h>

const int N = 100;
const int INF = 1<<30;
int size,source;
int d[N][N];	// edge graph
int shortest[N];	// stores the shortest distance from Start point to each point
int via[N];			// stores the shortest path
bool mark[N];		// mark if the coresponding point has checked

// init the edge matrix
void init_edge()
{
	int i,j;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			if(i==j) d[i][j] = 0;
			else d[i][j] = INF;

	for(i=0;i<size;i++)
	{
		mark[i] = false;
		via[i] = -1;
	}
}

// print out the edge matrix
void print()
{
	int i,j;
	for(i=0;i<size;i++)
	{
		// use left alignment
		for(j=0;j<size;j++)
			if(d[i][j]!=INF)printf("%-10d",d[i][j]);
			else printf("%-10c",'-');
		printf("\n");
	}
	printf("\n");
}

// output the shortest path from source point
void output()
{
	int i;
	for(i=0;i<size;i++)
		if(shortest[i] != INF) printf("%-10d",shortest[i]);
		else printf("%-10c",'-');
	printf("\n\n");
}

// initialize the shortest distance vector from source point
void init_source()
{
	int i;
	for(i=0;i<size;i++)
	{
		shortest[i] = d[source][i];
		if( shortest[i] != INF )
			via[i] = source;
	}
	mark[source] = true;	// mark the source point in the set
}


// output the shortest path from source to dest
void trace(int dest)
{
	printf("%d",dest);
	int pre = dest,next = -1;
	while( pre != source )
	{
		pre = via[pre];
		printf(" <- %d",pre);
	}
	printf("\n");
}

int main()
{
	freopen("testcase.in","r",stdin);
	int from,to,dist;

	// input size and edges
	scanf("%d %d",&size,&source);
	init_edge();
	while( scanf("%d %d %d",&from,&to,&dist) != EOF )
		d[from][to] = dist;
	//print(size);

	// initialize shortest path from 'source'
	init_source();
	
	//output(size);

	int i,j;
	for(i=0;i<size;i++)
	{// check which remaining edge 'i' should be added into the set

		// search which should be add(has the shortest dist to Start Point)
		int now_dist = INF;
		int index = -1;
		for(j=0;j<size;j++)
		{
			if( mark[j] != true && shortest[j] < now_dist)
			{
				now_dist = shortest[j];
				index = j;
			}
		}

		// now point 'index' has the shortest path to Start Point
		// add to the set
		mark[index] = true;

		// update all the shortest distance to Start Point
		for(j=1;j<size;j++)
		{
			if( mark[j]!=true && shortest[j] > shortest[index] + d[index][j] )
			{
				shortest[j] = shortest[index] + d[index][j];
				via[j] = index;
			}
		}
	}

	output();
	trace(2);
	
	return 0;
}