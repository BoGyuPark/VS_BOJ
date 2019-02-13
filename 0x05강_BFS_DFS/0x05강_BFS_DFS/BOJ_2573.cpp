#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, c[301][301], a[301][301], temp[301][301];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
void OneMelt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > 0) {
				int x = i, y = j;
				int ice = 0;
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z], ny = y + dy[z];
					if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
						if (a[nx][ny] <= 0) ice++;
					}
				}
				temp[x][y] = (a[x][y] - ice < 0 ? 0 : a[x][y] - ice);
			}
		}
	}		
}
void bfs() {

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	OneMelt();

	cout << "a";
}