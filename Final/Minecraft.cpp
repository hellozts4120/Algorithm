#include<iostream>
#include<cmath>
using namespace std;

int Fun2(int x){
	int m;
	m = sqrt(x) + 1;
	while(m--){
		if(x % m == 0){
			return (m + (x / m));
		}
	}
}

int Fun(int x){
	int ans;
	ans = x + Fun2(x);
	for(int i = 1; i <= x / 2; i++){
		if(x % i == 0){
			ans = min(ans,x / i + i * Fun2(x / i));
		}
	}
	return ans;
}
int main(){
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << 2 * Fun(n) << endl;		//ans = (最小行+最小列) / 2
	}
	return 0;
}