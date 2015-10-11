#include<iostream>
using namespace std;

int C[10005],Y[10005];

int main(){
	long long result = 0;
	int N,S;
	cin >> N >> S;
	for(int i = 0; i < N; i++){
		cin >> C[i] >> Y[i];
	}
	result = C[0] * Y[0];
	for(int i = 1; i < N;i++){
		if(C[i - 1] + S < C[i]){
			result += (C[i - 1] + S) * (Y[i]);
		}
		else{
			result += C[i] * Y[i];
		}
	}
	cout << result << endl;
	return 0;
}