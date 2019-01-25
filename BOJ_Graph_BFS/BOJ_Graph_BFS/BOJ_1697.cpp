#include<iostream>
#include<queue>
using namespace std;
int n, k, check[100001], dis[100001];
queue<int> q;
void bfs(int node) {
	check[node] = true;
	q.push(node);
	dis[node] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x - 1 >= 0 && check[x - 1] == false) {
			check[x - 1] = true;
			q.push(x - 1);
			dis[x - 1] = dis[x] + 1;
		}
		if (x + 1 < 100001 && check[x + 1] == false) {
			check[x + 1] = true;
			q.push(x + 1);
			dis[x + 1] = dis[x] + 1;
		}
		if (x * 2 < 100001 && check[x * 2] == false) {
			check[x * 2] = true;
			q.push(x * 2);
			dis[x * 2] = dis[x] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	bfs(n);
	cout << dis[k];
	return 0;
}