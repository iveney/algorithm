#include <stdlib.h>
#include <stdio.h>

int main()
{
	double sum=0.0;
	for(int i=0;i<12;i++)
	{
		double balance;
		scanf("%lf",&balance);
		sum+=balance;
	}
	printf("$%.2lf\n",sum/12.0);
}