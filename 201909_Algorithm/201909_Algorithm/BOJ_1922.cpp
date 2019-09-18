/*BOJ 1922 네트워크 연결_프림 알고리즘*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, a, b, c, check[1001], ans;
vector<vector<pair<int, int>>> v;
struct info {
	int next, w;
};
struct cmp {
	bool operator()(info a, info b) {
		return a.w > b.w;
	}
};
priority_queue<info, vector<info>, cmp> pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	pq.push({ 1,0 });
	while (!pq.empty()) {
		info t = pq.top();
		pq.pop();
		if (!check[t.next]) {
			ans += t.w;
			check[t.next] = true;
		}
		else continue;

		for (int i = 0; i < v[t.next].size(); i++) {
			int next = v[t.next][i].first;
			int w = v[t.next][i].second;
			if (check[next]) continue;
			pq.push({ next,w });
		}
	}
	cout << ans;
}