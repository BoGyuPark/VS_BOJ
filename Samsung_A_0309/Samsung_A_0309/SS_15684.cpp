#include<iostream>
#include<vector>
using namespace std;
int n, m, h, a[50][50], b[50][50], Limit, ans;
int sel[4], c[271];
bool flag, f, found;
vector<pair<int, int>> v;
//사다리 타기 시작
bool solve() {
	//i번째 사다리
	for (int i = 1; i <= n * 2; i += 2) {
		int x = 1, y = i;
		while (true) {
			//왼쪽에 사다리가 있는경우
			if (a[x][y - 1] == 1) {
				y -= 2;		x += 1;
			}
			//오른쪽에 사다리가 있는경우
			else if (a[x][y + 1] == 1) {
				y += 2;		x += 1;
			}
			//양쪽에 사다리가 없는 경우
			else x += 1;

			if (x == h + 1) break;
		}
		if (y != i) return false;
	}
	return true;
}

void dfs(int index, int start, int dest) {
	if (f) return;
	if (index == dest) {
		f = false;
		found = true;
		for (int j = 0; j < dest; j++) {
			if (a[v[sel[j]].first][v[sel[j]].second+2] == 1 || a[v[sel[j]].first][v[sel[j]].second-2] == 1) {
				found = false;
				break;
			}
			a[v[sel[j]].first][v[sel[j]].second] = 1;
		}
		if (found) {
			flag = solve();
			if (flag) {
				ans = dest;
				f = true;
				return;
			}
		}
		
		for (int j = 0; j < dest; j++) {
			a[v[sel[j]].first][v[sel[j]].second] = 0;
		}
		return;
	}
	for (int i = start; i < Limit; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = i;
		dfs(index + 1 , i, dest);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> h;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x][y * 2] = b[x][y * 2] = b[x][(y * 2) - 2] = b[x][(y * 2) + 2] = 1;
	}

	for (int i = 1; i <= h; i++) 
		for (int j = 2; j < n*2; j+=2) 
			if (b[i][j] == 0) v.push_back({ i,j });
	
	Limit = v.size();
	
	ans = -1;
	if (solve()) cout << 0;
	else {
		for (int i = 1; i < 4; i++) {
			dfs(0, 0, i);
		}
		cout << ans;
	}
}