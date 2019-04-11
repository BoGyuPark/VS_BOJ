#include<iostream>
using namespace std;
int n, m, k;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char a[201][201];
int Boom_Time[201][201];
void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << a[i][j];
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'O') Boom_Time[i][j] = 3;
		}
	}
	if (k == 1) printMap();
	else {
		for (int t = 2; t <= k; t++) {
			//ÆøÅº ¼³Ä¡
			if (t % 2 == 0) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (a[i][j] == 'O') continue;
						a[i][j] = 'O';
						Boom_Time[i][j] = t + 3;
					}
				}
			}
			//ÆøÅºÀÌ ÅÍÁú¶§
			else {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (Boom_Time[i][j] == t) {
							int x = i, y = j;
							a[x][y] = '.';
							Boom_Time[x][y] = 0;
							for (int j = 0; j < 4; j++) {
								int nx = x + dx[j], ny = y + dy[j];
								if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
								if (a[nx][ny] == '.')  continue;
								a[nx][ny] = '.';
							}
						}
					}
				}
			}
		}
		printMap();
	}
}