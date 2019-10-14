#include<iostream>
#include<algorithm>
using namespace std;
int n, inning[51][10], sel[11], order[11], c[11], ans;
void simulate() {
	int idx = 0;
	int stateBit = 0;
	int score = 0, strike = 0;
	for (int r = 1; r <= n; r++) {
		strike = 0;
		stateBit = 0;
		while (strike!=3) {
			int state = inning[r][order[idx]];

			if (state >= 1) {
				if (state == 4) {
					for (int i = 0; i < 3; i++) {
						if (stateBit &(1 << i)) score++;
					}
					score++;
					stateBit = 0;
				}
				else {
					stateBit = (stateBit << state) + (1 << (state - 1));
					for (int i = 3; i < 7; i++) {
						if (stateBit &(1 << i)) score++;
					}
					stateBit = stateBit & 7;
				}
			}
			else strike++;
			idx = (idx + 1) % 9;
		}
	}
	ans = max(ans, score);
}
void go(int index) {
	if (index == 8) {	
		for (int j = 0, a = 0; j < index; j++) {
			if (a == 3) a++;
			order[a] = sel[j];
			a++;
		}
		simulate();
		return;
	}
	for (int i = 2; i <= 9; i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> inning[i][j];
		}
	}
	order[3] = 1;
	go(0);
	cout << ans;
}