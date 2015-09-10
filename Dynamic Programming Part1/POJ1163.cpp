#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int SaveSum[MAX][MAX];
int n;

/*		����ݹ��Ͷ���		*/

int MaxFind(int i,int j){
	if(SaveSum[i][j] != -1){
		return SaveSum[i][j];
	}
	if(i == n){
		SaveSum[i][j] = D[i][j];
	}
	else
	{
		int x = MaxFind(i + 1,j);
		int y = MaxFind(i + 1,j + 1);
		SaveSum[i][j] = max(x,y) + D[i][j];
	}
	return SaveSum[i][j];
}
 int main()
 {
	 int i,j;
	 cin >> n;
	 for(i = 1;i <= n;i++){
		 for(j = 1;j <= i;j++){
			 cin >> D[i][j];
			 SaveSum[i][j] = -1;
		 }
	 }
	 cout << MaxFind(1,1) << endl;
	 return 0;
 }

 /*		ֱ�ӵ��ƣ�ȡ���ݹ麯��		*/

int main()
{
	int i,j;
	cin >> n;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= i;j++){
			cin >> D[i][j];
		}
	}
	for(i = 1;i <= n;i++){
		SaveSum[n][i] = D[n][i];
	}
	for(i = n - 1;i >= 0;i--){
		for(j = 1;j <= n;j++){
			SaveSum[i][j] = max(SaveSum[i + 1][j],SaveSum[i + 1][j + 1]) + D[i][j];
		}
	}
	cout << SaveSum[1][1] << endl;
	return 0;
}


/*		���ɽ��н�һ���Ŀռ��Ż�������һָ�����SaveSum��ά�����		*/