/*BOJ 16964 DFS 스페셜 저지*/
#include<iostream>
#include<vector>
using namespace std;
int n, path[100'001], check[100'001], nextNum = 2;
vector<vector<int>> g;
int findNext(int nodeIdx) {

	for (int i = 0; i < g[nodeIdx].size(); i++) {
		int next = g[nodeIdx][i];
		if (check[next]) continue;
		if (path[nextNum] == next) return next;
	}
	return -1;
}

void go(int nodeIdx) {

	while (true) {
		int possibleNode = findNext(nodeIdx);
		if (possibleNode == -1) break;
		if (possibleNode) {
			check[possibleNode] = true;
			nextNum++;
			go(possibleNode);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	g.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);	g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) cin >> path[i];
	check[1] = true;
	go(1);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			ans = 0;
			break;
		}
	}
	cout << ans;
}