#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int time,s,count = 0;;
	cin >> time;
	while(time--){
		cin >> s;
		int num1,num2;
		cin >> num1;
		int *list1 = new int[num1];
		for(int i = 0;i < num1;i++){
			cin >> list1[i];
		}
		cin >> num2;
		int *list2 = new int[num2];
		for(int i = 0;i < num2;i++){
			cin >> list2[i];
		}
		for(int i = 0;i < num1;i++){
			for(int j = 0;j < num2;j++){
				if(list1[i] + list2[j] == s){
					count++;
				}
			}
		}
		cout << count << endl;
		count = 0;
		delete []list1;
		delete []list2;
	}
	return 0;
}
