#include<iostream>
#include<cstring>
using namespace std;

int map[105][105];
int m,n;
int cur;

struct Node{
	int l,r;
	char direction;
}step[10010];

bool move(int &x, int &y, char dir){
	if(dir == 'L'){
		if(y >= 1 && !map[x][y-1]){
			y--;
			return true;
		}
		return false;
	}
	else if(dir == 'R'){
		if(y < m-1 && !map[x][y+1]){
			y++;
			return true;
		}
		return false;
	}
	else if(dir == 'U'){
		if(x >= 1 && !map[x-1][y]){
			x--;
			return true;
		}
		return false;
	}
	else{
		if(x < n-1 && !map[x+1][y]){
			x++;
			return true;
		}
		return false;
	}
}

int DFS(int x, int y, int depth){
	if(x<0 || x>=n || y<0 || y>=m || map[x][y]){
		return 0;
	}
	if(depth == cur){
		return 1;
	}
	char ch = step[depth].direction;
	int i;
	int tx = x, ty = y;
	for(i = 1; i < step[depth].l; i++){
		if(!move(tx,ty,ch)){
			return 0;
		}
	}
	for(; i <= step[depth].r; i++){
		if(move(tx,ty,ch)){
			if(DFS(tx,ty,depth+1)){
				return 1;
			}
		}
		else{
			break;
		}
	}
	return 0;
}

int main(){
	int cases;
	int count;
	cin >> cases;
	while(cases--){
		count = 0;
		cur = 0;
		int a,b;
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> map[i][j];
			}
		}
		while(cin >> a >> b){
			if(!a && !b){
				break;
			}
			step[cur].l = a;
			step[cur].r = b;
			cin >> step[cur].direction;
			cur++;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				count += DFS(i, j, 0);
			}
		}
		cout << count << endl;
	}
	return 0;
}