#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MM = 210,INFINITY = 100000;

struct Node{
	int x,y,dis;
	friend bool operator<(const Node &a,const Node &b){
		return a.dis > b.dis;	//注意这里是>,因为优先队列是大顶堆结构   
	}
	Node(int X,int Y,int Dis):x(X),y(Y),dis(Dis){};
};

int xe[MM][MM],ye[MM][MM];	 //xe表示横向边  ye表示纵向边 
int dis[MM][MM];	//表示到 0 0的距离
int f_x,f_y;
priority_queue<Node> q;

int main(){
	int M,N;
	cin >> M >> N;
	while(M != -1 || N != -1){
		memset(xe,0,sizeof(xe));
		memset(ye,0,sizeof(ye));
		int x,y,d,t;
		int mx,my;
		mx = my = 0;
		for(int i = 0;i < M;i++){	//初始化墙
			cin >> x >> y >> d >> t;
			if(d == 1){
				for(int j = 0;j < t;j++){
					ye[x][y + j] = INFINITY;	//ye[x][y]表示 x y+1这条边;
				}
				mx = max(mx,x);
				my = max(my,t+y);
			}
			else{
				for(int j = 0;j < t;j++){
					xe[x + j][y] = INFINITY;	//xe[x][y]表示 x+1 y这条边;
				}
				mx = max(mx,x);
				my = max(my,t+y);	
			}
		}
		for(int i = 0;i < N;i++){	//初始化门
			cin >> x >> y >> d;
			if(d == 1){
				ye[x][y + 1] = 1;
				mx = max(mx,x);
				my = max(my,1+y);
			}
			else{
				xe[x + 1][y] = 1;
				mx = max(mx,x+1);
				my = max(my,y);
			}
		}
		float xNemo,yNemo;
		cin >> xNemo >> yNemo;
		if(xNemo > mx || yNemo > my){	//Nemo不在墙内，直接输出0
			cout << "0" << endl;
			continue;
		}
		f_x = int(xNemo);
		f_y = int(yNemo);
		for(int i = 0;i <= mx;i++){
			for(int j = 0;j <= my;j++){
				dis[i][j] = INFINITY;
			}
		}
		dis[0][0] = 0;
		int temp_x,temp_y;
		int flag = 0;
		while(!q.empty()){
			q.pop();
		}
		q.push(Node(0,0,0));
		while(!q.empty()){	//从0 0出发bfs直到到达目的地
			temp_x = q.top().x;
			temp_y = q.top().y;
			q.pop();
			if(temp_x == f_x && temp_y == f_y){		//到达目的地,退出
				flag = 1;
				break;
			}
			if(temp_y+1<=my && dis[temp_x][temp_y+1]>dis[temp_x][temp_y]+xe[temp_x][temp_y+1]){		//向上走
				dis[temp_x][temp_y+1] = dis[temp_x][temp_y]+xe[temp_x][temp_y+1];
				q.push(Node(temp_x,temp_y+1,dis[temp_x][temp_y+1]));
			}
			if(temp_x+1<=mx && dis[temp_x+1][temp_y]>dis[temp_x][temp_y]+ye[temp_x+1][temp_y]){		//向右走
				dis[temp_x+1][temp_y] = dis[temp_x][temp_y]+ye[temp_x+1][temp_y];
				q.push(Node(temp_x+1,temp_y,dis[temp_x+1][temp_y]));
			}
			if(temp_y-1>=0 && dis[temp_x][temp_y-1]>dis[temp_x][temp_y]+xe[temp_x][temp_y]){		//向下走，重要
				dis[temp_x][temp_y-1] = dis[temp_x][temp_y]+xe[temp_x][temp_y];	//不是+xe[tmp_x][tmp_y-1]
				q.push(Node(temp_x,temp_y-1,dis[temp_x][temp_y-1]));
			}
			if(temp_x-1>=0 && dis[temp_x-1][temp_y]>dis[temp_x][temp_y]+ye[temp_x][temp_y]){	//向左走，注意同上
				dis[temp_x-1][temp_y] = dis[temp_x][temp_y]+ye[temp_x][temp_y];
				q.push(Node(temp_x-1,temp_y,dis[temp_x-1][temp_y]));
			}
		}
		if(flag){
			cout << dis[f_x][f_y] << endl;
		}
		else{
			cout << "-1" << endl;
		}
	}
	return 0;
}
