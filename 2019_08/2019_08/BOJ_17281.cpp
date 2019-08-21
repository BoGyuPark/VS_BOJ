/*BOJ 17281 야구*/
#include<iostream>
#include<queue>
using namespace std;
int n, order[51][9], sel[9], check[9], realOrder[9], Idx;
int ans, cnt;
queue<int> q;
void simulate() {
	cnt = 0;
	int outCnt = 0;
	Idx = 0;

	for (int r = 0; r < n; r++) {

		while (true) {
			int state = order[r][realOrder[Idx]];
			if (state == 0) outCnt++;
			else {
				int Qsize = q.size();
				
				while (Qsize--) {
					int now = q.front(); q.pop();
					if (now + state >= 4) cnt++;
					else q.push(now + state);
				}
				if (state == 4) cnt++;
				else q.push(state);
			}
			Idx = (Idx + 1) % 9;
			//종료
			if (outCnt == 3) {
				outCnt = 0;
				break;
			}
		}
		while (!q.empty()) q.pop();
	}
	if (ans < cnt) ans = cnt;
}

void go(int index) {
	if (index == 8) {
		int idx = 0;
		for (int j = 0; j < 8; j++) {
			if (idx == 3) idx++;
			realOrder[idx] = sel[j];
			idx++;
		}
		//순서 확정
		simulate();
		return;
	}
	for (int i = 1; i < 9; i++) {
		if (check[i]) continue;
		check[i] = true;
		sel[index] = i;
		go(index + 1);
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) cin >> order[i][j];
	}	
	go(0);
	cout << ans;
}