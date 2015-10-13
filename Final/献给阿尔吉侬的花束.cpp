#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Node{
	int x,y,step;
	Node(int x_,int y_,int steps):x(x_),y(y_),step(steps){};
};

char map[210][210];
char visited[210][210];
int dir[2][4]={{1,0,0,-1},{0,1,-1,0}};
int X0;
int Y0;

int BFS(int x, int y){
	queue<Node> q;
	q.push(Node(x,y,0));
	visited[x][y] = 1;
	while(!q.empty()){
		Node S = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int tx = S.x + dir[0][i];
			int ty = S.y + dir[1][i];
			int ts = S.step + 1;
			if(visited[tx][ty] || map[tx][ty] == '#'){
				continue;
			}
			if(map[tx][ty] == 'E'){
				return ts;
			}
			if(map[tx][ty] == '.'){
				visited[tx][ty] = 1;
				q.push(Node(tx,ty,ts));
			}
		}
	}
	return -1;
}		

int main(){
	int t;
	int findit = 0;
	cin >> t;
	while(t--){
		findit = 0;
		memset(visited,0,sizeof(visited));
		memset(map,0,sizeof(map));
		int r,c;
		int x,y;
		cin >> r >> c;
		for(int i = 0;i <= r;i++){
			map[i][0] = map[i][c + 1]='#';
		}
		for(int i = 0;i <= c;i++){
			map[0][i] = map[r + 1][i]='#';
		}
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				cin >> map[i][j];
				if(map[i][j] == 'S'){
					x = i;
					y = j;
					map[i][j] = '.';
				}
				if(map[i][j] == 'E'){
					X0 = i;
					Y0 = j;
				}
			}
		}
		findit = BFS(x,y);
		if(findit != -1){
			cout << findit << endl;
		}
		else{
			cout << "oop!" << endl;
		}
	}
	return 0;
}