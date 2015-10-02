#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

short rowFlags[9][10];
short colFlags[9][10];
short blockFlags[9][10];
int board[9][9];

struct Pos{
	int r,c;
	Pos(int r1,int c1):r(r1),c(c1){};
};

vector<Pos>blankPos;

inline int GetBoardNum(int r,int c){	//由行，列号求得块号
	int r1 = r / 3;
	int c1 = c / 3;
	return (r1 * 3 + c1);
}

void SetAllFlags(int i,int j,int num,int f){	//把num放在 (i,j)位置，设置相应标记，或从 (i,j)取走num, 清除相应标记 
	rowFlags[i][num] = f;
	colFlags[j][num] = f;
	blockFlags[GetBoardNum(i,j)][num] = f;
}

bool isOk(int i,int j,int num){		//看num能否放在 i,j位置 
	return (!rowFlags[i][num] && !colFlags[j][num] && !blockFlags[GetBoardNum(i,j)][num]);
}

bool Dfs(int n){	//处理前n个空格
	if(n < 0){
		return false;
	}
	int r = blankPos[n].r;
	int c = blankPos[n].c;
	for(int num = 1;num <= 9;num++){
		if(isOk(r,c,num)){
			board[r][c] = num;
			SetAllFlags(r,c,num,1);
			if(Dfs(n-1)){
				return true;
			}
			SetAllFlags(r,c,num,0);
		}
	}
	return false;
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		memset(rowFlags,0,sizeof(rowFlags));
		memset(colFlags,0,sizeof(colFlags));
		memset(blockFlags,0,sizeof(blockFlags));
		blankPos.clear();
		for(int i = 0;i < 9;i++){
			for(int j = 0;j < 9;j++){
				char in;
				cin >> in;
				board[i][j] = in - '0';
				if(board[i][j]){
					SetAllFlags(i,j,board[i][j],1);
				}
				else{
					blankPos.push_back(Pos(i,j));
				}
			}
		}
		Dfs(blankPos.size() - 1);
		for(int i = 0;i < 9;i++){
			for(int j = 0;j < 9;j++){
				cout << board[i][j];
			}
			cout << endl;
		}	
	}
	return 0;
}