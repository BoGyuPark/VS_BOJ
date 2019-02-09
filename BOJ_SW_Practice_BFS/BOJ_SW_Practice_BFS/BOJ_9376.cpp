#include<iostream>
#include<vector>
#include<deque>
using namespace	std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int t, h, w;
vector<vector<int> > bfs(vector<vector<char> > &v, int xpos, int ypos) {
	vector<vector<int> > dist;
	for (int i = 0; i < h + 2; i++) {
		vector<int> e(w + 2, -1);
		dist.push_back(e);
	}
	deque<pair<int,int> > dq;
	dq.push_back(make_pair(xpos, ypos));
	int check[105][105] = { 0, };
	check[xpos][ypos] = true;
	dist[xpos][ypos] = 0;
	while (!dq.empty()) {
		int x = dq.front().first, y = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < h + 2 && ny >= 0 && ny < w + 2) {
				if (check[nx][ny] == false) {
					if (v[nx][ny] == '.' || v[nx][ny] == '$') {
						dq.push_front(make_pair(nx, ny));
						check[nx][ny] = true;
						dist[nx][ny] = dist[x][y];
					}
					else if (v[nx][ny] == '#') {
						dq.push_back(make_pair(nx, ny));
						check[nx][ny] = true;
						dist[nx][ny] = dist[x][y] + 1;
					}
				}
			}
		}
	}
	return dist;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> h >> w;
		vector<vector<char> > v;
		vector<pair<int, int> > pos;
		for (int i = 0; i < h + 2; i++) {
			vector<char> e(w + 2, '.');
			v.push_back(e);
			if (i == 0 || i == h + 1) continue;
			for (int j = 1; j <= w; j++) {
				cin >> v[i][j];
				if (v[i][j] == '$') pos.push_back(make_pair(i, j));
			}
		}
		vector<vector<int> > outside = bfs(v, 0, 0);
		vector<vector<int> > p1 = bfs(v, pos[0].first, pos[0].second);
		vector<vector<int> > p2 = bfs(v, pos[1].first, pos[1].second);
		int ans = 999999, cur = 0;
		for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				if (outside[i][j] != -1) {
					cur = outside[i][j] + p1[i][j] + p2[i][j];
					if (v[i][j] == '#') cur -= 2;
					if (ans > cur)	ans = cur;
				}
			}
		}
		cout << ans << '\n';
	}
}