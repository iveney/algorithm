/*
ID: iveney1 
LANG: C
TASK: runround
*/
#include <stdio.h>
#include <string.h>

int isR(int M){
	int digits[10];
	int used[10];   // 1-9 
	memset(used,0,sizeof(used));
	int tmp=M,n=0,p;
	while(tmp!=0){
		p=tmp%10;
		if( p == 0 || used[p] ) return 0;
		used[p]=1;
		digits[n++]=p;
		tmp/=10;
	}
	int i;
	memset(used,0,sizeof(used));
	for(i=0;i<n/2;i++){
		tmp=digits[i];
		digits[i]=digits[n-i-1];
		digits[n-i-1]=tmp;
	}
	int c=0,cnt=0;
	//printf("testing %d\n",M);
	do{
		if( used[digits[c]] ) break;
		used[digits[c]]=1;
		cnt++;
	//	printf("%d %d\n",c,digits[c]);
		c=(c+digits[c])%n;
	}while(1);
	return (cnt==n && c==0);
}

int main(){
	freopen("runround.in","r",stdin);
#ifndef LOCAL
	freopen("runround.out","w",stdout);
#endif

	int M;
	scanf("%d",&M);
	
	int i;
	for(i=M+1;;i++){
		if( isR(i) ){
			printf("%d\n",i);
			break;
		}
	}

#ifdef LOCAL
	// output sth. here
#endif
	return 0;
}
