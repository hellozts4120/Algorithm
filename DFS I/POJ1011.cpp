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

bool DFS(int R, int M){		//��ǰ��R��δ��ľ�������ҵ�ǰ����ƴ���Ǹ����ӱȼٶ��Ĺ��ӳ��Ȼ���M
	if(R == 0 && M == 0){
		return true;
	}
	if(M == 0){		//һ���ո�ƴ��
		M = L;
	}
	int nStartNo = N - 1;
	if(M != L){		//��֦4��ȷ���Ѿ�ƴ�õĲ��֣������Ǵӳ��������е�
		nStartNo = nLastStickNo - 1;
	}
	for(int i = nStartNo; i >= 0; i--){
		if(!visited[i] && anLength[i] <= M){
			if(i < N - 1){
				if(visited[i + 1] == 0 && anLength[i] == anLength[i + 1]){
					continue;		//��֦1����Ҫ��ͬһ��λ�ö�γ�����ͬ���ȵ�ľ��
				}
			}
			visited[i] = 1;
			nLastStickNo = i;
			if(DFS(R - 1,M - anLength[i])){
				return true;
			}
			else{
				visited[i] = 0;		//˵���˴λ���������һ��;
				if(M == L || anLength[i] == M){
					return false;	//��֦2���滻��i�����ӵĵ�һ��ľ����û�õ�
									//��֦3�������滻��ƴ�ù��ӵ����һ��ľ���޷��ı�ʧ�ܵľ���
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