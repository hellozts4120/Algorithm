#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,vis[30][30],sum,path[30][2],f;
int dir[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
void dfs(int x,int y)
{
	vis[x][y]=1;
	sum++;
	path[sum][0]=x;
	path[sum][1]=y;
	if(sum==n*m)
	{
		for(int i=1;i<=sum;i++)
			printf("%c%d",path[i][0]+'A',path[i][1]+1);
		printf("\n");
		f=1;
		return ;
	}
	for(int i=0;i<8;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(xx<0||yy<0||xx>=n||yy>=m||vis[xx][yy])
			continue;
		dfs(xx,yy);
		if(f)
			return;
		sum--;
		vis[xx][yy]=0;
	}
}
int main(void)
{
	int t;
	scanf("%d",&t);
	int k;
	for(k=1;k<=t;k++)
	{
		if(k!=1)
			printf("\n");
		scanf("%d%d",&m,&n);
		memset(vis,0,sizeof(vis));
		sum=0;
		printf("Scenario #%d:\n",k);
		f=0;
		dfs(0,0);
		if(!f)
			printf("impossible\n");
	}
}