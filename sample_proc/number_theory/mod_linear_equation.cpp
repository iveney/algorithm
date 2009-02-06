// The Modular Linear Equation
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// the extended version of Euclid
// gets the linear coefficient of a and b
// input: int a,int b : the two number to get GCD
//        int *x,int *y : stores the coefficient
// output:d=gcd(a,b)
int extend_euclid(int a,int b,int *x,int *y){
	if(b==0){
		*x=1; *y=0;
		return a;
	}
	int xx,yy;
	int d = extend_euclid(b, a%b,&xx,&yy);
	*x=yy;
	*y=xx-(a/b)*yy;
	return d;
}

// solves the equation: ax = b (mod n)
// input : a,b,n
// output: a vector of all solutions (mod n)
vector<int> mle(int a,int b,int n){
	int d,x,y;	
	vector<int> sol;
	d = extend_euclid(a,n,&x,&y); // gcd(a,n)
	if( b % d == 0 ){// has solution
		sol = vector<int>(d);// totally d solutions
		int x0=(x*(b/d))% n,step = n/d;
		for(int i=0;i<d;i++){// list every solution
			sol[i] = (x0+i*step) % n;
			// note that C++'s `%' is not equivalent to 
			// the modular's definition
			if(sol[i] < 0) sol[i]+=n;
		}
	}
	return sol;
}

int main(){
	int a,b,n;
	typedef vector<int> IntVector;
	IntVector x;
	IntVector::iterator iter;
	while( cin>>a>>b>>n ){
		x = mle(a,b,n);
		if( x.size() == 0 )
			cout<<"NO solution"<<endl;
		else{
			sort(x.begin(),x.end()); // may want to sort
			for(iter = x.begin();iter!=x.end();iter++){
				cout<<*iter<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
