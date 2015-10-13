#include<iostream>
#include<cstring>
using namespace std;

int n,k;
int a[51][51][51] = {0};
int m[51][51][51] = {0};
int l[51][51][51] = {0};

int Fun1(int n, int k, int b){	//第三个参数b表示最小的参数应该大于或者等于b;
	if(a[n][k][b] != 0){
		return a[n][k][b];
	}
	if(k == 1 && n >= b){
		return 1;
	}
	if((n / k) < b){
		return 0;
	}
	for(int i = b; i <= n; i++){
		int temp = Fun1(n - i, k - 1, i);
		a[n][k][b] += temp;
		if(temp == 0){
			break;
		}
	}
	return a[n][k][b];
}

int Fun2(int n, int k, int b){
	if(m[n][k][b] != 0){
		return m[n][k][b];
	}
	if(k == 1 && n >= b){
		return 1;
	}
	if((n / k) < b){
		return 0;
	}
	for(int i = b; i <= n; i++){
		int temp = Fun2(n - i, k - 1, i + 1);
		m[n][k][b] += temp;
		if(temp == 0){
			break;
		}
	}
	return m[n][k][b];
}

int Fun3(int n, int k, int b){	
	if(l[n][k][b] != 0){
		return l[n][k][b];
	}
	if(k == 1 && n >= b && (n % 2 == 1)){
		return 1;
	}
	else if(k == 1 && (n % 2) == 0){
		return 0;
	}
	if((n / k) < b){
		return 0;
	}
	for(int i = b; i <= n; i += 2){
		int temp = Fun3(n - i, k - 1, i);
		l[n][k][b] += temp;
		if(temp == 0){
			break;
		}
	}
	return l[n][k][b];
}

int main(){
	while(cin >> n >> k){
		memset(a,0,sizeof(a));
		memset(m,0,sizeof(m));
		memset(l,0,sizeof(l));

		cout << Fun1(n,k,1) << endl;
		int temp = 0;
		for(int i = 1; i <= n; i++){
			temp += Fun2(n,i,1);
		}
		cout << temp << endl;
		int temp1 = 0;
		for(int i = 1; i <= n; i++){
			temp1 += Fun3(n,i,1);
		}
		cout << temp1 << endl;
	}
	return 0;
}

