#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100100;
int stall[MAX];
int N,C;

bool Greed(int x){
	int count = 0;
	int temp = stall[0];
	for(int i = 0; i < N; i++){
		if(stall[i] > temp + x){
			count++;
			temp = stall[i];
		}
	}
	if(count >= C - 1){
		return true;
	}
	else return false;
}

int main(){
	int result = 0;
	int left,right,mid;
	cin >> N >> C;
	for(int i = 0; i < N; i++){
		cin >> stall[i];
	}
	sort(stall,stall + N);
	left = 0;
	right = (stall[N-1] - stall[0]) / (C - 1);
	while(left <= right){
		mid = (left + right) / 2;
		if(Greed(mid)){		//mid能够放下C只羊，则最大间隔大于等于mid；
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	cout << left << endl;
	return 0;
}
