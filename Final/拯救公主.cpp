#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

char map[210][210];
int Door[11][2];
int CountDoor = 0;
int DiamondNum;
int visited[210][210][1 << 5 - 1];
int R,C,K;
int dir[2][4]={{1,0,0,-1},{0,1,-1,0}};
int MinTime;

struct Node{
	int x,y,step,key;
	Node(int x_,int y_,int step_,int key_):x(x_),y(y_),step(step_),key(key_){};
};

bool Check(int tk){
	int count = 0;
	for(int i = 0; i <= 5; i++){
		if((tk >> i) & 1){
			count++;
		}
	}
	if(count >= K){
		return true;
	}
	else{
		return false;
	}
}

int BFS(int x,int y){
	queue<Node>q;
	visited[x][y][0] = 1;
	q.push(Node(x,y,0,0));
	while(!q.empty()){
		Node S = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int tx = S.x + dir[0][i];
			int ty = S.y + dir[1][i];
			int ts = S.step + 1;
			int tk = S.key;
			if(visited[tx][ty][tk] || map[tx][ty] == '#' || tx < 0 || ty < 0 || tx >= R || ty >= C){
				continue;
			}
			if(map[tx][ty] == 'E'){
				if(Check(tk)){
					return ts;
				}
			}
			if(isdigit(map[tx][ty])){
				visited[tx][ty][tk] = 1;
				tk=tk | (1 << (map[tx][ty] - '0'));
				q.push(Node(tx,ty,ts,tk));
			}
			if(map[tx][ty] == '.'){
				visited[tx][ty][tk] = 1;
				q.push(Node(tx,ty,ts,tk));
			}
			if(map[tx][ty] == '$'){
				visited[tx][ty][tk] = 1;
				q.push(Node(tx,ty,ts,tk));
				for(int j = 0; j < CountDoor; j++){
					tx = Door[j][0];
					ty = Door[j][1];
					if(!visited[tx][ty]){
						visited[tx][ty][tk] = 1;
						q.push(Node(tx,ty,ts,tk));
					}
				}
			}
		}
	}
	return -1;
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int x,y;
		CountDoor = 0;
		DiamondNum = 0;
		CountDoor = 0;
		memset(Door,0,sizeof(Door));
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));
		cin >> R >> C >> K;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C;j++){
				cin >> map[i][j];
				if(isdigit(map[i][j])){
					DiamondNum++;
				}
				if(map[i][j] == '$'){
					Door[CountDoor][0] = i;
					Door[CountDoor][1] = j;
					CountDoor++;
				}
				if(map[i][j] == 'S'){
					x = i;
					y = j;
					map[i][j] = '.';
				}
			}
		}
		if(K > DiamondNum){
			cout << "oop!" << endl;
			continue;
		}
		int result = BFS(x,y);
		if(result == -1){
			cout << "oop!" << endl;
		}
		else{
			cout << result << endl;
		}
	}
	return 0;
}