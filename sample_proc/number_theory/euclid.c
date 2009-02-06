// recursive Euclid and non-recursive Euclid
// GCD recursion theorem:
// gcd(a,b) = gcd(b, a mod b)
// gcd(a,b) = gcd(|a|,|b|)
#include <stdio.h>
#define abs(x) (x<0?(-x):(x))

// recursive version of Euclid
// @parameter
// a: integer
// b: integer
// return their greatest common divisor
int euclid_recur(int a,int b){
	a=abs(a);
	b=abs(b);
	if( b == 0 )
		return a; // gcd(a,0) = a
	return euclid_recur(b,a % b);
}

// same as euclid_recur, but iterative
int euclid_nonrecur(int a,int b){
	a=abs(a);
	b=abs(b);
	if( a < b ){
		int t = a;
		a=b;
		b=t;
	}
	while( b != 0 ){
		int t = a;
		a = b;
		b = t % b;
	}
	return a;
}

// the extended version of Euclid
// gets the linear coefficient of a and b
// input: int a,int b : the two number to get GCD
//        int *x,int *y : stores the coefficient
// output:d=gcd(a,b)
int extend_euclid(int a,int b,int *x,int *y){
	if(b==0){
		*x=1;
		*y=0;
		return a;
	}
	int xx,yy;
	int d = extend_euclid(b, a%b,&xx,&yy);
	*x=yy;
	*y=xx-(a/b)*yy;
	return d;
}

int main(){
	int a,b;
	while( scanf("%d%d",&a,&b) != EOF ){
		int d,x,y;
		d=extend_euclid(a,b,&x,&y);
		printf("%d %d %d\n",d,x,y);
	}
	return 0;
}
