#include<iostream>
using namespace std;

const int MAX = 1010;
int input[MAX],Maxlen[MAX];

int main(){
	int n;
	int maxlong;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> input[i];
		Maxlen[i] = 1;
	}
	for(int i = 2;i <= n;i++){
		for(int j = 1;j < i;j++){
			if(input[i] > input[j]){
				Maxlen[i] = max(Maxlen[i],Maxlen[j] + 1);
			}
		}
	}
	maxlong = Maxlen[1];
	for(int i = 1;i <= n;i++){
		if(maxlong < Maxlen[i]){maxlong = Maxlen[i];}
	}
	cout << maxlong << endl;
	return 0;
}