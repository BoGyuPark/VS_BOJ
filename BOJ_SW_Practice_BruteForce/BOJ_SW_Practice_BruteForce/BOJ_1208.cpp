#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, s, arr[41];
long long ans = 0 , partsum = 0;
vector<int> up, down;
void go(int sum, int index, int dest, vector<int> &v) {
	if (index == dest) {
		v.push_back(sum);
		return;
	}
	go(sum + arr[index], index + 1, dest, v);
	go(sum, index + 1, dest, v);
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	go(0, 0, n / 2, up); 
	go(0, n / 2, n, down);
	sort(up.begin(), up.end()); sort(down.begin(), down.end());
	int l = 0, r = down.size() - 1;
	while (l < up.size() && r >= 0) {
		partsum = up[l] + down[r];
		if (partsum > s) {
			r--;
		}
		else if (partsum < s) {
			l++;
		}
		else {
			long long upcnt = 1, downcnt = 1;
			for (int i = l + 1; i < up.size(); i++) {
				if (up[l] == up[i]) upcnt++;
				else break;
			}
			for (int i = r - 1; i >= 0; i--) {
				if (down[r] == down[i]) downcnt++;
				else break;
			}
			ans += upcnt * downcnt;
			r -= downcnt; l += upcnt;
		}
	}
	if (s == 0) ans--;
	cout << ans;
}