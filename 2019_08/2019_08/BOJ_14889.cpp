/*BOJ 14889 스타트와 링크*/
#include<iostream>
#include<vector>
using namespace std;
int n, map[21][21], sel[21], ans = 2147483647;
vector<int> start, link;
void go(int index, int stCnt, int liCnt) {
	if (index == n) {
		for (int j = 0; j < n; j++) {
			if (sel[j] == 1) start.push_back(j);
			else link.push_back(j);
		}
		int startSum = 0, linkSum = 0;
		for (int j = 0; j < n / 2; j++) {
			for (int z = j + 1; z < n / 2; z++) {
				startSum += (map[start[j]][start[z]] + map[start[z]][start[j]]);
				linkSum += (map[link[j]][link[z]] + map[link[z]][link[j]]);
			}
		}
		int dif = abs(startSum - linkSum);
		if (ans > dif) ans = dif;
		start.clear();
		link.clear();
		return;
	}

	if (stCnt < n / 2) {
		sel[index] = 1;
		go(index + 1, stCnt + 1, liCnt);
		sel[index] = 0;
	}

	if (liCnt < n / 2) {
		go(index + 1, stCnt, liCnt + 1);
	}
	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cin >> map[i][j];
	go(0,0,0);
	cout << ans;
}