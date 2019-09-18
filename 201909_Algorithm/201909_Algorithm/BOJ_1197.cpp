/*BOJ 1197 최소 스패닝 트리_프림 알고리즘*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, A, B, C,check[10001], ans;
vector<vector<pair<int,int>>> v;
struct info {
	int nextNodeIdx, w;
};

struct cmp{
	bool operator()(info a, info b) {
		return a.w > b.w;
	}
};

priority_queue<info,vector<info>,cmp> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> A >> B >> C;
		v[A - 1].push_back({ B - 1,C });
		v[B - 1].push_back({ A - 1,C });
	}
	ans = 0;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		info t = pq.top();
		pq.pop();

		if (check[t.nextNodeIdx] == false) {
			check[t.nextNodeIdx] = true;
			ans += t.w;
		}
		else continue;
		
		for (int i = 0; i < v[t.nextNodeIdx].size(); i++) {
			int next = v[t.nextNodeIdx][i].first;
			int w = v[t.nextNodeIdx][i].second;
			if (check[next] == true) continue;
			pq.push({ next,w });
		}
	}

	cout << ans;
}