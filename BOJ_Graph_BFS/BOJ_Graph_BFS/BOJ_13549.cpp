#include<iostream>
#include<queue>
#define MAX 1000000
using namespace std;
int n, k, check[MAX], dis[MAX];
queue<int> curq, nextq;
void bfs(int start) {
	check[start] = true;
	dis[start] = 0;
	curq.push(start);
	while (!curq.empty()) {
		int x = curq.front();
		curq.pop();
		if (2 * x < MAX){
			if (check[2 * x] == false) {
				check[2 * x] = true;
				dis[x * 2] = dis[x];
				curq.push(2 * x);
			}
		}
		if (x + 1 < MAX){
			if (check[x + 1] == false) {
				check[x + 1] = true;
				nextq.push(x + 1);
				dis[x + 1] = dis[x] + 1;
			}
		}
		if (x - 1 >= 0){
			if (check[x - 1] == false) {
				check[x - 1] = true;
				nextq.push(x - 1);
				dis[x - 1] = dis[x] + 1;
			}
		}
		if (curq.empty()) {
			curq = nextq;
			nextq = queue<int>();
		}
	}
}
int main() {
	cin >> n >> k;
	bfs(n);
	cout << dis[k];
	return 0;
}