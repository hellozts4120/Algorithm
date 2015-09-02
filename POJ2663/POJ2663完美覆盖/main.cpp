#include<cstdio>
#include<iostream>
using namespace std;

int main()		//Caution: n=0,ans=1;
{
	int n,i,j;
	int domino[31];
	domino[0] = 1;
	domino[2] = 3;
	for(i = 4;i <= 30;i += 2){						//两种情况：1、不相连3*a[n-2];2、相连2*(a[n-4]+a[n-6]+...+a[0])
		domino[i] =	3 * domino[i - 2];				//化简后a[n]= 4*a[n-2] - a[n-4]
		for(j = 0;j <= i - 4;j += 2){
			domino[i] += domino[j] * 2;
		}
	}
	while(cin >> n){
		if(n == -1){
			break;
		}
		if(n % 2 != 0){
			printf("0\n");
		}
		else cout << domino[n] <<endl;
	}
	return 0;
}
