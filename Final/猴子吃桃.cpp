#include<iostream>
using namespace std;

int main(){
	int n,num,i,s;
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}
		for(num = n-1; num <= 2147483647; num++){
			s = num;
			for(i = 1; i < n; i++){
				s = s * n + 1;
				if(s % (n-1)){
					break;
				}
				else{
					s = s / (n - 1);
				}
			}
			if(i == n){
				cout << s * n + 1 << endl;
				break;
			}
		}
	}
	return 0;
}