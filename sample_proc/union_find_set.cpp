// 并查集
// union find set
#include <stdio.h>
#include <string.h>
const int N=10;
int parent[N];		// parent[i] is the ith element's parent node
int height[N];		// the union set tree's height

void init()
{// set all node's parent to NONE,set all set's height as 0
	memset(parent,-1,sizeof(parent));
	memset(height,0,sizeof(height));
}

/*
int find(int i)
{// finds the reprentative of the set where ith element is in
	int p=i;
	while(i!=-1)
	{
		p=i;
		i=parent[i];
		if(i!=-1 && parent[i]!=-1)	// zip the route
			parent[p]=parent[i];
	}
	return p;
}
*/

int find(int i)
{// recursive version
	if(parent[i]==-1) return i;
	else
		return parent[i]=find(parent[i]);
}

void merge(int i,int j)
{// merge the set which i and j is in separately
	i=find(i);
	j=find(j);
	if( height[i]>height[j] )
	{// now i is the representative
		parent[j]=i;
	}
	else
	{// height[i]<=height[j],set j as the representative
		parent[i]=j;
		if(height[i]==height[j])
			height[j]++;
	}
}

int main()
{
	init();
	merge(0,1);
	merge(1,2);
	merge(2,3);
	for(int i=0;i<N;i++)
		printf("%d ",parent[i]);
	printf("\n");
	for(int i=0;i<N;i++)
		printf("%d ",height[i]);
	printf("\n");
	return 0;
}
