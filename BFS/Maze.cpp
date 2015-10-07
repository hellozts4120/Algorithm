#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct Point{
	int x;
	int y;
};

int Maze[7][7];
Point Pre[7][7];
Point Move[4] = {{0,1},{0,-1},{1,0},{-1,0}};

void CreatMaze(){
	for(int i = 0; i < 7; i++){
		Maze[0][i] = Maze[6][i] = 1;
	}
	for(int i = 0; i < 7; i++){
		Maze[i][0] = Maze[i][6] = 1;
	}
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			cin >> Maze[i][j];
		}
	}
}

bool MazePath(int r,int c,int x,int y){		//判断是否有路径从入口到出口，保存该路径;
	if(x == r && y == c){
		return true;
	}
	queue<Point> q;
	Point current;
	current.x = x;
	current.y = y;
	q.push(current);
	Maze[current.x][current.y] = -1;
	while(!q.empty()){
		current = q.front();
		for(int i = 0; i < 4; i++){
			if(current.x + Move[i].x == r && current.y + Move[i].y == c){
				Maze[current.x + Move[i].x][current.y + Move[i].y] = -1;
				Pre[r][c] = current;
				return true;
			}
			if(Maze[current.x + Move[i].x][current.y + Move[i].y] == 0){
				Point temp;	//next position;
				temp.x = current.x + Move[i].x;
				temp.y = current.y + Move[i].y;
				q.push(temp);
				Maze[temp.x][temp.y] = -1;
				Pre[temp.x][temp.y] = current;
			}
		}
		q.pop();
	}
	return false;
}

void PrintPath(int r,int c){
	Point temp;
	stack<Point> s;
	temp.x = r;
	temp.y = c;
	while(temp.x != 1 || temp.y != 1){
		s.push(temp);
		temp = Pre[temp.x][temp.y];
	}
	cout << "(0,0)" << endl;
	while(!s.empty()){
		temp = s.top();
		cout << "(" << temp.x - 1 << "," << temp.y - 1 << ")" << endl;
		s.pop();
	}
}

int main(){
	CreatMaze();
	if(MazePath(5,5,1,1)){
		PrintPath(5,5);
	}
	return 0;
}