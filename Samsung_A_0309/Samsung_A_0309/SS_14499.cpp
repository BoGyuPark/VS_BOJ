#include<iostream>
using namespace std;
int n, m, nowx, nowy, k, a[21][21] = { 0, };
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ro[4][6] = {
	{3,1,0,5,4,2},
	{2,1,5,0,4,3},
	{4,0,2,3,5,1},
	{1,5,2,3,0,4}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> nowx >> nowy >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	int dice[6] = { 0, }; 
	int t[6] = { 0, };
	while (k--) {
		int dir;
		cin >> dir;
		//주사위를 굴린다.
		dir--;
		int nx = nowx + dx[dir], ny = nowy + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		//임시저장
		for (int i = 0; i < 6; i++) t[i] = dice[ro[dir][i]];
		//원래 주사위로 복사
		for (int i = 0; i < 6; i++) dice[i] = t[i];
		
		if (a[nx][ny] == 0) a[nx][ny] = dice[5];
		else {
			dice[5] = a[nx][ny];
			a[nx][ny] = 0;
		}
		cout << dice[0] << '\n';
		nowx = nx; nowy = ny;
	}
}