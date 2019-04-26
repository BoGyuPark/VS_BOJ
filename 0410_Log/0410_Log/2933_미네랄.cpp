#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m, k, row;
int c[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char a[100][100];
queue<pair<int, int>> q;
vector<pair<int,int>> v, lowest;	//미네랄의 열만저장.
void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << a[i][j];
		cout << '\n';
	}
	//cout << '\n';
}
void DownMap() {
	int num = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'x' && c[i][j] == 0) {
				q.push({ i,j });
				v.push_back({ i,j });
				c[i][j] = num;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (c[nx][ny] != 0) continue;
						if (a[nx][ny] == 'x') {
							v.push_back({ nx,ny });
							q.push({ nx,ny });
							c[nx][ny] = num;
						}
					}
				}
				
				int MinH = n, calx = 0, caly = 0;
				
				//먼저 해당열중에 가장 밑에있는 행을 구한다.
				int check[100] = { 0, };
				for (int z = 0; z < v.size(); z++) {
					int nowCol = v[z].second;
					if (check[nowCol] > 0) continue;
					check[nowCol] = 1;
					for (int s = n - 1; s >= 0; s--) {
						if (c[s][nowCol] == num) {
							lowest.push_back({ s,nowCol });
							break;
						}
					}
				}

				//클러스터의 가장 아랫부분과 빈칸의 개수를 조사한다.
				for (int z = 0; z < lowest.size(); z++) {
					int temp = 0;
					for (int s = lowest[z].first + 1; s <n; s++) {
						if (a[s][lowest[z].second] == '.') temp++;
						else break;
					}
					if (MinH > temp) MinH = temp;
				}

				//최소 갯수만큼 클러스터를 내려준다.
				if (MinH != n && MinH != 0) {	
					for (int z = 0; z < v.size(); z++) {
						a[v[z].first][v[z].second] = '.';
					}
					for (int z = 0; z < v.size(); z++) {
						v[z].first += MinH;
						a[v[z].first][v[z].second] = 'x';
						c[v[z].first][v[z].second] = true;
					}
				}
				v.clear();
				lowest.clear();
				num++;
				//printMap();

			}
		}
	}
}


void Crash(int x, int y) {
	if (y == 0) {
		for (int i = 0; i < m; i++) {
			if (a[x][i] == 'x') {
				a[x][i] = '.';
				break;
			}
		}
	}
	else {
		for (int i = m - 1; i >=0; i--) {
			if (a[x][i] == 'x') {
				a[x][i] = '.';
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> row;
		int col = 0;
		if (i % 2 == 1) col = m - 1;
		Crash(n-row , col);
		//클러스터 확인
		DownMap();
		memset(c, 0, sizeof(c));
		//printMap();
	}
	printMap();
}