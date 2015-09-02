#include<cstdio>
#include<memory.h>
#include<cstdlib>
#define MAX 75
char board[MAX + 2][MAX + 2];	//矩形板
bool mark[MAX + 2][MAX + 2];	//标记数组
int minstep;
int w,h;
int turn[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};	//四个转向

void Search(int now_x,int now_y,int end_x,int end_y,int step,int nowturn)
{
	int x,y,i;
	if(step > minstep){		//当前步数大于最小步数，可直接返回（必定不是最优解）
		return;
	}
	if((now_x == end_x) && (now_y == end_y)){
		if(step < minstep){
			minstep = step;
			return;
		}
	}
	for(i = 0;i < 4;i++){
		x = now_x + turn[i][0];
		y = now_y + turn[i][1];		//判断条件：1.在板的有效范围内；2.(x,y)上未有阻挡；3.(x,y)已到达终点  其中1必须满足，2、3足一即可
		if((x >= 0 && x <= w + 1 && y >= 0 && y <= h + 1) && (((board[y][x] == ' ') && (mark[y][x] == false)) || ((x == end_x) && (y == end_y) && (board[y][x] == 'X')))){
			mark[y][x] = true;		//未走过，则此处标记
			if(nowturn == i){		//递归
				Search(x,y,end_x,end_y,step,i);
			}
			else{
				Search(x,y,end_x,end_y,step + 1,i);
			}
			mark[y][x] = false;		//回溯时可继续从此处进军
		}
	}
}

int main()
{
	int Boardnum = 0;
	while(scanf("%d %d",&w,&h)){
		if(w == 0 && h == 0){
			break;
		}
		Boardnum++;
		printf("Board #%d:\n",Boardnum);
		int i,j;
		for(i = 0;i < MAX + 2;i++){
			board[0][i] = ' ';
			board[i][0] = ' ';
		}
		for(i = 1;i <= h;i++){
			getchar();
			for(j = 1;j <= w;j++){
			board[i][j] = getchar();
			}
		}
		for(i = 0;i <= w;i++){
			board[h + 1][i + 1] = ' ';
		}
		for(i = 0;i <= h;i++){
			board[i + 1][w + 1] = ' ';
		}
		int begin_x,begin_y,end_x,end_y,count = 0;
		while(scanf("%d%d%d%d",&begin_x,&begin_y,&end_x,&end_y)){
			if((begin_x == 0) && (begin_y == 0) && (end_x == 0) && (end_y == 0)){break;}
			count++;
			minstep = 999999;
			memset(mark,false,sizeof(mark));
			Search(begin_x,begin_y,end_x,end_y,0,-1);
				if(minstep < 999999){
					printf("Pair %d: %d segments.\n", count, minstep);
				}
				else {
					printf("Pair %d: impossible.\n", count);
				}
		}
		printf("\n");
	}
		system("pause");
		return 0;
}