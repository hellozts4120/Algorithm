#include<iostream>
using namespace std;

char chess[8][8];
int col[8];
int n,k;
int result;

void DFS(int begin,int chessNum){
	for(int i = 0;i < n;i++){
		if((chess[begin][i] == '#') && (col[i] == 0)){
			if(chessNum == 1){
				result++;
			}
			else{
				col[i] = 1;
				for(int j = begin + 1;j <= n - chessNum + 1;j++){
					DFS(j,chessNum - 1);
				}
				col[i] = 0;
			}
		}
	}
}

int main(){
	while((cin >> n >> k) && !(n == -1 && k == -1)){
		result = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				cin >> chess[i][j];
			}
		}
		for(int i = 0;i < n;i++){
			col[i] = 0;
		}
		for(int i = 0;i <= n - k;i++){
			DFS(i,k);
		}
		cout << result << endl;
	}
	return 0;
}