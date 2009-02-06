#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int MAXNUM=1000000;
BYTE num[MAXNUM];
typedef char BYTE;

int main(int argc,char * argv[]){
	if(argc<2) {
		printf("Usage: sieve [n]\n");
		return 1;
	}
	int n=atoi(argv[1]);
	if(n>MAXNUM){
		printf("n < %d\n",MAXNUM);
		return 2;
	}
	memset(num,0,sizeof(num));
	int i,j;
	int sqrn = sqrt(n);
	for(i=2;i<=sqrn;i++){
		if( num[i] == 0 ){// it's a prime
			j=2;
			int mul;
			do{
				mul=i*j;
				num[mul] = 1;
				j++;
			}while(mul <= n);
		}
	}
	for(i=2;i<=n;i++)
		if( num[i] == 0)
			printf("%d\n",i);
	return 0;
}
