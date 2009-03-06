/*
ID: iveney1 
LANG: C
TASK: lamps
*/
#include <stdio.h>
#define MAXN 101

#define sb(n,b) {(n)|=(1<<((b)-1));}
#define ub(n,b) {(n)&=(~(1<<((b)-1)));}

#define op1(a,b) {b=((~(a))&(mask));};

#define op2(a,b) {\
	int k,x=2;\
	b=(a);\
	for(k=0;k<(N)/2;k++){\
		(b)^=x;\
		x<<=2;\
	}\
}

#define op3(a,b) {\
	int k,x=1;\
	b=(a);\
	for(k=0;k<(N+1)/2;k++){\
		(b)^=x;\
		x<<=2;\
	}\
}

#define op4(a,b) {\
	int k,x=1;\
	b=(a);\
	for(k=0;k<=(N-1)/3+1;k++){\
		(b)^=x;\
		x<<=3;\
	}\
}

int N,C;
int ON,onmask;
int OFF,offmask;
int S;
int l[MAXN];
int comb[20];
int cnt[20];
int mask;
void out(int a){
	int i;
	int m = 1;
	for(i=0;i<N;i++){
		printf("%d",((a&m)>0));
		m<<=1;
	}
	printf("\n");
}

// generate all the possible state
void generate(){
	comb[0]=S;      // 0=S
	op1(S,comb[1]); // 1
	op2(S,comb[2]); // 2
	op3(S,comb[3]); // 3
	op4(S,comb[4]); // 4

	op4(comb[1],comb[5]); // 5,1 4
	op4(comb[2],comb[6]); // 6,2 4
	op4(comb[3],comb[7]); // 7,3 4

	//op2(comb[1],comb[5]); // 1 2=3
	//op3(comb[1],comb[6]); // 1 3=2
	//op3(comb[2],comb[8]); // 2 3=1
	//op4(comb[5],comb[10]); // 10, 1 2 4 = 3 4
	//op4(comb[6],comb[11]); // 11, 1 3 4 = 2 4
}

int satisfy(int n){
	if( (n & ON) != ON ) return 0;
	if( ((~n) & OFF) != OFF ) return 0;
	return 1;
}

int main(){
	freopen("lamps.in","r",stdin);
#ifndef LOCAL
	freopen("lamps.out","w",stdout);
#endif

	scanf("%d%d",&N,&C);
	int t;
	do{
		scanf("%d",&t);
		if(t==-1) break;
		ON |= 1<<(t-1);
	}while(1);
	onmask = ON;
	do{
		scanf("%d",&t);
		if(t==-1) break;
		OFF |= 1<<(t-1);
	}while(1);
	offmask = OFF;
	
//	out(ON);
//	out(OFF);

	int i,j=1;
	for(i=0;i<N;i++) {
		mask|=j;
		j<<=1;
	}
	S=0xFFFF & mask;
	generate();
	int impossible=1;
	for(i=0;i<8;i++){
		if( satisfy(comb[i]) ){
			// check if possible
			if( C >= 2 ){
				//printf("%d: ",i);
				out(comb[i]);
				impossible=0;
			}
			else if( C == 1 &&
				(i == 1 || i == 2 || i == 3 || i == 4)){
				out(comb[i]);
				impossible=0;
			}
			else if( i == 0 ){
				out(comb[i]);
				impossible=0;
			}
		}
	}
	if(impossible)
		printf("IMPOSSIBLE\n");
	// output final result

#ifdef LOCAL
	// output sth. here
#endif
	return 0;
}
