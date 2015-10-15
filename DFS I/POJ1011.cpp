#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

int N,L;
vector<int>anLength;
int nLastStickNo;
int visited[100];	//if used;

bool DFS(int R, int M){		//当前有R根未用木棒，而且当前正在拼的那根棍子比假定的棍子长度还少M
	if(R == 0 && M == 0){
		return true;
	}
	if(M == 0){		//一根刚刚拼完
		M = L;
	}
	int nStartNo = N - 1;
	if(M != L){		//剪枝4：确保已经拼好的部分，长度是从长到短排列的
		nStartNo = nLastStickNo - 1;
	}
	for(int i = nStartNo; i >= 0; i--){
		if(!visited[i] && anLength[i] <= M){
			if(i < N - 1){
				if(visited[i + 1] == 0 && anLength[i] == anLength[i + 1]){
					continue;		//剪枝1：不要在同一个位置多次尝试相同长度的木棒
				}
			}
			visited[i] = 1;
			nLastStickNo = i;
			if(DFS(R - 1,M - anLength[i])){
				return true;
			}
			else{
				visited[i] = 0;		//说明此次还不能用这一根;
				if(M == L || anLength[i] == M){
					return false;	//剪枝2：替换第i根棍子的第一根木棒是没用的
									//剪枝3：仅仅替换已拼好棍子的最后一根木棒无法改变失败的局面
				}
			}
		}
	}
	return false;
}

int main(){
	while(1){
		cin >> N;
		if(N == 0){
			break;
		}
		int minTotalLen = 0;
		nLastStickNo = N - 1;
		anLength.clear();
		for(int i = 0; i < N; i++){
			int temp;
			cin >> temp;
			anLength.push_back(temp);
			minTotalLen += anLength[i];
		}
		sort(anLength.begin(),anLength.end());
		for(L = anLength[N - 1]; L <= minTotalLen / 2; L++){
			if(minTotalLen % L){
				continue;
			}
			memset(visited,0,sizeof(visited));
			if(DFS(N,L)){
				cout << L << endl;
				break;
			}
		}
		if(L > minTotalLen / 2){
			cout << minTotalLen << endl;
		}
	}
	return 0;
}