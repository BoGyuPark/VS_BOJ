#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, l, a[101][101], b[101][101], c[101][101];
bool go(int row, int map[101][101]) {
	for (int i = 1; i < n; i++) {
		if (map[row][i] != map[row][i - 1]) {
			int dif = map[row][i] - map[row][i - 1];
			if (dif < 0) dif = -dif;
			if (dif != 1) return false;
			//경사 놓는 것 처리
			if (map[row][i] > map[row][i - 1]) {
				for (int j = 1; j <= l; j++) {
					//경사로를 놓다가 범위를 벗어나는 경우
					if (i - j < 0) return false;
					//낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속 되지 않는 경우
					if (map[row][i - 1] != map[row][i - j]) return false;
					//경로를 놓은 곳에 또 경사로를 놓는 경우
					if (c[row][i - j]) return false;
					c[row][i - j] = true;
				}		
			}
			else {
				for (int j = 0; j < l; j++) {
					//경사로를 놓다가 범위를 벗어나는 경우
					if (i + j >= n) return false;
					//낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속 되지 않는 경우
					if (map[row][i] != map[row][i + j]) return false;
					//경로를 놓은 곳에 또 경사로를 놓는 경우
					if (c[row][i + j]) return false;
					c[row][i + j] = true;
				}
			}
		}
	}
	return true;
}

int main() {
	cin >> n >> l;
	//a배열은 기본 배열, b배열은 행과 열을 바꿈
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)	ans += go(i, a);
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) ans += go(i, b);
	cout << ans;		
}