#include<iostream>
#include<queue>
#define MAX 200001
using namespace std;
long long check[MAX], dp[MAX], dist[MAX];
int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	q.push(n); check[n] = true;
	//dp[i]는 i까지 가는 경우의 수 
	dp[n] = 1; dist[n] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int next : {x - 1, x + 1, x * 2}) {
			if (next >= 0 && next <= MAX) {
				if (check[next] == false) {
					check[next] = true;
					q.push(next);
					dist[next] = dist[x] + 1;
					dp[next] = dp[x];
				}
				else if (dist[next] == dist[x] + 1) {
					dp[next] += dp[x];
				}
			}
		}
	}
	cout << dist[k]<<'\n';
	cout << dp[k] << '\n';
}