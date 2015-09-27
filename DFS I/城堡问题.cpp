#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int room[60][60];
int color[60][60];
int maxRoom,currentRoom;
int roomArea;
int row,col;

void DFS(int i,int j){
	if(color[i][j]){
		return;
	}
	++roomArea;
	color[i][j] = currentRoom;
	if((room[i][j] & 1) == 0) DFS(i,j-1);
	if((room[i][j] & 2) == 0) DFS(i-1,j);
	if((room[i][j] & 4) == 0) DFS(i,j+1);
	if((room[i][j] & 8) == 0) DFS(i+1,j);
}
//也可使用栈，从而不使用递归

int main(){
	maxRoom = 0;
	cin >> row >> col;
	for(int i = 1;i <= row;i++){
		for(int j = 1;j <= col;j++){
			cin >> room[i][j];
		}
	}
	memset(color,0,sizeof(color));
	for(int i = 1;i <= row;i++){
		for(int j = 1;j <= col;j++){
			if(color[i][j] == 0){
				++currentRoom;
				roomArea = 0;
				DFS(i,j);
				maxRoom = max(maxRoom,roomArea);
			}
		}
	}
	cout << currentRoom << endl;
	cout << maxRoom << endl;
}