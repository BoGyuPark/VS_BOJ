#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int n, a[101][101], k, l;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
queue<pair<int, char>> q;
deque<pair<int, int>> dq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int t1, t2; cin >> t1 >> t2;
		a[t1 - 1][t2 - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int t1; char ch;
		cin >> t1 >> ch;
		q.push({ t1,ch });
	}
	int ans = 0;
	dq.push_back({ 0,0 });
	int dir = 1;		//规氢 快螟
	while (true) {
		int x = dq.front().first, y = dq.front().second;
		int nx = x + dx[dir], ny = y + dy[dir];
		//寒俊 何碟鳃 版快
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
		//磊扁 个俊 何碟鳃 版快
		int found = false;
		for (int i = 0; i < dq.size(); i++) {
			if (nx == dq[i].first && ny == dq[i].second) {
				found = true;
				break;
			}
		}
		if (found) break;
		dq.push_front({ nx,ny });
		if (a[nx][ny] == 1) a[nx][ny] = 0;
		else dq.pop_back();
		ans++;
		if (q.size() != 0) {
			if (q.front().first == ans) {
				if (q.front().second == 'D') dir = (dir + 1) % 4;
				else dir = (dir + 3) % 4;
				q.pop();
			}
		}
	}
	cout << ans + 1;
}