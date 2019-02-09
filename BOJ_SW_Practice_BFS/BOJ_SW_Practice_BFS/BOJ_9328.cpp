#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int t, h, w, cnt;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
string keys;
void bfs(vector<string> &map, int x, int y) {
	int check[105][105] = { 0, };
	int d[105][105] = { 0, };
	queue<pair<int, int> > normalQ;
	vector<queue<pair<int, int> > > alphaQ(26);
	normalQ.push(make_pair(x, y));
	check[x][y] = true;
	cnt = 0;
	while (!normalQ.empty()) {
		int nowx = normalQ.front().first, nowy = normalQ.front().second;
		normalQ.pop();
		for (int i = 0; i < 4; i++) {
			int nx = nowx + dx[i], ny = nowy + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (check[nx][ny] == false) {
					if (map[nx][ny] == '.') {
						check[nx][ny] = true;
						normalQ.push(make_pair(nx, ny));
					}
					else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {
						int flag = false;
						for (int i = 0; i < keys.size(); i++) {
							if (map[nx][ny]-('A'-'a') == keys[i])	flag = true;
						}
						if (flag == true) {
							normalQ.push(make_pair(nx, ny));
							check[nx][ny] = true;
						}
						else {
							check[nx][ny] = true;
							alphaQ[map[nx][ny] - 'A'].push(make_pair(nx, ny));
						}
					}
					else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z') {
						check[nx][ny] = true;
						normalQ.push(make_pair(nx, ny));
						keys += map[nx][ny];
						while (!alphaQ[map[nx][ny] - 'a'].empty()) {
							normalQ.push(alphaQ[map[nx][ny] - 'a'].front());
							alphaQ[map[nx][ny] - 'a'].pop();
						}
					}
					else if (map[nx][ny] == '$') {
						check[nx][ny] = true;
						cnt++;
						normalQ.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	cout << cnt << '\n';
}
int main() {
	cin >> t;
	while (t--) {
		cin >> h >> w;
		h += 2; w += 2;
		vector<string> vs(h);
		for (int i = 0; i < h; i++) {
			if (i == 0 || i == h - 1) {
				string s = "";
				for (int j = 0; j < w; j++) s += '.';
				vs[i] = s;
			}
			else {
				string temp;
				cin >> temp;
				temp = '.' + temp + '.';
				vs[i] = temp;
			}
		}
		cin >> keys;
		bfs(vs, 0, 0);
	}
}