/*BOJ 2660 »∏¿ÂªÃ±‚*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n, check[51];
vector<vector<int>> ve(50);
vector<pair<int, int>> ans;
void bfs(int idx) {
	memset(check, -1, sizeof(check));
	queue<int> q;
	q.push(idx);
	check[idx] = 0;
	int depth = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < ve[now].size(); i++) {
			int next = ve[now][i];
			if (check[next]!=-1) continue;
			check[next] = check[now] + 1;
			depth = max(depth, check[next]);
			q.push(next);
		}
	}
	ans.push_back({ depth,idx + 1 });
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	while (true) {
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		ve[u - 1].push_back(v - 1);
		ve[v - 1].push_back(u - 1);
	}

	for (int i = 0; i < n; i++) bfs(i);
	
	sort(ans.begin(), ans.end());
	int mini = ans[0].first;
	int cnt = 0;
	for (int i = 0; i < ans.size(); i++) if (ans[i].first == mini) cnt++;
	cout << mini << ' ' << cnt << '\n';
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].first == mini) {
			cout << ans[i].second << ' ';
		}
		else break;
	}
}