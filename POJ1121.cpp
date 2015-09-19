#include<cstdio>
#include<cstring>
unsigned answer[251][251];

int main(){			//×´Ì¬·½³Ì: s[i][j] = s[i-2*j][j] + s[i][j+1];(1<=j<=i/2);
	//freopen("in(1).txt","r",stdin);
	//freopen("out11.txt","w",stdout);
	int n;
	for(int i = 1;i <= 250;i++){
		answer[0][i] = 1;
		for(int j = i/2 + 1;j <= i;j++){
			answer[i][j] = 1;
		}
	}
	for(int i = 2;i <= 250;i++){
		for(int j = i/2;j > 0;j--){
			answer[i][j] = answer[i-2*j][j] + answer[i][j+1];
		}
	}
	while(scanf("%d",&n) && n){
		printf("%d %u\n",n,answer[n][1]);
	}
	return 0;
}
