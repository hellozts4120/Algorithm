#include<iostream>
using namespace std;

int gcd(int a, int b){
	int max = (a>b)?a:b;
	int min = (a<b)?a:b;
	int temp = max % min;
	if(temp){
		return gcd(min,temp);
	}
	else{
		return min;
	}
}

int main(){
	int M,N;
	int count = 0;
	while(cin >> M >> N){
		count++;
		if(M == 0 || N == 0 || count > 40000){
			break;
		}
		cout << gcd(M,N) << endl;
	}
	return 0;
}