/*BOJ 17136 색종이*/
#include<iostream>
#include<vector>
using namespace std;
int map[10][10], remainCnt[6] = { 0,5,5,5,5,5 };
const int n = 10;
int paperCnt, OneCnt, ans = 2147483647;;
vector<pair<int, int>> v;
int isInsert(int row, int col, int Size) {
	for (int i = row; i < row + Size; i++) {
		for (int j = col; j < col + Size; j++) {
			if (map[i][j] != 1 || i >= n || j >= n) return -1;
		}
	}
	return Size*Size;
}

void setPaper(int row, int col, int Size, int value) {
	for (int i = row; i < row + Size; i++) {
		for (int j = col; j < col + Size; j++) {
			map[i][j] = value + 1;
		}
	}
}

void go(int index, int x, int y, int paperCnt, int addCnt) {
	if (ans < paperCnt) return;

	//exit
	if (addCnt == OneCnt || index == 25) {
		if (ans > paperCnt) ans = paperCnt;
		return;
	}

	for (int i = 5; i > 0; i--) {
		if (remainCnt[i] <= 0) continue;
		int num = isInsert(x, y, i);
		if (num != -1) {
			remainCnt[i]--;
			setPaper(x, y, i, i);
			int nx = x, ny = y;
			//다음 1의 좌표 찾기
			for (int j = 0; j < v.size(); j++) {
				if (map[v[j].first][v[j].second] == 1) {
					nx = v[j].first, ny = v[j].second;
					break;
				}
			}
			go(index + 1, nx, ny, paperCnt + 1, addCnt + num);

			setPaper(x, y, i, false);
			remainCnt[i]++;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				v.push_back({ i,j });
			}
		}
	}
	OneCnt = v.size();
	if (v.size() > 0) {
		go(0, v[0].first, v[0].second, 0, 0);
		if (ans == 2147483647) ans = -1;
		cout << ans;
	}
	else cout << 0;
}