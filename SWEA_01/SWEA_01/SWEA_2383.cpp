#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T, Test, n, a[10][10], sel[10], person, t;
vector<pair<int, int>> v,s;
queue <int> q1, q2;
void simulate() {
	t = 1;
	int s1Value = a[s[0].first][s[0].first];
	int s1TimeOut = 0;
	int s1cnt = 0, s2cnt = 0;
	int Q1size, Q2size;
	while (true) {
		if (s1TimeOut == 0) {
			Q1size = q1.size();
		}
		while (Q1size--) {
			int now = q1.front();
			q1.pop();
			now--;
			if (now == 0) s1cnt++;
			else q1.push(now);

			if (s1cnt == 3) {
				s1TimeOut = s1Value;
				break;
			}
		}
		s1TimeOut--;
		t++;
	}
}

void go(int index) {
	if (index == person) {
		while (!q1.empty()) {
			q1.pop();
		}
		while (!q2.empty()) {
			q2.pop();
		}
		if (sel[4] == 1 && sel[5] == 1 && sel[0] == 0 && sel[1] == 0 && sel[2] == 0 && sel[3] == 0)
			cout << 'a';
		for (int j = 0; j < person; j++) {
			if (sel[j] == 0) {
				int dif = abs(v[j].first - s[0].first) + abs(v[j].second - s[0].second);
				q1.push(dif);
			}
			else {
				int dif = abs(v[j].first - s[1].first) + abs(v[j].second - s[1].second);
				q2.push(dif);
			}
		}
		simulate();

		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		go(index + 1);
	}
}
int main() {
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 1) v.push_back({ i,j });
				else if (a[i][j] != 0) s.push_back({ i,j });
			}
		}
		person = v.size();
		go(0);
	
	}
}