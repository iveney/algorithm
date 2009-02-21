/*
ID: iveney1 
LANG: C
TASK: hamming
*/
// just use dfs search
//
#include <stdio.h>

#define MAXB (8)
#define MAXL (1<<8)
#define MAXNUM 	MAXL
#define MAXN (64)
#define MAXD (7)

int N,B,D;
int arr[MAXL];
int l=0;

int hamdist(int a,int b){
	int c = a^b;
	int n=0;
	while( c>0 ){
		if( (c & 1) ) n++;
		c>>=1;
	}
	return n;
}

int valid(int a){
	int i;
	for(i=0;i<l;i++){
		if(hamdist(a,arr[i]) < D)
			return 0;
	}
	return 1;
}

int search(int num){
	if( valid(num) ){
		arr[l++] = num;
		if(l == N)
			return 1;
		int i;
		for(i=num+1;i<MAXNUM;i++){
			if( search(i) ) return 1;
		}
		l--;
		return 0;
	}
	else
		return 0;
}

void output(){
	int i;
	int line=0;
	for(i=0;i<l;i++){
		printf("%d",arr[i]);
		if((i+1)%10==0) printf("\n");
		else if( i!= l-1 ) printf(" ");
	}
	if( (i) % 10 != 0 )printf("\n");
}

int main(){
	freopen("hamming.in","r",stdin);
#ifndef LOCAL
	freopen("hamming.out","w",stdout);
#endif
	scanf("%d%d%d",&N,&B,&D);

	int i;
	for(i=0;i<MAXNUM;i++)
		if( search(i) ){
			output();
			break;
		}

#ifdef LOCAL
	// output sth. here
#endif
	return 0;
}
