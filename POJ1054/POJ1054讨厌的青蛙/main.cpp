#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int row,column,n;
struct PLANT{
	int x,y;
};
PLANT plants[5001];
PLANT plant;

int SearchPath(PLANT a,int dX,int dY)
{
PLANT plant;int steps;
plant.x = a.x + dX;
plant.y = a.y + dY;
steps = 2;	//	��С��ȵ�3��
while(plant.x <= row && plant.x >= 1 && plant.y <= column && plant.y >=1){
	if(!binary_search(plants,plants + n,plant)){	//��֤ÿһ��������ȵ�����
		steps = 0;
		break;
	}
	plant.x += dX;
	plant.y += dY;
	steps++;
}
return steps;
}

int main()
{
	int i,j,dX,dY,pX,pY,steps,max = 2;
	scanf("%d%d",&row,&column);
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d%d",&plants[i].x,&plants[i].y);
	}
	sort(plants,plants + n);	//��ˮ����С��С��������x������ͬ��y�����С��������
	for(i = 0;i < n - 2;i++){
		for(j = i + 1;j < n - 1;j++){
			dX = plants[j].x - plants[i].x;
			dY = plants[j].y - plants[i].y;
			pX = plants[i].x - dX;
			pY = plants[i].y - dY;
			if(pX >= 1 && pY >= 1 && pX <= row && pY <= column){continue;}	//��һ���ǰһ���ڵ����˵��ѡȡ�ĵ��С��Ӧ������ѡȡ
			if(plants[i].x + (max - 1) * dX > row){break;}	//x�������Խ���ˣ�˵�����β���������ѡȡ��һ����ͬ����һ���ڶ��㲽��ֻ����󣬸��Ӳ���������Ӧ��ѡȡ��һ����һ��
			if(plants[i].y + (max - 1) * dY > column && plants[i].y + (max - 1) * dY < 1){continue;}
			steps = SearchPath(plants[j],dX,dY);
			if(steps > max){max = steps;}
		}
	}
	if(max == 2){max = 0;}
	printf("%d\n",max);
	system("pause");
	return 0;
}
bool operator < (const PLANT &p1,const PLANT &p2)
{
	if(p1.x == p2.x){return (p1.y < p2.y);}
	return (p1.x < p2.x);
}

