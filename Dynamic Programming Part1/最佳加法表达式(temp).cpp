#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1000
using namespace std;
char str[MAX];
int m,num[MAX][MAX],ans[MAX][MAX];

int main(){
	scanf("%s",str);
	scanf("%d",&m);
	int len = strlen(str);
	if(len - 1 < m){
		return 0;
	}
	for(int i = 0;i < len;i++){
		num[i][i] = int(str[i] - '0');
		if(i){
			num[0][i] = num[0][i - 1] * 10 + int(str[i] - '0');
		}
		ans[i][0] = num[0][i];
	}
	for(int i = 1;i < len;i++){
		for(int j = i + 1;j < len;j++){
			num[i][j] = num[i][j - 1] * 10 + int(str[i] - '0');
		}
	}
	for(int j = 1;j <= m;j++){
		for(int i = 0;i < len;i++){
			for(int k = 0;k < i;k++){
				ans[i][j] = min(ans[i][j],ans[k][j - 1] + num[k + 1][i]);
			}
		}
	}
	printf("%d\n",ans[len - 1][m]);
	return 0;
}
