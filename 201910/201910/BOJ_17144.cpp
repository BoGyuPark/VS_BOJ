#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n, m, T, map[51][51], dist[51][51];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int>> air;
vector<pair<int, int>> v;
void fuse() {
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		int possibleCnt = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j], ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == -1) continue;
			possibleCnt++;
			dist[nx][ny] += map[x][y] / 5;
		}
		map[x][y] -= ((map[x][y] / 5)*possibleCnt);
	}
	v.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1) continue;
			map[i][j] += dist[i][j];
		}
	}
}

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void Rotate() {
	int r = air[0].first - 1 , c = air[0].second;
	int rowMax = air[0].first, colMax = m - 1;
	//down
	for (int i = 0; i < rowMax - 1; i++) {
		map[r][c] = map[r - 1][c];
		r--;
	}
	//left
	for (int i = 0; i < colMax; i++) {
		map[r][c] = map[r][c + 1];
		c++;
	}
	//up
	for (int i = 0; i < rowMax; i++) {
		map[r][c] = map[r + 1][c];
		r++;
	}

	//right
	for (int i = 0; i < colMax - 1; i++) {
		map[r][c] = map[r][c - 1];
		c--;
	}
	map[r][c] = 0;
}
void reverseRotate() {
	int r = air[1].first + 1, c = air[1].second;
	int rowMax = n - 1 -air[1].first , colMax = m - 1;
	//up
	for (int i = 0; i < rowMax - 1; i++) {
		map[r][c] = map[r + 1][c];
		r++;
	}
	//left
	for (int i = 0; i < colMax; i++) {
		map[r][c] = map[r][c + 1];
		c++;
	}
	//down
	for (int i = 0; i < rowMax; i++) {
		map[r][c] = map[r - 1][c];
		r--;
	}
	//right
	for (int i = 0; i < colMax - 1; i++) {
		map[r][c] = map[r][c - 1];
		c--;
	}
	map[r][c] = 0;
}

void findPos() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1) continue;
			v.push_back({ i,j });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> T;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) air.push_back({ i,j });
			else if (map[i][j] > 0) v.push_back({ i,j });
		}
	}

	for (int i = 0; i < T; i++) {
		fuse();
		Rotate();
		reverseRotate();
		findPos();
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1) continue;
			ans += map[i][j];
		}
	}
	cout << ans;
}