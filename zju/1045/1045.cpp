#include <stdio.h>
#include <stdlib.h>

int main()
{
	double len;
	double ep=0.001;
	do
	{
		scanf("%lf",&len);
		if( len < ep )
			break;
		int i=0;
		double sum=0;
		while(sum < len)
		{
			i++;
			sum+=1.0/(1.0+i);
		}
		printf("%d card(s)\n",i);
	}while(1);
}