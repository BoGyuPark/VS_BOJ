/*BOJ 1697 ¼û¹Ù²ÀÁú*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dist[100'001];
int n, k;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == k) {
			cout << dist[now];
			return 0;
		}
		for (int i : {-1, 1, now}) {
			int next = now + i;
			if (next < 0 || next > 100'001) continue;
			if (dist[next] != -1) continue;
			dist[next] = dist[now] + 1;
			q.push(next);
		}
	}
}