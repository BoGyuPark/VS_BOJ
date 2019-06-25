#include<iostream>
using namespace std;
int n, m, a[101][101], sx, sy, sdir, ex, ey, edir;
//         µ¿, ¼­, ³² , ºÏ
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> sx >> sy >> sdir >> ex >> ey >> edir;
	sx--; sy--; sdir--; ex--; ey--; edir--;




}