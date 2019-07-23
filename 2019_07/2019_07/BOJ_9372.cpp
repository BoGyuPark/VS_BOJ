/*BOJ 9372 상근이의 여행*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int T, n, m, a, b, ans;
int check[1001];
queue<int> q;
vector<vector<int>> v;
void bfs() {
	q.push(1);
	check[1] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				ans++;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> n >> m;
		v.resize(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		ans = 0;
		bfs();
		cout << ans << '\n';
		v.clear();
		memset(check, 0, sizeof(check));
	}
}