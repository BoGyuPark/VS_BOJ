/*2383. [모의 SW 역량테스트] 점심 식사시간*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int T, tc, n, map[11][11], sel[11], ans;
int st1Len[11], st2Len[11];
vector<pair<int, int>> v, l, r;
pair<int, int> stair[2];
queue<int> waitQ1, waitQ2, q1, q2;
void goDownStair(queue<int> &wait, queue<int> &q, int t, int stairIdx, int *pCnt) {
	while (true) {
		if (!q.empty() && t == q.front()) {
			q.pop();
			(*pCnt)--;
		}
		else break;
	}
	
	while (true) {
		if (!wait.empty() && t >= wait.front() && q.size() < 3) {
			int stairLen = map[stair[stairIdx].first][stair[stairIdx].second];
			
			if (t == wait.front()) q.push(wait.front() + stairLen);
			else q.push(t + stairLen);
			wait.pop();
		}
		else break;
	}

	return;
}
void simulate() {
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	for (int i = 0; i < l.size(); i++) waitQ1.push(l[i].first + 1);
	for (int i = 0; i < r.size(); i++) waitQ2.push(r[i].first + 1);
	int p1Cnt = l.size(), p2Cnt = r.size();
	int t = 0;
	while (true) {
		//stair1과 stair2는 독립적으로 실행
		goDownStair(waitQ1, q1, t, 0, &p1Cnt);
		goDownStair(waitQ2, q2, t, 1, &p2Cnt);
		if (p1Cnt == 0 && p2Cnt == 0) break;
		t++;
	}
	if (ans > t) ans = t;
	while (!q1.empty()) q1.pop();
	while (!q2.empty()) q2.pop();
	while (!waitQ1.empty()) waitQ1.pop();
	while (!waitQ2.empty()) waitQ2.pop();
}

void go(int index) {
	if (index == v.size()) {

		//팀 나누기
		for (int j = 0; j < v.size(); j++) {
			if (sel[j] == 0) l.push_back({ st1Len[j],j });
			else r.push_back({ st2Len[j],j });
		}

		//시뮬레이션
		simulate();
		l.clear(); r.clear();
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		go(index + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		int z = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) v.push_back({ i,j });
				else if (map[i][j] != 0) {
					stair[z] = { i,j };
					z++;
				}
			}
		}

		//사람과 각 계단 사이의 거리를 미리 저장해둔다.
		for (int i = 0; i < v.size(); i++) {
			int len = abs(v[i].first - stair[0].first) + abs(v[i].second - stair[0].second);
			st1Len[i] = len;
			len = abs(v[i].first - stair[1].first) + abs(v[i].second - stair[1].second);
			st2Len[i] = len;
		}

		ans = 2147483647;
		//두 계단에 사람 나누기
		go(0);
		cout << '#' << tc << ' ' << ans << '\n';
		v.clear();
	}
}