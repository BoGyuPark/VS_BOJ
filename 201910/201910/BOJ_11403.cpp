/* BOJ 11403 경로 찾기*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n,t, map[101][101], visited[101];
vector<vector<int>> g;
queue<int> q;
void bfs(int nodeIdx) {
	memset(visited, 0, sizeof(visited));
	q.push(nodeIdx);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i];
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
			map[nodeIdx][next] = true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	g.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> t;
			if (t == 1) g[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) bfs(i);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}