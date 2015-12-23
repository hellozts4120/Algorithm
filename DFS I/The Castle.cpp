#include<iostream>
#include<cstring>
using namespace std;

int map[50][50], color[50][50];
int n,m;
int MaxNum = 0, RoomNum = 0, CurNum;

void DFS(int i, int j){
	color[i][j] = RoomNum;
	CurNum++;
	if(!(map[i][j] & 1) && !color[i][j-1]){
		DFS(i, j-1);
	}
	if(!(map[i][j] & 2) && !color[i-1][j]){
		DFS(i-1, j);
	}
	if(!(map[i][j] & 4) && !color[i][j+1]){
		DFS(i, j+1);
	}
	if(!(map[i][j] & 8) && !color[i+1][j]){
		DFS(i+1, j);
	}
}

int main(){
	memset(color,0,sizeof(color));
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!color[i][j]){
				RoomNum++;
				CurNum = 0;
				DFS(i,j);
				if(CurNum > MaxNum){
					MaxNum = CurNum;
				}
			}
		}
	}
	cout << RoomNum << endl;
	cout << MaxNum << endl;
	return 0;
}