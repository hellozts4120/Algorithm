#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
int K,R,N,L,T,D,S;
struct Road{
	int d,L,t;
};
vector<vector<Road>> cityMap(110);	//�ڽӱ�cityMap[i]�Ǵӵ�i��·�����ĳ��м��� 
int minLen = 1 << 30;	 //��ǰ�ҵ�������·���ĳ��� 
int totalLen;			//�����ߵ�·���ĳ��� 
int totalCost;			//�����ߵ�·���Ļ��� 
int visited[110];		//�����Ƿ��Ѿ��߹��ı�� 
int minL[110][10100];	//minL[i][j]��ʾ��1��i��ģ�����Ϊj�����·�ĳ���  

void DFS(int num){
	if(num == N){
		minLen = min(minLen,totalLen);
		return;
	}
	for(int i = 0;i < cityMap[num].size();i++){
		int d = cityMap[num][i].d;		//s ��·����d 
		if(!visited[d]){
			int cost = totalCost + cityMap[num][i].t;
			if(cost > K){
				continue;
			}
			if(totalLen + cityMap[num][i].L >= minLen || totalLen + cityMap[num][i].L >= minL[d][cost]){
				continue;
			}
			totalLen += cityMap[num][i].L; 
			totalCost +=  cityMap[num][i].t; 
			minL[d][cost] = totalLen;  
			visited[d] = 1;  
			DFS(d);  
			visited[d] = 0;  
			totalCost -=  cityMap[num][i].t; 
			totalLen -= cityMap[num][i].L;
		}
	}
}

int main(){
	cin >> K >> N >> R;
	for(int i = 0;i < R;i++){
		int s;
		Road r;
		cin >> s >> r.d >> r.L >> r.t;
		if(s != r.d){
			cityMap[s].push_back(r);
		}
		for(int i = 0;i < 110;i++){
			for( int j = 0;j < 10100;++j){
				minL[i][j] = 1 << 30;
			}
		}
		memset(visited,0,sizeof(visited));
		totalLen = 0;
		totalCost = 0;
		visited[1] = 1;
		minLen = 1 << 30;
		DFS(1);
		if( minLen < (1 << 30)){
			cout << minLen << endl;
		}
		else cout << "-1" << endl; 
	}
	return 0;
}