#include <stdio.h>
#include <math.h>

double min(double a,double b){
	return (a<b)?a:b;
}

class pt{
	public:
		pt(){x=0;y=0;}
		pt(double xx,double yy):x(xx),y(yy){}
		double x,y;
		double dist(const pt & rhs){
			double a=x-rhs.x;
			double b=y-rhs.y;
			return sqrt(a*a+b*b);
		}
		void set(double xx,double yy){x=xx;y=yy;}
};

void partition_y(pt * yl,pt * yr,
		pt * y,int ny,double h){
	int nl,nr;
	nl=nr=0;
	int i;
	for(i=0;i<ny;i++){
		if(
	}
}

double min_dist(pt * lx,pt * ly,int n){
	double minimum;
	int i;
	if( n<=3 ){
		minimum = lx[0].dist(lx[1]);
		if( n == 3 ) {
			double dist02 = lx[0].dist(lx[2]);
			double dist12 = lx[1].dist(lx[2]);
			minimum=min(minimum,dist02);
			minimum=min(minimum,dist12);
		}
		return minimum;
	}
	int pivot = n/2;
	
	return minimum;
}


int main(){

	return 0;
}
/*
	pt t[3];
	t[1].set(8,6);
	t[2].set(0,0);
	t[0].set(9,20);
	printf("%lf\n",min_dist(t,t,2));
	*/
