/*BOJ 2644 ÃÌ¼ö°è»ê*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, s, e, m, X, Y, ans;
vector<vector<int>> v;
int check[10000];
void bfs() {
	queue<int> q;
	q.push(s);
	check[s] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (check[next] != -1) continue;
			if (next == e) {
				ans = check[now] + 1;
				return;
			}
			q.push(next);
			check[next] = check[now] + 1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s >> e >> m;
	v.resize(n * 2);
	for (int i = 0; i < m; i++) {
		cin >> X >> Y;
		v[X].push_back(Y);
		v[Y].push_back(X);
	}
	memset(check, -1, sizeof(check));
	ans = -1;
	bfs();
	cout << ans;
}