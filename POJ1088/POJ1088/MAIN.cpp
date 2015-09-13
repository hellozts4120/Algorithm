#include<iostream>
#include<cstdio>
using namespace std;
//×´Ì¬·½³Ì£ºsum[i][j] = max(sum[i - 1][j],sum[i + 1][j],sum[i][j - 1],sum[i][j + 1]) + 1;

int row,col;
int field[100][100];
int save[100][100];

int SnowSlide(int i,int j){
	int max = 0;
	if(save[i][j]){
		return save[i][j];
	}
	if(j >= 1){
		if(field[i][j] > field[i][j - 1]){
			if(max < SnowSlide(i,j - 1)){
				max = SnowSlide(i,j - 1);
			}
		}
	}
	if(j + 1 <= col - 1){
		if(field[i][j] > field[i][j + 1]){
			if(max < SnowSlide(i,j + 1)){
				max = SnowSlide(i,j + 1);
			}
		}
	}
	if(i >= 1){
		if(field[i][j] > field[i - 1][j]){
			if(max < SnowSlide(i - 1,j)){
				max = SnowSlide(i - 1,j);
			}
		}
	}
	if(i + 1 <= row - 1){
		if(field[i][j] > field[i + 1][j]){
			if(max < SnowSlide(i + 1,j)){
				max = SnowSlide(i + 1,j);
			}
		}
	}

	return save[i][j] = max + 1;
}

int main(){
	cin >> row >> col;
	for(int i = 0;i < row;i++){
		for(int j = 0;j < col;j++){
			cin >> field[i][j];
			save[i][j] = 0;
		}
	}
	for(int i = 0;i < row;i++){
		for(int j = 0;j < col;j++){
			SnowSlide(i,j);
		}
	}
	for(int i = 0;i < row;i++){
		for(int j = 0;j < col;j++){
			if(save[i][j] >= save[0][0]){
				save[0][0] = save[i][j];
			}
		}
	}
	cout << save[0][0] << endl;
	return 0;
}
