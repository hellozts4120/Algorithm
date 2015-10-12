#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX = 1010;

struct Node{
	double left;
	double right;
};

int T,n,d;
Node s[MAX];

bool operator<(const Node &a, const Node &b){
	return a.left < b.left;
}

int solve(){
	int ans;
	double now;
	sort(s,s + n);
	ans = 1;
	now = s[0].right;
	for(int i = 1; i < n; i++){
		if(s[i].left <= now){
			now = min(now,s[i].right);
		}
		else{
			ans++;
			now = s[i].right;
		}
	}
	return ans;
}

int main(){
	int x,y;
	int res;
	bool flag;
	T = 0;
	while(1){
		T++;
		cin >> n >> d;
		if(n == 0 && d == 0){
			break;
		}
		flag = true;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			if(y > d){
				flag = false;
			}
			else{
				s[i].left = x - sqrt(d * d - y * y);
				s[i].right = x + sqrt(d * d - y * y);
			}
		}
		if(flag){
			res = solve();
			cout << "Case " << T << ": " << res << endl;
		}
		else{
			cout << "Case " << T << ": -1" << endl;
		}
	}
	return 0;
}
