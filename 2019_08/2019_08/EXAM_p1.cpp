/*업글 개미*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, T, tc, ans, sel[13], finishFlag;
int preIdx[13][13], idx[13], cpyIdx[13];
vector<int> dir, cpyDir, s, cpyS, origin;

void swapping(int t) {

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (dir[j] == 0 && dir[j + 1] == 1) {
				swap(dir[j], dir[j + 1]);
				swap(idx[j], idx[j + 1]);
				j++;
			}
		}
	}

}

bool isSort() {
	int dif = abs(s[0]-s[1]);
	if (dif != 1) return false;

	for (int i = 1; i < n - 1; i++) {
		if (dif != abs(s[i] - s[i + 1])) return false;
	}
	return true;
}

void changeCard(int k) {
	int temp[13] = { 0, };
	for (int i = 0; i < n; i++) {
		s[i] = cpyS[preIdx[k][i]];
	}
	cpyS = s;
}

void go(int index, int dest) {
	if (finishFlag) return;
	if (index == dest) {

		for (int j = 0; j < dest; j++) {
			if (sel[j] == 0) continue;		
			changeCard(sel[j]);
		}

		if (isSort() && ans > dest) {
			ans = dest;
			finishFlag = true;
			return;
		}
		cpyS = origin;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (index == 0 || sel[index - 1] != i) {
			sel[index] = i;
			go(index + 1, dest);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		//0은 ->, 1은 <- , 01일때만 swap
		for (int i = 0; i < n; i++) {
			if (i < n / 2) dir.push_back(0);
			else dir.push_back(1);
		}

		int t;
		for (int i = 0; i < n; i++) {
			cin >> t;
			s.push_back(t);
		}

		//복사본
		cpyDir = dir;
		origin = cpyS = s;
		for (int i = 0; i < n; i++) idx[i] = cpyIdx[i] = preIdx[0][i] = i;
		
		// 1 ~ n-1까지 셔플한 인덱스를 한번 미리 저장해 두자.
		for (int j = 1; j < n; j++) {
			swapping(j);
			for (int i = 0; i < n; i++) preIdx[j][i] = idx[i];
			for (int i = 0; i < n; i++) idx[i] = cpyIdx[i];
			dir = cpyDir;
		}
		
		ans = 2147483647;
		finishFlag = false;

		//초기 세팅
		if (isSort()) ans = 0;
		else {
			//271,425가지
			for (int i = 1; i <= 5; i++) go(0, i);
		}
		if (ans == 2147483647) ans = -1;
		cout << '#' << tc << ' ' << ans << '\n';
		dir.clear();
		s.clear();
	}
}