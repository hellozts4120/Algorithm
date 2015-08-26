#include<stdio.h>
#include<stdlib.h>
int press[6][8],position[6][8];

bool guess()	//module to guess whether the case is right
{
	int row,column;
	for(row = 1;row < 5;row++)
	{
		for(column = 1;column < 7;column++)
		{
			press[row+1][column] =(press[row][column]+ press[row][column-1] + press[row][column+1] + press[row-1][column] + position[row][column]) % 2;
		}
	}
	for(column = 1;column < 7;column++)
	{
		if((press[5][column] + press[5][column-1] + press[5][column+1] + press[4][column]) % 2 != position[5][column])
		{
			return(false);
		}
		
	}
	return(true);
}

void enumerate()	//
{
	int column;bool success;
	for(column = 1;column < 7;column++)
	{
		press[1][column] = 0;
	}
	while(!(success = guess())){
		press[1][1]++;
		column = 1;
		while(press[1][column] > 1){
			press[1][column] = 0;
			column++;
			press[1][column]++;
		}
	}
	return;
}

int main()
{
	int cases,i,row,column,done=0;
	scanf("%d",&cases);
	for(row = 0;row < 6;row++)
	{
		press[row][0] = 0;
		press[row][7] = 0;
	}
	for(column = 0;column < 7;column++)
	{
		press[0][column] = 0;
	}
	for(i = 0;i < cases;i++){
		for(row = 1;row < 6;row++)
		{
			for(column = 1;column <7;column++)
			{
				scanf("%d",&position[row][column]);
			}
		}
		enumerate();
		printf("PUZZLE #%d\n",i+1);
		done = 1;
		for(row = 1;row < 6;row++){
			for(column = 1;column < 7;column++)
			{
				printf("%d ",press[row][column]);
			}
			printf("\n");
		}
	}
	if(done == 0){printf("INF!\n");}
	system("pause");
	return 0;
}
