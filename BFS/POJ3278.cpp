#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN = 100000;
int visited[MAXN + 10];
int N,K;
struct Step{
	int x;
	int steps;
	Step(int x_,int s_):x(x_),steps(s_){};
};
queue<Step> q;

int main(){
	cin >> N >> K;
	memset(visited,0,sizeof(visited));
	q.push(Step(N,0));
	visited[N] = 1;
	while(!q.empty()){
		Step current = q.front();
		if(current.x == K){
			cout << current.steps << endl;
			return 0;
		}
		else{
			if(current.x - 1 >= 0 && !visited[current.x - 1]){
				q.push(Step(current.x - 1 , current.steps + 1));
				visited[current.x - 1] = 1;
			}
			if(current.x + 1 >= 0 && !visited[current.x + 1]){
				q.push(Step(current.x + 1 , current.steps + 1));
				visited[current.x + 1] = 1;
			}
			if(current.x * 2 >= 0 && !visited[current.x * 2]){
				q.push(Step(current.x * 2 , current.steps + 1));
				visited[current.x * 2] = 1;
			}
			q.pop();
		}
	}
	return 0;
}