#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,d;
int x[21],y[21],amount[21];
int Count = 0;
int maxAmount = 0;

void GetPos(){
	for(int i = 0; i <= 1024; i++){
		for(int j = 0; j <= 1024; j++){
			int tempAmount = 0;
			for(int k = 0; k < n; k++){
				if((x[k]>=i-d) && (x[k]<=i+d) && (y[k]>=j-d) && (y[k]<=j+d)){
					tempAmount += amount[k];
				}
				if(tempAmount > maxAmount){
					maxAmount = tempAmount;
					Count = 1;
				}
				else if(tempAmount == maxAmount){
					Count++;
				}
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(amount,0,sizeof(amount));
		cin >> d;
		cin >> n;
		maxAmount = 0;
		Count = 0;
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i] >> amount[i];
		}
		GetPos();
		cout << Count << " " << maxAmount << endl;
	}
	return 0;
}
