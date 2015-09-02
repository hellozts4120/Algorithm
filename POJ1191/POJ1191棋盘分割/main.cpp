#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<iomanip>
using namespace std;
int board[9][9];
int record[15][9][9][9][9];
int sum[9][9];

int CalSum(int x1,int y1,int x2,int y2){
	return (sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] - sum[x2][y1 - 1]);
}

int func(int n,int x1,int y1,int x2,int y2){
	int ans,xtmp,ytmp,sum1,sum2,anstmp;
	int MIN = 999999;
	if(record[n][x1][y1][x2][y2] >= 0){
		return record[n][x1][y1][x2][y2];
	}
	if(n == 1){
		ans = CalSum(x1,y1,x2,y2);
		record[n][x1][y1][x2][y2] = ans * ans;
		return record[n][x1][y1][x2][y2];
	}
	for(xtmp = x1;xtmp < x2;xtmp++){
		sum1 = CalSum(x1,y1,xtmp,y2);
		sum2 = CalSum(xtmp + 1,y1,x2,y2);
		anstmp = min((func(n - 1,x1,y1,xtmp,y2) + sum2 * sum2),(func(n - 1,xtmp + 1,y1,x2,y2) + sum1 * sum1));
		if(MIN > anstmp){
			MIN = anstmp;
		}
	}
	for(ytmp = y1;ytmp < y2;ytmp++){
		sum1 = CalSum(x1,y1,x2,ytmp);
		sum2 = CalSum(x1,ytmp + 1,x2,y2);
		anstmp = min((func(n - 1,x1,y1,x2,ytmp) + sum2 * sum2),(func(n - 1,x1,ytmp + 1,x2,y2) + sum1 * sum1));
		if(MIN > anstmp){
			MIN = anstmp;
		}
	}
	record[n][x1][y1][x2][y2] = MIN;
	return record[n][x1][y1][x2][y2];
}

int main()
{
	int n;
	int i,j;
	int rowsum;
	double result;
	memset(record,-1,sizeof(record));
	memset(sum,0,sizeof(sum));
	cin >> n;
	for(i = 1;i < 9;i++){
		for(j = 1,rowsum = 0;j < 9;j++){
			cin >> board[i][j];
			rowsum += board[i][j];
			sum[i][j] = sum[i - 1][j] + rowsum;
		}
	}
	result = (func(n,1,1,8,8) / n) - (sum[8][8] * sum[8][8] / (n * n));
	cout << setiosflags(ios::fixed) << setprecision(3) << result <<endl;
	return 0;
}
		