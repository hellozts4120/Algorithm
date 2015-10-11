#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 101;
//�ǹ����Բ�֣�����̰�ģ�����ÿһ���ǹ��ĵ�λ��ֵ�������ɲ�֣�Ҳ��ʹ��DP���������⣻

struct Box{
	int v,w;	//value,weight
	double density;	//��λ��ֵ
};

int N,W;
Box box[MAX];
double totalW,totalV;
bool operator<(const Box &a,const Box &b){
	return a.density < b.density;
}

int main(){
	cin >> N >> W;
	for(int i = 0; i < N; i++){
		cin >> box[i].v >> box[i].w;
		box[i].density = (box[i].v * 1.0) / box[i].w;
	}
	sort(box,box+N);	//����λ��ֵ����
	totalV = 0;
	totalW = 0;
	for(int i = N - 1; i >= 0;i--){
		if(totalW + box[i].w <= W){
			totalW += box[i].w;
			totalV += box[i].v;
		}
		else{
			totalV += box[i].density * (W - totalW);
			totalW = W;
			break;
		}
	}
	printf("%.1lf\n",totalV);
	return 0;
}