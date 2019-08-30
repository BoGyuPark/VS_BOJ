/*BOJ 1268 임시 반장 정하기*/
#include<iostream>
#include<cstring>
using namespace std;
int n, map[1001][6], cntArr[1001], checkFriend[1001];
int cal(int findNum, int r, int c) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i == r) continue;
		if (map[i][c] == findNum) {
			if (checkFriend[i] == false) {
				checkFriend[i] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= 5; j++) cin >> map[i][j];
		
	for (int i = 1; i <= n; i++) {
		memset(checkFriend, 0, sizeof(checkFriend));
		int sum = 0;
		for (int j = 1; j <= 5; j++) {
			sum += cal(map[i][j], i, j);
		}
		cntArr[i] = sum;
	}
	int maxi = -1, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (maxi < cntArr[i]) {
			maxi = cntArr[i];
			ans = i;
		}
	}
	cout << ans;
}