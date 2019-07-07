#include<iostream>
#include<cstring>
using namespace std;
int n, m, visited[4][500][500], sx, sy;
char map[500][500], cpy[500][500];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int transDirS[] =  { 1, 0, 3, 2 };
int transDirRS[] = { 3,2,1,0 };
char dir_char[] = { 'U', 'R', 'D','L' };
void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << cpy[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}
void cpy_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cpy[i][j] = map[i][j];
		}
	}
}

int simulate(int dirNum) {
	int dir = dirNum;
	int x = sx, y = sy;
	cpy[x][y] = '*';
	visited[dir][x][y] = true;
	int cnt = 1;
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			break;

		//Voyager Ç¥½Ã
		if (visited[dir][nx][ny] == true) {
			cnt = -1;
			break;
		}

		if (cpy[nx][ny] == 'C') {
			break;
		}
		else {
			if (cpy[nx][ny] == '/') {
				dir = transDirS[dir];
			}
			else if (cpy[nx][ny] == '\\') {
				dir = transDirRS[dir];
			}
			//cpy[nx][ny] = '*';
			visited[dir][nx][ny] = true;
			cnt++;
		}
		x = nx;
		y = ny;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			cpy[i][j] = map[i][j];
		}
	}
	cin >> sx >> sy;
	sx--; sy--;
	int ans = 0;
	char ans_char;
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		int value = simulate(i);
		if (value == -1) {
			flag = true;
			ans_char = dir_char[i];
			break;
		}
		if (ans < value) {
			ans = value;
			ans_char = dir_char[i];
		}
		//cout << value << '\n';
		//printMap();
		cpy_map();
		memset(visited, 0, sizeof(visited));
	}
	
	cout << ans_char << '\n';
	if (flag == true) {
		cout << "Voyager";
	}
	else {
		cout << ans;
	}
}