#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=200;
struct path{
	int a,b,c,d;
};

class AvoidRoads{
public:
	long long numWays(int width,int height,vector<string> bad){
		_bad = bad;
		int i,j;
		long long int d[MAX][MAX];
		for(i=0;i<_bad.size();i++){// input the bad block list
			int a,b,c,d;
			//sscanf(bad[i],"%d %d %d %d",&a,&b,&c,&d);
			istringstream sstr(_bad[i].c_str());
			sstr>>a>>b>>c>>d;
			if( c<a || d<b ){// sort the block
				int temp;
				temp=a;a=c;c=temp; 
				temp=d;d=b;b=temp;
			}
			p[i].a=a; p[i].b=b;
			p[i].c=c; p[i].d=d;
			//printf("%d %d %d %d\n",a,b,c,d);
		}

		for(j=0;j<=height;j++) {
			for(i=0;i<=width;i++){
				if(i==0&&j==0)d[j][i]=1;
				else d[j][i]=0;
				if( i-1 >= 0 && !isBad(j,i-1,j,i) ) d[j][i]+=d[j][i-1];
				if( j-1 >= 0 && !isBad(j-1,i,j,i) ) d[j][i]+=d[j-1][i];
			}
		}
		return d[height][width];
	}

	int isBad(int a,int b,int c,int d){ // (a,b) before (c,d)
		int i;
		for(i=0;i<_bad.size();i++) {
			if( a==p[i].a && b==p[i].b &&
					c==p[i].c && d==p[i].d  ){
				return 1;
			}
		}
		return 0;
	}

	struct path p[55];
	vector<string> _bad;
};

int main()
{
	const int width=35;
	const int height=31;
	//const char * bad[]={"5 8 5 9", "8 3 8 4", "2 3 3 3", "2 5 2 4", "4 2 4 3", "3 4 3 3", "1 2 1 1", "9 5 9 4", "5 8 5 9", "8 4 9 4", "5 2 4 2", "5 9 6 9", "9 0 8 0", "2 7 2 6", "9 2 9 1", "6 7 5 7", "0 4 1 4", "8 9 8 10", "1 3 1 4", "2 8 3 8", "5 9 4 9", "7 9 8 9", "4 0 3 0", "1 1 0 1", "1 7 0 7", "7 6 6 6", "4 4 5 4", "1 1 0 1", "6 7 7 7", "6 8 5 8", "5 7 5 8", "9 5 10 5", "2 7 1 7", "3 0 4 0", "9 3 10 3", "9 1 9 0", "4 7 3 7", "6 1 7 1", "9 7 10 7", "7 2 7 1", "2 3 2 2", "7 7 7 6", "2 1 1 1", "1 4 1 5", "1 8 1 9", "2 3 1 3", "6 4 6 3", "4 5 5 5", "4 6 3 6", "0 3 0 2"}  	 	;
	const char * bad[]={};
	static const int n=sizeof(bad)/4; // elements count in bad
	vector<string> b(n);
	for(int i=0;i<n;i++) b[i]=string(bad[i]);

	AvoidRoads ar;
	cout<<ar.numWays(width,height,b)<<endl;
	/*
	   for(j=0;j<=height;j++){
	   for(i=0;i<=height;i++){
	   printf("%25lld",d[j][i]);
	   }
	   printf("\n");
	   }
	   */
	return 0;
}
