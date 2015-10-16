#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int num[105];
int ans[105];
int n,k,result;
bool flag = true;

int cmp( const int &a, const int &b ){
	if( a > b ){
		return 1;
	}
	else return 0;
}

void DFS(int cur,int len,int x){
	if(cur == 0){
		flag = false;
		for(int i = 0; i < len; i++){
			if(i == 0){
				cout << ans[i];
			}
			else{
				cout << "+" << ans[i];
			}
		}
		cout << endl;
		return;
	}
	for(int i = x; i < n; i++){
		if((i == x || num[i] != num[i - 1]) && (cur - num[i]) >= 0){	//¼ôÖ¦
			ans[len] = num[i];
			DFS(cur - num[i],len + 1,i + 1);
		}
	}
}

int main(){
	while(cin >> k >> n){
		memset(num,0,sizeof(num));
		memset(ans,0,sizeof(ans));
		flag = true;
		if(k == 0 && n == 0){
			break;
		}
		for(int i = 0; i < n; i++){
			cin >> num[i];
		}
		sort(num,num + n,cmp);
		cout << "Sum of " << k << ":" << endl;
		DFS(k,0,0);
		if(flag){
			cout << "NONE" << endl;
		}
	}
	return 0;
}