#include<iostream>
using namespace std;

bool chess[6][6];
bool flag;
int step;
int row[5] = {-1,1,0,0,0};
int col[5] = {0,0,0,1,-1};

bool JudgeEnd(){
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= 4;j++){
			if(chess[i][j] != chess[1][1]){
				return false;
			}
		}
	}
	return true;
}

void FlipChess(int r,int c){
	for(int i = 0;i < 5; i++){
		chess[r + row[i]][c + col[i]] = (!chess[r + row[i]][c + col[i]]);
	}
}

void DFS(int r,int c,int deep){		//此DFS里各种迭代回溯的方法非常重要！！
	if(deep == step){
		flag = JudgeEnd();
		return;
	}
	if(flag || (r == 5)){
		return;
	}

	FlipChess(r,c);		//	Flip Chess!
	if(c < 4){ 
		DFS(r,c + 1,deep + 1);
	}
	else{
		DFS(r + 1,1,deep + 1);
	}

	FlipChess(r,c);		//	If failed, flip back and try again!
	if(c < 4){ 
		DFS(r,c + 1,deep);
	}
	else{
		DFS(r + 1,1,deep);
	}
}

int main(){
	char in;
	for(int i = 0;i < 6;i++){
		chess[0][i] = chess[5][i] = false;
	}
	for(int i = 0;i < 6;i++){
		chess[i][0] = chess[i][5] = false;
	}
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= 4;j++){
			cin >> in;
			if(in == 'b'){
				chess[i][j] = true;
			}
			else{
				chess[i][j] = false;
			}
		}
	}
	for(step = 0;step <= 16;step++){
		DFS(1,1,0);
		if(flag){
			break;
		}
	}
	if(flag){
		cout << step << endl;
	}
	else{
		cout << "Impossible" << endl;
	}
	return 0;
}