#include<cstdio>
#include<cstring>

int max(int a,int b){
	return (a>b?a:b);
}

int main(){		//背包问题，通解公式:c[j]=max(c[j],c[j-w[i]]+p[i]);
	int n,m;
	int w[5000],d[5000];
	int answer[20000];
	memset(answer,0,sizeof(answer));
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&w[i],&d[i]);
	}
	for(int i = 1;i <= n;i++){
		for(int j = m;j >= w[i];j--){
			answer[j] = max(answer[j],answer[j - w[i]] + d[i]);
		}
	}
	printf("%d\n",answer[m]);
	return 0;
}