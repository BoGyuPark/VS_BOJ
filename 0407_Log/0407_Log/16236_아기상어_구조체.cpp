#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct info {
	int dist, x, y;
};
int n, a[20][20], c[20][20], sx, sy, time;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
vector<info> rmList;
bool cmp(const info & a, const info &b) {
	if (a.dist < b.dist) {
		return true;
	}
	else if (a.dist == b.dist) {
		if (a.x < b.x) return true;
		else if (a.x == b.x) {
			if (a.y < b.y) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

int FindRemoveList(int i, int j, int sSize) {
	q.push({ i,j });
	c[i][j] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z], ny = y + dy[z];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (c[nx][ny] != -1) continue;
			if (a[nx][ny] <= sSize) {
				//먹을 수 있는경우
				if (a[nx][ny] < sSize && a[nx][ny] > 0) {
					rmList.push_back({ c[x][y] + 1,nx,ny });
				}
				//그냥 이동 가능한 경우
				q.push({ nx,ny });
				c[nx][ny] = c[x][y] + 1;
			}
		}
	}
	//잡아먹을 물고기위치로 아기상어위치를 변경시키고
	//아기상어가 먹은 횟수를 증가시킨다.
	if (rmList.size() == 0) return false;
	else {
		if(rmList.size()>1)	sort(rmList.begin(), rmList.end(), cmp);
		sx = rmList[0].x; sy = rmList[0].y;
		int d = rmList[0].dist;
		a[sx][sy] = 0;
		rmList.clear();
		return d;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				sx = i, sy = j;
				a[i][j] = 0;
			}
		}
	}
	int SharkSize = 2, eatCnt = 0, time = 0;
	while (true) {
		memset(c, -1, sizeof(c));
		int temp = FindRemoveList(sx, sy, SharkSize);
		if (temp > 0) {
			eatCnt++;
			time += temp;
		}
		else break;
		if (eatCnt == SharkSize) {
			SharkSize++;
			eatCnt = 0;
		}
	}
	cout << time;
}