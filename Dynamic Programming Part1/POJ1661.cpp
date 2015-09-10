#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define BoardMax 1000
#define MAXIUM 1000000
using namespace  std;

int  x,y,n,t,maxHigh;		//四个输入的常数

struct Board{
	int Llong,Rlong,high;
	bool operator<(const Board & a){
		return high > a.high;
	}
};

Board board[BoardMax + 5];
int leftMinTime[BoardMax + 5];
int rightMinTime[BoardMax + 5];
int L[BoardMax + 5];

int MinTime(int l,bool bLeft){
	int y = board[l].high;	//bLeft:确定是执行左侧走还是右侧走
	int x;
	if(bLeft){
		x = board[l].Llong;
	}
	else
		x = board[l].Rlong;
	int i;
	for(i = l + 1;i <= n;i++){
		if(board[i].Llong <= x && board[i].Rlong >= x){
			break;		//此次下落恰好落到某块板子上
		}
	}
	if(i <= n){
		if(y - board[i].high > maxHigh){
			return MAXIUM;	//板间隔过大时判定失败
		}
	}
	else{
		if(y > maxHigh){
			return MAXIUM;	//此时直接落地，若高度过大，判断失败
		}
		else return y;
	}
	int nLeftTime = y - board[i].high + x - board[i].Llong;
	int nRightTime = y - board[i].high + board[i].Rlong - x;
	if(leftMinTime[i] == -1){
		leftMinTime[i] = MinTime(i,true);
	}
	if(L[i] == -1){
		L[i] = MinTime(i,false);
	}
	nLeftTime += leftMinTime[i];
	nRightTime += L[i];
	if(nLeftTime < nRightTime)	return nLeftTime;
	else return nRightTime;
}

int main(){
	cin >> t;
	for(int i = 0;i < t;i++){
		memset(leftMinTime,-1,sizeof(leftMinTime));
		memset(L,-1,sizeof(rightMinTime));
		scanf("%d%d%d%d",&n,&x,&y,&maxHigh);
		board[0].Llong = x;
		board[0].Rlong = x;
		board[0].high = y;
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&board[i].Llong,&board[i].Rlong,&board[i].high);
		}
		sort(board,board + n + 1);
		printf("%d\n",MinTime(0,true));
	}
	return 0;
}