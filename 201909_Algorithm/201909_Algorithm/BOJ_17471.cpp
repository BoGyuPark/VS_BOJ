/*BOJ 17471 게리맨더링*/
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n, cost[11], sel[11], m, t, checkZero[11], checkOne[11], ans;
vector<vector<int>> v(11);
vector<int> zero, one;
queue<int> q;
struct info {
	int cnt, sum;
};
info Search(int start, int check[]) {
	info t;
	q.push(start);
	check[start] = true;
	t.cnt = 1;
	t.sum = cost[start];
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (check[next]) continue;
			check[next] = true;
			q.push(next);
			t.cnt++;
			t.sum += cost[next];
		}
	}
	return t;
}

void go(int index) {
	if (index == n) {
		int cnt = 0;
		memset(checkOne, 0, sizeof(checkOne));
		memset(checkZero, 0, sizeof(checkZero));
		zero.clear(); one.clear();
		//0구역과 1구역을 나누자.
		for (int j = 0; j < n; j++) {
			cnt += sel[j];
			if (sel[j] == 1) {
				checkZero[j + 1] = true;
				one.push_back(j + 1);
			}
			else {
				checkOne[j + 1] = true;
				zero.push_back(j + 1);
			}
		}

		//제외
		if (cnt == 0 || cnt == n) return;

		//탐색
		info ZeroResult = Search(zero[0], checkZero);
		if (ZeroResult.cnt != zero.size()) return;

		info OneResult = Search(one[0],checkOne);
		if (OneResult.cnt != one.size()) return;

		int dif = abs(ZeroResult.sum - OneResult.sum);
		if (ans > dif) ans = dif;
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		go(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin>>cost[i];
	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> t;
			v[i].push_back(t);
		}
	}
	ans = 2147483647;
	go(0);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}