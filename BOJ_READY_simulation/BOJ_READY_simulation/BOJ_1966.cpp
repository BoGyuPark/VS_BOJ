#include<iostream>
#include<deque>
using namespace std;
int t, n, m, pr, index, cnt;
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		//index와 중요도
		deque <pair<int, int>> dq(n),t;
		for (int i = 0; i < n; i++) {
			cin >> dq[i].second;
			dq[i].first = i;
		}
		while(true){
			pr = dq.front().second; index = dq.front().first;
			cnt = 0;
			for (int j = 1; j < dq.size(); j++) {
				if (pr < dq[j].second) {
					dq.push_back({ index,pr });
					dq.pop_front();
					break;
				}
				else cnt++;
			}
			if (dq.size() == 1) {
				t.push_back({ index,pr });
				dq.pop_front();
				break;
			}
			else if (cnt == dq.size() - 1) {
				t.push_back({ index,pr });
				dq.pop_front();
			}
		}
		for (int i = 0; i < t.size(); i++)
			if (t[i].first == m) cout << i + 1 << '\n';
	}
}