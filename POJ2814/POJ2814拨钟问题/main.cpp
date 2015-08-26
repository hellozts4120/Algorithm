#include<stdio.h>
#include<stdlib.h>
int main()
{
	int clock[9],i,j,sum,min = 262144,move[9];
	for(i = 0;i < 9;i++){
		scanf("%d",&clock[i]);
	}
	for(int i1 = 0;i1 < 4;i1++)
		for(int i2 = 0;i2 < 4;i2++)
			for(int i3 = 0;i3 < 4;i3++)
				for(int i4 = 0;i4 < 4;i4++)
					for(int i5 = 0;i5 < 4;i5++)
						for(int i6 = 0;i6 < 4;i6++)
							for(int i7 = 0;i7 < 4;i7++)
								for(int i8 = 0;i8 < 4;i8++)
									for(int i9 = 0;i9 < 4;i9++)
									{
										if(((i1+i2+i4+clock[0])%4==0)&&((i1+i2+i3+i5+clock[1])%4==0)&&((i2+i3+i6+clock[2])%4==0)&&((i1+i4+i5+i7+clock[3])%4==0)&&((i1+i3+i5+i7+i9+clock[4])%4==0)&&((i3+i5+i6+i9+clock[5])%4==0)&&((i4+i7+i8+clock[6])%4==0)&&((i5+i7+i8+i9+clock[7])%4==0)&&((i6+i8+i9+clock[8])%4==0)){
											sum = i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9; 
											if(sum < min){
												min = sum;
												move[0]=i1;
												move[1]=i2;
												move[2]=i3;
												move[3]=i4;
												move[4]=i5;
												move[5]=i6;
												move[6]=i7;
												move[7]=i8;
												move[8]=i9;
											}
										}
									}
									for(i = 0;i < 9;i++){
										if(move[i] == 0){continue;}
										for(j = 0;j < move[i];j++){
											printf("%d ",i+1);
										}
									}
									system("pause");
}

