#include<iostream>
#include<cstring>
using namespace std;

char map[25][25];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int W,H,result;

void DFS(int x, int y){
	map[x][y] = '#';
	int tx,ty;
	for(int i = 0; i < 4; i++){
		tx = x + dir[i][0];
		ty = y + dir[i][1];
		if(tx >= 0 && ty >= 0 && tx < H && ty < W && map[tx][ty] == '.'){
			DFS(tx,ty);
			result++;
		}
	}
}

int main(){
	int x,y;
	while(cin >> W >> H){
		if(W == 0 && H == 0){
			break;
		}
		memset(map,0,sizeof(map));
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				cin >> map[i][j];
				if(map[i][j] == '@'){
					x = i;
					y = j;
				}
			}
		}
		result = 1;
		DFS(x,y);
		cout << result << endl;
	}
	return 0;
}