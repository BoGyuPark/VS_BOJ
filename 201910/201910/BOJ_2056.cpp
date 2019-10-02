/* BOJ 2056 ÀÛ¾÷*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int n, wight, w[10001], m, t, indegree[10001], ans;
int accW[10001];
vector<vector<int>> v;
queue<int> q;
void topologicalSort() {
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
		accW[i] = w[i];
		ans = max(ans, accW[i]);
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;
			accW[next] = max(accW[next], accW[now] + w[next]);
			ans = max(accW[next], ans);
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		cin >> m;
		indegree[i] += m;
		for (int j = 0; j < m; j++) {
			cin >> t;
			v[t].push_back(i);
		}
	}
	topologicalSort();
	cout << ans;
}