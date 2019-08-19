/*BOJ 16958 텔레포트*/
#include<iostream>
#include<vector>
using namespace std;
int n, t, s, x, y, m, a, b;
typedef struct {
	int s, x, y;
}info;
vector<info> v, tel;
void solve(int s, int e) {
	int dist = abs(v[s].x - v[e].x) + abs(v[s].y - v[e].y);

	if (v[s].s == 1 && v[e].s == 1) {
		if (dist > t) dist = t;
	}
	else if (v[s].s == 0 && v[e].s == 1) {
		for (int i = 0; i < tel.size(); i++) {
			int temp = abs(v[s].x - tel[i].x) + abs(v[s].y - tel[i].y);
			if (dist > temp + t) dist = temp + t;
		}
	}
	else if (v[s].s == 0 && v[e].s == 0) {
		for (int i = 0; i < tel.size(); i++) {
			int temp = abs(v[s].x - tel[i].x) + abs(v[s].y - tel[i].y);
			for (int j = 0; j < tel.size(); j++) {
				int temp2 = abs(v[e].x - tel[j].x) + abs(v[e].y - tel[j].y);
				if (i == j) {
					if (dist > temp + temp2) dist = temp + temp2;
				}
				else {
					if (dist > temp + temp2 + t) dist = temp + temp2 + t;
				}
			}
		}
	}
	else {	//1 0
		for (int i = 0; i < tel.size(); i++) {
			int temp = abs(v[e].x - tel[i].x) + abs(v[e].y - tel[i].y);
			if (dist > temp + t) dist = temp + t;
		}
	}
	cout << dist << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> s >> x >> y;
		if (s == 1) tel.push_back({ s,x,y });
		v.push_back({ s,x,y });
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		solve(a - 1, b - 1);
	}
	return 0;
}