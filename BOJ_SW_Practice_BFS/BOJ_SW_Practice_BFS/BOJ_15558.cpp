#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
int n, k;
int main() {
	cin >> n >> k;
	vector<string> vs(2);
	cin >> vs[0] >> vs[1];
	queue<pair<int, int>> q;
	vector<vector<int> > dis(2);
	vector<pair<int, int>> dir = { {0,1},{0,-1},{1,k} };
	for (int i = 0; i < 2; i++) {
		vector<int> e(200001, -1);
		dis[i] = e;
	}
	q.push(make_pair(0, 0));
	dis[0][0] = 0;
	int flag = false;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (auto &p : dir) {
			int nx = (x + p.first) % 2, ny = y + p.second;
			if (ny < 0) continue;
			if (ny <= dis[x][y]) continue;
			if (ny >= n) {
				flag = true;
				while (!q.empty()) q.pop();
				break;
			}
			if (dis[nx][ny] == -1 && vs[nx][ny] == '1') {
				dis[nx][ny] = dis[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	cout << (flag == true ? 1 : 0);
}