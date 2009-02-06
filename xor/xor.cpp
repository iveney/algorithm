#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

//random-number generation functor
class ExampleRnd 
{
public:
    size_t operator( )(size_t n) const 
    { return(rand( )%n ); }
};


int main(int argc,char * argv[]){
	srand(time(NULL));
	int n=argv[1][0]-'0';
	int num=atoi(argv[2]);
	vector<int> v(2*n+1);
	int i;
	for(i=0;i<n;i++){
		v[2*i]=i;
		v[2*i+1]=i;
	}
	v[2*n] = num;
	ExampleRnd rnd; //use own functor to shuffle
	random_shuffle(v.begin(),v.end(),rnd);
	vector<int>::iterator iter = v.begin();
	int temp=0;
	while(iter!=v.end()){
		temp ^= *iter;
		cout<< *iter << " ";
		iter++;
	}
	cout<<endl;
	cout<<temp<<endl;

	return 0;
}
