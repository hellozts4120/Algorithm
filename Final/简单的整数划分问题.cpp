#include<iostream>
using namespace std;

int fun(int n,int m){
	if(n == 1 || m == 1){
		return 1;
	}
	else if(n == m){
		return 1+fun(n,m - 1);
	}
	else if(n < m){
		return fun(n,n);
	}
	else{
		return fun(n - m,m) + fun(n,m - 1);
	}
}

int main(){
	int N;
	while(cin >> N){
		if(N <= 0 || N > 50){
			break;
		}
		else{
			cout << fun(N,N) << endl;
		}
	}
	return 0;
}
