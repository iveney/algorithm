#include <stdio.h>
#include <sting.h>

int last = 1;
int mul = 1;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			mul = last * i;
		}
	}
}
