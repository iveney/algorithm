/*
ID: iveney1 
LANG: C
TASK: pprime
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define PRINT() {if( sum>=a && sum<=b && isprime(sum) ) printf("%d\n",sum);}

int isprime(int n)
{
	if(n<=1) return 0;
	int i;
	int root = (int) sqrt(n);
	for(i=2;i<=root;i++)
		if( n % i == 0 )
			return 0;
	return 1;
}

int count(int n){
	int c=1;
	while(n/10>0) {
		c++;
		n/=10;
	}
	return c;
}

char buf[10];
int d[10];
int t[]={
	0,
	1,	// 1
	10,
	1E2,
	1E3,
	1E4,	// 5
	1E5,
	1E6,
	1E7,
	1E8,
	1E9,   // 9
};

int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	int a,b;
	scanf("%d %d",&a,&b);
	int i=0;
	int sum=0;
	int c1=count(a);
	int c2=count(b);
	//printf("c1,c2=%d %d\n",c1,c2);
	for(i=c1;i<=c2;i++){// digit count
		for(d[1]=0;d[1]<=9;d[1]++) {
			sum = d[1];
			if(i<2){
				PRINT();
			}
			else if(i==2){
				sum = d[1]*10+d[1];
				PRINT();
			}
			else{
				for(d[2]=0;d[2]<=9;d[2]++) {
					sum = d[1]*100+d[2]*10+d[1];
					if(i<4){
						PRINT();
					}
					else if(i==4){
						sum = d[1]*1000+d[2]*100+d[2]*10+d[1];
						PRINT();
					}
					else{
						for(d[3]=0;d[3]<=9;d[3]++) {
							sum = d[1]*10000+d[2]*1000+d[3]*100+d[2]*10+d[1];
							if(i<6){
								PRINT();
							}
							else if(i==6){
								sum = d[1]*1E5+d[2]*1E4+d[3]*1E3+
								      d[3]*1E2+d[2]*1E1+d[1];
								PRINT();
							}
							else{
								for(d[4]=0;d[4]<=9;d[4]++) {
									sum = d[1]*1E6+d[2]*1E5+d[3]*1E4+
										d[4]*1E3+d[3]*1E2+d[2]*10+d[1];
									if(i<8){
										PRINT();
									}
									else if(i==8){
										sum = d[1]*1E7+d[2]*1E6+d[3]*1E5+d[4]*1E4+
										      d[4]*1E3+d[3]*1E2+d[2]*1E1+d[1];
										PRINT();
									}
									else{
										for(d[5]=0;d[5]<=9;d[5]++) {
											sum = d[1]*1E8+d[2]*1E7+
												d[3]*1E6+d[4]*1E5+
												d[5]*1E4+d[4]*1E3+
												d[3]*1E2+d[2]*10+d[1];
											PRINT();
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
