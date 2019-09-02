/* BOJ 5214 환승 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, k, m, check[101005], ans = 2147483647;
vector<vector<int>> ve;
queue<int> q;
void bfs(int num) {
	q.push(num);
	check[num] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == n) {
			ans = check[now];
			return;
		}
		for (int i = 0; i < ve[now].size(); i++) {
			int next = ve[now][i];
			if (check[next] != 0) continue;
			//가중치 다르게 주기
			check[next] = check[now] + (next <= n);
			q.push(next);
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> m;
	int newNode = n + 1;
	for (int i = 0; i < m; i++) {
		//input
		ve.resize(n + m + 1);
		for (int j = 0; j < k; j++) {
			int t; cin >> t;
			ve[newNode].push_back(t);
			ve[t].push_back(newNode);
		}
		newNode++;
	}
	bfs(1);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}