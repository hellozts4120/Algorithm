#include<iostream>
using namespace std;
const int MAX = 100010;

int n,k,a[MAX];

bool Check(int x){
	int now = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > x){
			now += (a[i] - x - 1) / (k - 1) + 1;
			if(now > x){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int left,right,mid;
	left = right = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] > right){
			right = a[i];
		}
	}
	cin >> k;
	if(k == 1){
		cout << right << endl;
		return 0;
	}
	while(left <= right){
		mid = (left + right) / 2;
		if(Check(mid)){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	cout << left << endl;
	return 0;
}