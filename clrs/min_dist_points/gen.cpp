#include <stdio.h>
#include <string.h>
#include <time.h>
#include <map>
#define MAXVAL 500
using namespace std;

class pt{
	public:
		int x,y;
};

struct ltpt{
	bool operator()(const pt & s1, const pt & s2) const {
		int a=s1.x*s1.x+s1.y*s1.y;
		int b=s2.x*s2.x+s2.y*s2.y;
		return (a-b)<0;
	}
};



int main(int argc,char * argv[]){
	if(argc<2) return 1;
	int i,n=atoi(argv[1]);
	printf("%d\n",n);
	map<pt,int,ltpt> m;
	srand(time(NULL));
	for(i=0;i<n;i++){
		pt temp;
		do{
			temp.x = rand() % MAXVAL;
			temp.y = rand() % MAXVAL;
		}while(m[temp]);
		m[temp]++;
		printf("%d %d\n",temp.x,temp.y);
	}
	return 0;
}
