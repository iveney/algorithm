#include <stdio.h>
#include <vector>
using namespace std;

const int SIZE = 20000;

char nodes[SIZE];
int parents[SIZE];
vector<int> table[SIZE];

int getHeight(vector<int> t[],int no)
{
	int max = 0;
	for(int i=0;i<t[no].size();i++)
	{// 递归求height
		int h = getHeight(t,t[no][i]) + i + 1;
		if( h > max )
			max = h;
	}
	return max;
}

int main()
{	
	//freopen("test4//graft.in","r",stdin);
	//freopen("output.txt","w",stdout);
	int t=0;
	while(1)
	{
		int h1=0,h2=0,height=0,n=0;
		scanf("%s",nodes);
		if( nodes[0] == '#') break;
		t++;

		int pos=0,p=0,q=-1;
		parents[0]=-1;
		while( nodes[pos] != '\0' )
		{// 建立树,得到h1
			char c = nodes[pos];
			if( c == 'd' )
			{
				n++;
				height++;

				q=p;
				p=n;
				parents[p]=q;

				if( height > h1 ) h1 = height;
			}
			else
			{
				p=q;
				q=parents[q];
				height--;
			}
			pos++;
		}// n+1 是节点个数

		for(int k = 0;k<n+1;k++)
			table[k].clear();
		for(int i=1;i<n+1;i++)
		{// 建立对应关系表
			table[ parents[i] ].push_back(i);
		}

		h2 = getHeight(table,0);
		
		//print(n+1);
		//fprintf(stdout,"Tree %d: %d => %d\n",t,h1,h2);
		printf("Tree %d: %d => %d\n",t,h1,h2);
	}
	//fclose(out);
	return 0;
}