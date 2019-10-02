/* BOJ 4485 ³ì»ö ¿Ê ÀÔÀº ¾Ö°¡ Á©´ÙÁö? */
#include<iostream>
#include<queue>
using namespace std;
int n, map[126][126], dist[126][126];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
#define INF 2147483647
struct info {
	int x, y, cost;
};
struct cmp {
	bool operator()(info a, info b) {
		return a.cost > b.cost;
	}
};
priority_queue<info, vector<info>, cmp> pq;

void search() {
	pq.push({ 0,0,0 });
	dist[0][0] = 0;
	while (!pq.empty()) {
		int x = pq.top().x, y = pq.top().y, cost = pq.top().cost;
		pq.pop();

		if (dist[x][y] < cost) continue;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i], nCost = cost + map[x][y];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			
			if (dist[nx][ny] > nCost) {
				dist[nx][ny] = nCost;
				pq.push({ nx,ny,nCost });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				dist[i][j] = INF;
			}
		}
		search();
		cout << "Problem " << tc << ": " << dist[n - 1][n - 1] + map[n - 1][n - 1] << '\n';
		tc++;
	}
}