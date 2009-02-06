
const int MAX=31;
class ForbiddenStrings{
public:
	long long countNotForbidden(int n){
		int i;
		long long d[6][MAX];
		d[0][1]=d[1][1]=d[2][1]=1;
		d[0][2]=d[1][2]=d[2][2]=1;
		d[3][2]=d[4][2]=d[5][2]=2;

		for(i=3;i<=n;i++){
			d[0][i]=d[0][i-1]+(d[3][i-1]+d[5][i-1])/2;
			d[1][i]=d[1][i-1]+(d[3][i-1]+d[4][i-1])/2;
			d[2][i]=d[2][i-1]+(d[4][i-1]+d[5][i-1])/2;

			d[3][i]=d[3][i-1]+d[0][i-1]+d[1][i-1];
			d[4][i]=d[4][i-1]+d[1][i-1]+d[2][i-1];
			d[5][i]=d[5][i-1]+d[0][i-1]+d[2][i-1];
		}
		long long  out=0;
		//for(i=0;i<6;i++) printf("%lld  ",d[i][n]);
		for(i=0;i<6;i++) out+=d[i][n];
		return out;
	}
};
