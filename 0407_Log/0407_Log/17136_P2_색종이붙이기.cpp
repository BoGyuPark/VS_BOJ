#include<iostream>
using namespace std;
int a[10][10], remainCnt = 0;
int sx, sy, ans;
//들어간다면 도형을 삽입 num+1로 삽입
void InsertSq(int i, int j, int num, int value) {
	for (int x = i; x < i + num; x++)
		for (int y = j; y < j + num; y++)
			a[x][y] = value + 1;
}
//num * num 의 도형이 들어가는 지 체크
bool checkInsert(int i, int j, int num) {
	int possibleCnt = 0;
	for (int x = i; x < i + num; x++) {
		for (int y = j; y < j + num; y++) {
			if (a[x][y] == 1) possibleCnt++;
		}
	}
	if (possibleCnt == num * num) {
		InsertSq(i, j, num, num);
		return true;
	}
	else return false;
}

pair<int, int> findPos() {
	int flag = false;
	int nx = 0, ny = 0;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			if (a[x][y] == 1) {
				nx = x; ny = y;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	return { nx,ny };
}

void dfs(int index, int i, int j, int sq1, int sq2, int sq3, int sq4, int sq5, int reCnt) {
	if (ans <= 25 - sq1 - sq2 - sq3 - sq4 - sq5) return;
	if (index == 25 || reCnt == 0) {
		int sum = 0;
		sum = 25 - sq1 - sq2 - sq3 - sq4 - sq5;
		if (ans > sum) ans = sum;
		return;
	}

	if (sq1 > 0) {
		if (checkInsert(i, j, 1)) {
			//도형을 놓을 다음위치를 찾는다.
			int nx, ny;
			pair<int, int> p = findPos();
			nx = p.first, ny = p.second;
			dfs(index + 1, nx, ny, sq1 - 1, sq2, sq3, sq4, sq5, reCnt - 1);
			//다시 복구시킨다.
			InsertSq(i, j, 1, 0);
		}
	}

	if (sq2 > 0) {
		if (checkInsert(i, j, 2)) {
			//도형을 놓을 다음위치를 찾는다.
			int nx, ny;
			pair<int, int> p = findPos();
			nx = p.first, ny = p.second;
			dfs(index + 1, nx, ny, sq1, sq2 - 1, sq3, sq4, sq5, reCnt - 4);
			//다시 복구시킨다.
			InsertSq(i, j, 2, 0);
		}
	}

	if (sq3 > 0) {
		if (checkInsert(i, j, 3)) {
			//도형을 놓을 다음위치를 찾는다.
			int nx, ny;
			pair<int, int> p = findPos();
			nx = p.first, ny = p.second;
			dfs(index + 1, nx, ny, sq1, sq2, sq3 - 1, sq4, sq5, reCnt - 9);
			//다시 복구시킨다.
			InsertSq(i, j, 3, 0);
		}
	}

	if (sq4 > 0) {
		if (checkInsert(i, j, 4)) {
			//도형을 놓을 다음위치를 찾는다.
			int nx, ny;
			pair<int, int> p = findPos();
			nx = p.first, ny = p.second;
			dfs(index + 1, nx, ny, sq1, sq2, sq3, sq4 - 1, sq5, reCnt - 16);
			//다시 복구시킨다.
			InsertSq(i, j, 4, 0);
		}
	}

	if (sq5 > 0) {
		if (checkInsert(i, j, 5)) {
			//도형을 놓을 다음위치를 찾는다.
			int nx, ny;
			pair<int, int> p = findPos();
			nx = p.first, ny = p.second;
			dfs(index + 1, nx, ny, sq1, sq2, sq3, sq4, sq5 - 1, reCnt - 25);
			//다시 복구시킨다.
			InsertSq(i, j, 5, 0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) remainCnt++;
		}
	int found = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (a[i][j] == 1) { sx = i; sy = j; found = true; break; }
		}
		if (found) break;
	}
	ans = 2147483647;
	dfs(0, sx, sy, 5, 5, 5, 5, 5, remainCnt);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}