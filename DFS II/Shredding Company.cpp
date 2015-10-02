#include<iostream>
#include<cstring>
using namespace std;

char str[10];
int len,maxNum,sum,tar;
int v[10],vt[10];
int dis[1000000];

void Dfs(int x,int m,int cap){
	int i,y,flag;
	if(x > len-1){
		flag = 1;
		for(i = 0;i < cap;i++)
			if(vt[i] != v[i]) flag=0;
		if(maxNum < m){
			maxNum = m;
			sum = cap;
			for(i = 0;i < cap;i++) vt[i] = v[i];
		}
		if(flag == 0) 
			dis[m]++;
		return;
	}
	y = 0;
	for(i = x;i < len;i++){
		y = y * 10 + (str[i] - '0');
		if(y + m <= tar){
			v[cap] = y;
			Dfs(i + 1,y + m,cap + 1);
		}
		else break;
	}
}


int main(){
	while(cin >> tar >> str){
		int s = 0;
		len = strlen(str);
		memset(vt,0,sizeof(vt));
		memset(v,0,sizeof(v));
		memset(dis,0,sizeof(dis));
		if(tar == 0 && str[0] == '0' && len == 1){
			break;
		}
		for(int i = 0;i < len;i++){
			s += str[i] - '0';
		}
		if(s > tar){
			cout << "error" << endl;
			continue;
		}
		maxNum = 0;
		sum = 0;
		Dfs(0,0,0);
		if(dis[maxNum] != 1){
			cout << "rejected" ;
		}
		else{
			cout << maxNum;
			for(int i = 0; i < sum; i++){
				cout << " " << vt[i];
			}
		}
		cout << endl;
	}
	return 0;
}
