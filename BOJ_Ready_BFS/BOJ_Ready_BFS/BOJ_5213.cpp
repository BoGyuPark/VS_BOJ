#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
int n, l, r;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int a[501][501 * 2], c[501][501 * 2], temp[501][501 * 2];
pair<int, int> from[501][501 * 2];
queue<pair<int, int>> q;
bool impo(int x, int y, int nx, int ny) {
	//방문 안했을때
	if (c[nx][ny] == -1) {
		//타일번호가 같을때
		if (temp[x][y] == temp[nx][ny]) {
			c[nx][ny] = c[x][y];
			return true;
		}
		//타일번호가 다르고 번호가 같을때
		else if (a[x][y] == a[nx][ny]) {
			c[nx][ny] = c[x][y] + 1;
			if (ny + 1 < n * 2 && ny - 1 >= 0){
				if (temp[nx][ny] == temp[nx][ny + 1]) {
					c[nx][ny + 1] = c[x][y] + 1;
					q.push({ nx,ny+1 });
					from[nx][ny + 1] = { x,y };
				}
				else { 
					c[nx][ny - 1] = c[x][y] + 1;
					q.push({ nx,ny-1 });
					from[nx][ny - 1] = { x,y };
				}
			}
			return true;
		}
	}
	return false;
}
int main() {
	cin >> n;
	//입력에 맞게 배열에 입력, 몇번째타일인지 각 좌표에 입력(temp배열)
	int j = 0, k = 0, li = 0, p, flag = 0;
	for (int i = 1; i <= n*n - n / 2; i++) {
		cin >> l >> r;
		a[j][k] = l;
		a[j][k + 1] = r;
		temp[j][k] = temp[j][k + 1] = i;
		if (flag == false) {
			if (j % 2 == 0) p = n;
			else p = n-1;
			li += p;
			flag = true;
		}
		if (i == li) {
			j++;
			if(j%2==1) k = 1;
			else k = 0;
			flag = false;
			continue;
		}
		k += 2;
	}
	memset(c, -1, sizeof(c));
	q.push({ 0,0 });
	c[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n * 2) {
				if (impo(x, y, nx, ny)){
					q.push({ nx,ny });
					//if (temp[nx][ny] == temp[x][y]) continue;
					from[nx][ny] = { x,y };
				}
			}
		}
	}
	//마지막 타일로 이동 할 수 없다면 번호가 가장 큰 타일로 이동
	int ex, ey, maxi = -2, order = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int j = 2 * n - 1; j >= 0; j--) {
			if (c[i][j]!=-1 && maxi < c[i][j]) {
				if (temp[i][j] > order) {
					maxi = c[i][j];
					ex = i; ey = j;
					order = temp[ex][ey];
				}
			}
		}
	}
	cout << c[ex][ey] << '\n';
	vector<int> ans;
	int x = ex, y = ey;
	int t1, t2;
	while (temp[x][y] != 1) {
		ans.push_back(temp[x][y]);
		t1 = from[x][y].first, t2 = from[x][y].second;
		x = t1; y = t2;
	}
	ans.push_back(temp[x][y]);
	int t = ans[ans.size() - 1];
	cout << t << ' ';
	for (int i = ans.size()-2; i >=0; i--) {
		if (t != ans[i]) {
			cout << ans[i] << ' ';
			t = ans[i];
		}
	}
}