#include<stdio.h>
int paint[20][20],map[20][20],n,count,min[20],done[20],k = 0;
char color[20];

bool guess()
{
	int row,column;
	for(row = 1;row < n;row++){
		for(column = 1;column < n+1;column++){
			paint[row+1][column] = (map[row][column] + paint[row][column] + paint[row][column-1] + paint[row][column+1] + paint[row-1][column]) % 2;
			if(paint[row+1][column] == 1){count++;};
		}
	}
	for(column = 1;column < n+1;column++){
		if((paint[row][column] + paint[row][column-1] + paint[row][column+1] + paint[row-1][column])%2 != map[row][column]){
			return false;
		}
	}
	if(count < min[k]){min[k] = count;}
	return true;
}

void enumerate()
{
	int column;
	for(column = 1;column <= n+1;column++){
		paint[1][column] = 0;
	}
	while(guess()==false && paint[1][n+1]==0){
		count = 0;
		paint[1][1]++;
		column = 1;
		if(paint[1][column] > 1){
			paint[1][column] = 0;
			column++;
			paint[1][column]++;
		}
		for(int z = 0;z <= n+1;z++)
		{
			if(paint[1][z] == 1){count++;}
		}
	}
	if(paint[1][n+1]==1){done[k]=0;}
		return;
}

int main()
{
	int cases,i,row,column;
	scanf("%d",&cases);
	for(i = 0;i < cases;i++){
		scanf("%d",&n);
		min[k] = n * n + 1;
		for(row = 0;row < n+1;row++){
			paint[row][0] = 0;paint[row][n+1] = 0;
		}
		for(column = 0;column < n+1;column++){
			paint[0][column] = 0;
		}
		for(row = 1;row < n+1;row++){
			scanf("%s",color);
			for(column = 1;column < n+1;column++){
				for(int j = 0;j < n;j++){
					if(color[j] == 'y'){
						map[row][column] = 0;
					}
					if(color[j] == 'w'){
						map[row][column] = 1;
					}
				}
			}
		}
		enumerate();
		if(min[k] < n * n + 1){done[k] = 1;}
	count = 0;
	k++;
	}
	for(i = 0;i < cases;i++){
		if(done[i]==0){printf("inf\n");}
		if(done[i]==1){printf("%d\n",min[i]);}
	}
	return 0;
}
