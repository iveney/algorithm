/*
ID: iveney1 
LANG: C
TASK: castle
*/
#include <stdio.h>

/*
 * 1: wall to the west
 * 2: wall to the north
 * 4: wall to the east
 * 8: wall to the south
 */

#define MAX 52
#define QSIZE MAX*MAX
#define enqueue(a) {\
	queue[tail]=(a);\
	tail=(tail+1)%(QSIZE);\
}

#define pophead() {head=(head+1)%(QSIZE);}
#define isempty() (head==tail)
#define set(p,nr,nc) {(p)->r=(nr);(p)->c=(nc);}

enum DIRS{WEST=1,NORTH=2,EAST=4,SOUTH=8};
char *dir_string[]={"W","N","E","S"};
int dirs[]={1,2,4,8};
int dr[]={0, -1,0,1};
int dc[]={-1,0,1,0};

typedef struct NODE{
	int r,c;
}node;

int M,N;
// index=0,51 is dummy room, color=0, size=0
int wall[MAX][MAX];
int grid[MAX][MAX]; // use for flood fill
node queue[QSIZE];
int in[MAX][MAX];
int head=0;
int tail=0;
int color_size[QSIZE];
int largest_color=0;
int newcolor=0;
int maxcolor=0;

int getNbr(node n,node *p){
	int size=0,i;
	int v = wall[n.r][n.c];
	for(i=0;i<4;i++){
		if( !(v & dirs[i]) ){
			set((p+size), n.r+dr[i], n.c+dc[i]);
			size++;
		}
	}
	return size;
}

void output_colors(){
	int i,j;
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++)
			printf("%3d",grid[i][j]);
		printf("\n");
	}
	for(i=1;i<=maxcolor;i++)
		printf("[%d]=%d\n",i,color_size[i]);
}

int main(){
	freopen("castle.in","r",stdin);
#ifndef LOCAL
	freopen("castle.out","w",stdout);
#endif
	scanf("%d%d",&M,&N); // M is column count, N is row count
	int i,j,k;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			scanf("%d",&wall[i][j]);
	node n,nbrs[4],*p;
	for(i=1;i<=N;i++){// flood fill
		for(j=1;j<=M;j++){
			if( grid[i][j] == 0 ){ // not marked
				// start to flood fill
				newcolor++;
				maxcolor=(maxcolor<newcolor?newcolor:maxcolor);
				n.r = i; n.c = j;
				head=tail=0;
				enqueue(n);
				while( !isempty() ){
					n = queue[head];
					pophead();
					//if( grid[n.r][n.c] == 0 )
					//	printf("some error:%d %d\n",n.r,n.c);
					color_size[newcolor]++;
					grid[n.r][n.c] = newcolor;
					int nbrsize = getNbr(n,nbrs);
					for(k=0;k<nbrsize;k++){
						p = &nbrs[k];
						if(grid[p->r][p->c] == 0 && !in[p->r][p->c] ){
							enqueue(*p);
							in[p->r][p->c] = 1;
						}
					}
				}// end of flood fill
				if( color_size[newcolor]>largest_color )
					largest_color = color_size[newcolor];
			}
		}
	}// all room is colored
	int max_size=0;
	node max_node;
	int max_dir;
	for(j=1;j<=M;j++){
		for(i=N;i>=1;i--){
			int this_color = grid[i][j];
			int this_size = color_size[this_color];
			int nbr_color,nbr_size;
			for(k=1;k<=2;k++){
				if( wall[i][j] & dirs[k] ){ // there is a wall
					nbr_color = grid[i+dr[k]][j+dc[k]];
					if( nbr_color == this_color ) // same room
						break;
					nbr_size = color_size[nbr_color];
					int new_size = this_size+nbr_size;
					if( new_size > max_size ){
						max_size = new_size;
						max_node.r = i;
						max_node.c = j;
						max_dir = k;
					}
				}
			}
		}
	}
	printf("%d\n",maxcolor);
	printf("%d\n",largest_color);
	printf("%d\n",max_size);
	printf("%d %d %s\n",max_node.r,max_node.c,dir_string[max_dir]);
#ifdef LOCAL
	output_colors();
#endif
	return 0;
}
