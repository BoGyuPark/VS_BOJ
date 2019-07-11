/*BOJ 1325 효율적인 해킹*/

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m, check[10001];
int ans[100001];
vector<vector<int>> vec;
queue<int> q;
void bfs(int num) {
	memset(check, -1, sizeof(check));
	q.push(num);
	check[num] = 0;
	int cnt = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];
			if (check[next] != -1) continue;
			check[next] = check[now] + 1;
			q.push(next);
			cnt++;
			
		}
	}
	ans[num] = cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	vec.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		vec[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	int maxNum = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] > maxNum) maxNum = ans[i];
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == maxNum) cout << i << ' ';
	}
}