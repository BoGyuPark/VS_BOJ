#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define MAX 20
using namespace std;
int n, k, map[10][10], blist[21], clist[21], sel[MAX], ans = 0, c[MAX];
int Winner, noEnter, wins[4], maxi, bpivot, cpivot;
bool Nopro = false;
queue<int> q, bq, cq;
void fight(int w, int no) {
	int f, se;
	if (w == 1) {
		if (q.empty()) { Nopro = true; return; }
		f = q.front();
		q.pop();
	}
	else {
		if (w == 2) f = blist[bpivot++];
		else f = clist[cpivot++];
	}

	if (no == 1) {
		if (q.empty()) { Nopro = true; return; }
		se = q.front();
		q.pop();
	}
	else {
		if (no == 2) se = blist[bpivot++];
		else se = clist[cpivot++];
	}

	int t = map[f][se];
	if (t == 2) {
		Winner = w;
		noEnter = (6 - w - no);
	}
	else if (t == 0) {
		Winner = no;
		noEnter = (6 - no - w);
	}
	else {
		Winner = max(w, no);
		noEnter = (6 - w - no);
	}
	wins[Winner]++;
}

void solve() {
	// 1Àº A, 2Àº B, 3´Â C
	Winner = 1; noEnter = 2;
	Nopro = false;
	memset(wins, 0, sizeof(wins));
	bpivot = 0; cpivot = 0;
	for (int r = 0; r < maxi; r++) {
		fight(Winner, noEnter);
		if (Nopro == true) return;
		for (int x = 1; x <= 3; x++) {
			if (wins[x] >= k) {
				if (x == 1) ans = 1;
				return;
			}
		}
	}
}


void go(int index) {
	if (index == n) {
		while (!q.empty()) { q.pop(); }
		for (int j = 0; j < n; j++) q.push(sel[j]);
		solve();
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = i + 1;
		go(index + 1);
		c[i] = false;
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> map[i][j];

	int temp;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 20; i++) {
			cin >> temp;
			if (j == 0) blist[i] = temp;
			else clist[i] = temp;
		}
	}

	maxi = (3 * (k - 1) + 1);
	go(0);
	cout << ans;
}