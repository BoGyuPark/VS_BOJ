#include<iostream>
#include<queue>
using namespace std;
int r, c, check[251][251];
char arr[251][251];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans_s, ans_w;
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (check[i][j] == true || arr[i][j]=='#') continue;

			int s_cnt = 0, w_cnt = 0;
			if (arr[i][j] == 'o') s_cnt++;
			else if (arr[i][j] == 'v') w_cnt++;

			check[i][j] = true;
			q.push({ i,j });

			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z], ny = y + dy[z];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (arr[nx][ny] == '#' || check[nx][ny]==true) continue;
					if (arr[nx][ny] == 'o') s_cnt++;
					else if (arr[nx][ny] == 'v') w_cnt++;
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}

			if (s_cnt > w_cnt) ans_s += s_cnt;	
			else ans_w += w_cnt;
		}
	}
	cout << ans_s << ' ' << ans_w;
	
}