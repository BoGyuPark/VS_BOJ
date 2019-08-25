/*BOJ 17136 색종이 붙이기*/
#include<iostream>
using namespace std;
const int n = 10;
int map[11][11], ans = 2147483647, OneCnt;
int paperCnt[] = { 0,5,5,5,5,5 };

bool isInsert(int x, int y, int Size) {
	if (x + Size > n || y + Size > n) return false;
	for (int i = x; i < x + Size; i++) {
		for (int j = y; j < y + Size; j++) {
			if (map[i][j] != 1) return false;
		}
	}
	return true;
}

void setPaper(int x, int y, int Size, int num) {
	for (int i = x; i < x + Size; i++) {
		for (int j = y; j < y + Size; j++) {
			map[i][j] = num + 1;
		}
	}
}

pair<int, int> findNextPos() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) return { i,j };
		}
	}
}

void go(int index, int x, int y, int insertCnt) {

	if (insertCnt >= 25 || ans < insertCnt) return;
	if (index == OneCnt) {
		if (ans > insertCnt) ans = insertCnt;
		return;
	}
	
	for (int z = 5; z >= 1; z--) {

		if (isInsert(x, y, z) && paperCnt[z] > 0) {
			//z크기의 색종이를 z+1 숫자로 덮는다.
			setPaper(x, y, z, z);
			paperCnt[z]--;

			//다음 좌표로 이동
			pair<int, int> p = findNextPos();
			go(index + (z*z), p.first, p.second, insertCnt + 1);

			paperCnt[z]++;
			setPaper(x, y, z, 0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) OneCnt++;
		}
	}
		
	pair<int, int> p = findNextPos();
	go(0, p.first, p.second, 0);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}