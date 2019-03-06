#include<iostream>
#include<queue>
using namespace std;
int tc, n, m, cnt, t, cpySize;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		queue<pair<int, int>> ori, cpy;
		for (int i = 0; i < n; i++) {
			cin >> t;
			ori.push({ i,t });
			cpy.push({ i,t });
		}
		cnt = 1;
		while (!ori.empty()) {
			int index = ori.front().first, value = ori.front().second;
			ori.pop(); cpy.pop();
			//큐내부 확인
			cpySize = cpy.size();
			bool found = false;
			while (cpySize--) {
				if (value < cpy.front().second) {
					found = true;
					break;
				}
				cpy.pop();
			}
			if (found) ori.push({ index,value });
			else {
				if (index == m) break;
				cnt++;
			}
			cpy = ori;
		}
		cout << cnt << '\n';
	}
}