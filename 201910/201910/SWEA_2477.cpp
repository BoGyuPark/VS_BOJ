#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int T, tc, n, m, k, A, B, a[10], b[10], exitCnt = 0;
queue<pair<int, int>> rWaiting, fWaiting, receptionBox[10], fixBox[10];
vector<int> reception[10], fix[10];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> m >> k >> A >> B;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= m; i++) cin >> b[i];
		for (int i = 1; i <= k; i++) {
			int temp; cin >> temp;
			rWaiting.push({ i,temp });
		}
		exitCnt = 0;
		int t = 0;
		while (true)
		{
			//접수창구에서 종료된 고객 정비 웨이팅에 넣기
			for (int i = 1; i <= n; i++) {
				if (!receptionBox[i].empty()) {
					if (t == receptionBox[i].front().second) {
						fWaiting.push(receptionBox[i].front());
						receptionBox[i].pop();
					}
				}
			}

			//접수창구에 빈곳부터 넣기
			while (!rWaiting.empty() && rWaiting.front().second <= t) {
				int flag = 0;
				for (int i = 1; i <= n; i++) {
					if (receptionBox[i].empty()) {
						pair<int, int> temp = rWaiting.front();
						rWaiting.pop();
						receptionBox[i].push({ temp.first,t + a[i] });
						reception[i].push_back(temp.first);
						break;
					}
					else flag++;
				}
				if (flag == n) break;
			}

			//정비창구에서 종료된 고객 빼기
			for (int i = 1; i <= m; i++) {
				if (!fixBox[i].empty()) {
					if (t == fixBox[i].front().second) {
						fixBox[i].pop();
						exitCnt++;
					}
				}
			}

			//정비 웨이팅에서 시간에 맞는 고객 정비 창구로 넣기
			while (!fWaiting.empty() && fWaiting.front().second <= t) {
				int flag = 0;

				for (int i = 1; i <= m; i++) {
					if (fixBox[i].empty()) {
						pair<int, int> temp = fWaiting.front();
						fWaiting.pop();
						fixBox[i].push({ temp.first,t + b[i] });
						fix[i].push_back(temp.first);
						break;
					}
					else flag++;
				}
				if (flag == m) break;
			}
			
			
			t++;
			if (exitCnt == k) break;
		}
		int ans = 0;
		for (int i = 0; i < reception[A].size(); i++) {
			for (int j = 0; j < fix[B].size(); j++) {
				if (reception[A][i] == fix[B][j]) ans += fix[B][j];
			}
		}
		if (ans == 0) ans = -1;
		cout << '#' << tc << ' ' << ans << '\n';
		memset(fix, 0, sizeof(fix)); fix->resize(10);
		memset(reception, 0, sizeof(reception)); reception->resize(10);
	}
}