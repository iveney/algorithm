/*
ID: iveney1 
LANG: C
TASK: sprime
*/
#include <stdio.h>
#include <math.h>

const int plist[]={1,2,3,5,7,9};
int psize=6;

int isprime(int n) {
	if(n<=1) return 0;
	int i;
	int root = (int) sqrt(n);
	for(i=2;i<=root;i++)
		if( n % i == 0 )
			return 0;
	return 1;
}

int dfs(int num,int depth){
	if( !isprime(num) ) return -1;
	else if(depth <= 0) {
		printf("%d\n",num);
		return num;
	}
	int i,temp;
	for(i=0;i<psize;i++){
		temp = num*10+plist[i];
		//printf("searching %d, depth=%d\n",temp,depth);
		dfs(temp,depth-1);
	}
}

int main(){
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<psize;i++){// 1st level do not use 1
		dfs(plist[i],N-1);
	}

	return 0;
}
