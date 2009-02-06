#include <stdio.h>

int main()
{
	int t;
	int n;
	scanf("%d",&t);
	for(int s=0;s<t;s++)
	{
		scanf("%d",&n);
		int min=100;
		int max=-1;
		for(int i=0;i<n;i++){
			int temp;
			scanf("%d",&temp);
			if( min>temp ) min = temp;
			if( max<temp ) max = temp;
		}
		printf("%d\n",(max-min)*2);

	}
}
