#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int N,M;
int minArea = 1 << 30;		//���ű����;
int area = 0;				//���ڴ�еĵ�������;
int minV[30];		// minV[n]��ʾn�㵰�����ٵ����
int minA[30];		// minA[n]��ʾn�㵰������ٲ����� 

int MaxVforNRH(int n,int r,int h){		//����n�㵰�⣬�ײ����뾶r����߸߶�h������£��ܴճ�����������
	int v = 0;
	for(int i = 0;i < n;i++){
		v += (n - i)*(r - i)*(h - i);
	}
	return v;
}

void Dfs(int v,int n,int r,int h){
	//Ҫ��n��ȥ�����v,��ײ�뾶���ܳ���r,�߶Ȳ��ܳ���h 
	//�����С��������� minArea 
	if(n == 0){
		if(v) return;
		else{
			minArea = min(minArea,area);
			return;
		}
	}
	if(v <= 0){
		return;
	}
	if(minV[n] > v){	//������з��ֻ�û�����Щ��������һ���ᳬ����ȱ���������ֹͣ�
		return;
	}
	if(area + minA[n] >= minArea){		//������з�����������Ѿ���õ����ű��������ֹͣ�
		return;
	}
	if(h < n || r < n){		//�������Ԥ���������ϴ�߶��Ѿ��޷����ţ����߰뾶�Ѿ��޷����ţ���ֹͣ�
		return;
	}
	if(MaxVforNRH(n,r,h) < v){	//������з��ֻ�û�����Щ�����������Ҳ�����˻�ȱ���������ֹͣ�,�˲���Ϊ��Ҫ
		return;
	}
	for(int rr = r;rr >= n;--rr){
		if(n == M){
			area = rr * rr;
		}
		for(int hh = h;hh >= n;--hh){
			area += 2 * rr * hh;
			Dfs(v  - rr * rr * hh,n - 1,rr - 1,hh - 1);
			area -= 2 * rr * hh;
		}
	}
}

int main(){
	cin >> N >> M;
	minV[0] = 0;
	minA[0] = 0;
	for(int i = 1;i <= M;++i){
		minV[i] = minV[i - 1] + i * i * i;
		minA[i] = minA[i - 1] + 2 * i * i;
	}
	if(minV[M] > N){
		cout << 0 << endl;
	}
	else{
		int maxH =  (N - minV[M - 1]) /(M * M) + 1;		//�ײ����߶�
		//��ײ���������� (N-minV[M-1]),�Ұ뾶����M 
		int maxR = sqrt(double(N - minV[M - 1]) / M) + 1;	//�ײ�߶�����M
		area = 0;
		minArea = 1 << 30;
		Dfs(N,M,maxR,maxH);
		if(minArea == 1 << 30){
			cout << 0 << endl;
		}
		else{
			cout << minArea << endl;
		}
	}
	return 0;
}