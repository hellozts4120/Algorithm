#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MM = 210,INFINITY = 100000;

struct Node{
	int x,y,dis;
	friend bool operator<(const Node &a,const Node &b){
		return a.dis > b.dis;	//ע��������>,��Ϊ���ȶ����Ǵ󶥶ѽṹ   
	}
	Node(int X,int Y,int Dis):x(X),y(Y),dis(Dis){};
};

int xe[MM][MM],ye[MM][MM];	 //xe��ʾ�����  ye��ʾ����� 
int dis[MM][MM];	//��ʾ�� 0 0�ľ���
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
		for(int i = 0;i < M;i++){	//��ʼ��ǽ
			cin >> x >> y >> d >> t;
			if(d == 1){
				for(int j = 0;j < t;j++){
					ye[x][y + j] = INFINITY;	//ye[x][y]��ʾ x y+1������;
				}
				mx = max(mx,x);
				my = max(my,t+y);
			}
			else{
				for(int j = 0;j < t;j++){
					xe[x + j][y] = INFINITY;	//xe[x][y]��ʾ x+1 y������;
				}
				mx = max(mx,x);
				my = max(my,t+y);	
			}
		}
		for(int i = 0;i < N;i++){	//��ʼ����
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
		if(xNemo > mx || yNemo > my){	//Nemo����ǽ�ڣ�ֱ�����0
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
		while(!q.empty()){	//��0 0����bfsֱ������Ŀ�ĵ�
			temp_x = q.top().x;
			temp_y = q.top().y;
			q.pop();
			if(temp_x == f_x && temp_y == f_y){		//����Ŀ�ĵ�,�˳�
				flag = 1;
				break;
			}
			if(temp_y+1<=my && dis[temp_x][temp_y+1]>dis[temp_x][temp_y]+xe[temp_x][temp_y+1]){		//������
				dis[temp_x][temp_y+1] = dis[temp_x][temp_y]+xe[temp_x][temp_y+1];
				q.push(Node(temp_x,temp_y+1,dis[temp_x][temp_y+1]));
			}
			if(temp_x+1<=mx && dis[temp_x+1][temp_y]>dis[temp_x][temp_y]+ye[temp_x+1][temp_y]){		//������
				dis[temp_x+1][temp_y] = dis[temp_x][temp_y]+ye[temp_x+1][temp_y];
				q.push(Node(temp_x+1,temp_y,dis[temp_x+1][temp_y]));
			}
			if(temp_y-1>=0 && dis[temp_x][temp_y-1]>dis[temp_x][temp_y]+xe[temp_x][temp_y]){		//�����ߣ���Ҫ
				dis[temp_x][temp_y-1] = dis[temp_x][temp_y]+xe[temp_x][temp_y];	//����+xe[tmp_x][tmp_y-1]
				q.push(Node(temp_x,temp_y-1,dis[temp_x][temp_y-1]));
			}
			if(temp_x-1>=0 && dis[temp_x-1][temp_y]>dis[temp_x][temp_y]+ye[temp_x][temp_y]){	//�����ߣ�ע��ͬ��
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
