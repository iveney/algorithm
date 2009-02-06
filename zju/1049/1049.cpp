#include <stdlib.h>
#include <stdio.h>
#include <math.h>
const double PI = 3.1415926;
int main()
{
	int N;
	scanf("%d",&N);
	double Rs[1001];
	int set=0;
	for(int i=1;i<=N;i++)
	{
		double x,y;
		scanf("%lf %lf",&x,&y);
		double len = sqrt(x*x+y*y);
		double R;
		int j;
		for(j=1;j<=1000;j++)
		{
			if( j < set )
			{
				R = Rs[j];
			}
			else
			{
				double area = 50.0*j;
				R = Rs[j] = sqrt(2 * area / PI);
				set = j;
			}
			if( R-len > 0.0 )
				break;
		}
		printf("Property %d: This property will begin eroding in year %d.\n",i,j);
	}
	printf("END OF OUTPUT.\n");
}
