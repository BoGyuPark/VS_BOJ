/*BOJ 16945 매직 스퀘어로 변경하기*/
#include<iostream>
using namespace std;
int map[9], sel[9], check[9];
const int n = 9;
int ans = 2147483647;
bool findRow() {
	int t1, t2, t3;
	t1 = sel[0] + sel[1] + sel[2];
	t2 = sel[3] + sel[4] + sel[5];
	t3 = sel[6] + sel[7] + sel[8];
	if (t1 == 15 && t2 == 15 && t3 == 15) return true;
	return false;
}
bool findCol() {
	int t1, t2, t3;
	t1 = sel[0] + sel[3] + sel[6];
	t2 = sel[1] + sel[4] + sel[7];
	t3 = sel[2] + sel[5] + sel[8];
	if (t1 == 15 && t2 == 15 && t3 == 15) return true;
	return false;
}
bool findDia() {
	int t1, t2;
	t1 = sel[0] + sel[4] + sel[8];
	t2 = sel[2] + sel[4] + sel[6];
	if (t1 == 15 && t2 == 15) return true;
	return false;
}
void go(int index) {
	if (index == n) {
		if (findRow() && findCol() && findDia()) {
			int sum = 0;
			for (int j = 0; j < n; j++) sum += abs(map[j] - sel[j]);
			if (ans > sum) ans = sum;
		}
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (check[i]) continue;
		check[i] = true;
		sel[index] = i + 1;
		go(index + 1);
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) cin >> map[i];
	go(0);
	cout << ans;
}