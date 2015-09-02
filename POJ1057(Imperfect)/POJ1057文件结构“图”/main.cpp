#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

void Sort(int n,string str[]){
	int i = 0,j = 0;
	string tmpstr;
	while(i < n - 1){
		j = i + 1;
		while(j < n){
			if(str[j] < str[i]){
				tmpstr = str[i];
				str[i] = str[j];
				str[j] = tmpstr;
			}
			j++;
		}
		i++;
	}
}

char Output(string str1,int n,int time){
	string str2;
	int i = 0,j = 0;
	string strall[100];
	cin >> str2;
	if(str2[0] == '#'){
		return '#';
	}
	if(str1 == "ROOT"){
		printf("DATA SET %d:\n",time);
	}
	while(i < n){
		cout << "|     ";
		i++;
	}
	cout << str1 << endl;
	do{
		switch(str2[0]){
			case 'd':	Output(str2,n + 1,time);break;
			case 'f':	strall[j++] = str2;break;
			case ']':	{
				Sort(j,strall);
				int g = 0;
				while(g < j){
					int k = 0;
					while(k < n){
						cout << "|     ";
						i++;
					}
					cout << strall[g] << endl;
					g++;
				}
				return ']';
						}
			case '*':	{
				Sort(j,strall);
				int g = 0;
				while(g < j){
					cout << strall[g] << endl;
					g++;
				}
				return '*';
						}
			case '#':	return '#';
		}
	}while(cin >> str2);
	return '*';
}

int main()
{
	int time = 1;
	while(1){
		if(Output("ROOT",0,time) == '#'){
			break;
		}
		cout << endl;
		time++;
	}
	return 0;
}
