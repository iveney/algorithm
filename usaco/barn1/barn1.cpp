/*
ID: iveney1
PROG: milk1
LANG: C++
*/
#include <stdio.h>

int M,S,C;
char stall[210];

int main()
{
	freopen("milk1.in","r",stdin);
	//freopen("milk1.out","w",stdout);
	scanf("%d%d%d",&M,&S,&C);
	int i;
	for(i=0;i<C;i++)
	{
		int temp;
		scanf("%d",&temp);
		stall[temp] = 1;
	}

	int count = 0;
	i=1;
	while( i<=S )
	{
		if(stall[i] == 0)
			count++;
		i++;
	}
	//while( i<=S )
	//{
	//	// search for next occupy
	//	while( i<=S && stall[i] == 1 )
	//		i++;
	//	// search for next empty
	//	while( i<=S && stall[i++] == 0 )
	//		count++;
	//}
	printf("%d\n",count);

	return 0;
}