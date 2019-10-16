#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, K, ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int transDir[] = { 1,0,3,2 };
vector<pair<int, int>> map[101][101];
struct info {
	int r, c, s, d, z;
	bool isAlive;
};
vector<info> v;
void distCal(int dir, int changePos, int dist, int dPos[], int idx, int wallDist) {
	int initPos, crossPos, maxi;
	if (dir == 0) initPos = 0, crossPos = n - 1, maxi = n - 1;
	else if (dir == 1) initPos = n - 1, crossPos = 0, maxi = n - 1;
	else if (dir == 2) initPos = m - 1, crossPos = 0, maxi = m - 1;
	else initPos= 0, crossPos = m - 1, maxi = m - 1;

	if (dist - wallDist > 0) {
		dist -= wallDist;
		int mulValue = dist / maxi;
		int remainValue = dist % maxi;

		if (mulValue % 2 == 0) {
			changePos = initPos;
			if (remainValue > 0) {
				dir = transDir[dir];
				changePos += dPos[dir] * remainValue;
			}
		}
		else {
			changePos = crossPos;
			if (remainValue > 0) {
				changePos += dPos[dir] * remainValue;
			}
			else {
				dir = transDir[dir];
			}
		}
	}
	else {
		changePos += dPos[dir] * dist;
	}
	if(dir<=1) v[idx].r = changePos;
	else v[idx].c = changePos;
	v[idx].d = dir;
}
void shirkMove() {
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].isAlive) continue;
		int dist = v[i].s;
		int dir = v[i].d;
		int x = v[i].r, y = v[i].c;
		if (dir == 0)	distCal(dir, x, dist, dx, i, x);
		else if (dir == 1) distCal(dir, x, dist, dx, i, n - 1 - x);
		else if (dir == 2) distCal(dir, y, dist, dy, i, m - 1 - y);
		else distCal(dir, y, dist, dy, i, y);
	}
}
void killshirk(int col) {
	int miniRow = 2147483647 , idx = -1;
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].isAlive) continue;
		if (v[i].c == col) {
			if (miniRow > v[i].r) {
				miniRow = v[i].r;
				idx = i;
			}
		}
	}
	if (idx != -1) {
		v[idx].isAlive = false;
		ans += v[idx].z;
	}
}

void findKing() {

	for (int i = 0; i < v.size(); i++) {
		if (!v[i].isAlive) continue;
		map[v[i].r][v[i].c].push_back({ v[i].z,i });
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j].size() > 1) {
				sort(map[i][j].begin(), map[i][j].end(), greater<pair<int,int>>());
				for (int z = 1; z < map[i][j].size(); z++) {
					v[map[i][j][z].second].isAlive = false;
				}
			}
			map[i][j].clear();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	cin >> n >> m >> K;
	for (int i = 0; i < K; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		v.push_back({ r - 1,c - 1,s,d - 1,z,true });
	}

	for (int i = 0; i < m; i++) {
		killshirk(i);
		shirkMove();
		findKing();		//각 좌표에 상어 한마리만 살리기
	}
	cout << ans;
}