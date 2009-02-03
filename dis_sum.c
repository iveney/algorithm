#include <stdio.h>

const int N=100;

int max(int a,int b){return a>b? a:b;}

int main(){
	int a[N];
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);

	int p=a[0],q=0,pi=1,t;
	for(i=1;i<n;i++){
		if( pi == 1 ){
			if( a[i]+q>=q ) {
				if( a[i]+q>=p ){ //max is a[i]+q
					pi=1;
					t=a[i]+q;
				}
				else{ // max is p
					pi=0;
					t=p;
				}
			}
			else{
				if( q>=p ){// max is q
					pi=0;
					t=q;
				}
				else{// max is p
					pi=0;
					t=p;
				}
			}
		}
		else{// compare p is enough
			if( p>=a[i]+p){
				t = p;
				pi= 0;
			}
			else{
				t = a[i]+p;
				pi=1;
			}
		}
		q=p;p=t;
	}

	printf("%d\n",p);

	return 0;
}
