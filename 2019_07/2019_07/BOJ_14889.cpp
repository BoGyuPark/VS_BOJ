/*BOJ 14889 스타트와 링크*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[20][20], n;
vector<int> start, link;
int check[20], sel[20];
int ans;
void go(int index, int start_cnt, int link_cnt) {
	if (index == n) {
		for (int j = 0; j < n; j++) {
			if (sel[j] == 0) start.push_back(j);
			else link.push_back(j);
		}
		int startSum = 0, linkSum = 0;
		for (int a = 0; a < n / 2; a++) {
			for (int b = a + 1; b < n / 2; b++) {
				startSum += (arr[start[a]][start[b]]+ arr[start[b]][start[a]]);
				linkSum += (arr[link[a]][link[b]] + arr[link[b]][link[a]]);
			}
		}
		ans = min(ans, abs(startSum - linkSum));
		start.clear();
		link.clear();
		return;
	}

	if (start_cnt < n / 2) {
		sel[index] = 1;
		go(index + 1, start_cnt + 1, link_cnt);
		sel[index] = 0;
	}

	if (link_cnt < n / 2) {
		go(index + 1, start_cnt, link_cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
	ans = 2147483647;
	go(0, 0, 0);
	cout << ans;
}