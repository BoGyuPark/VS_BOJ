#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, D, map[17][17], ans, sel[4], c[20];
struct info {
	int x, y;
	bool isAlive;
};
struct enemy {
	int dist, y, idx;
};
vector<info> v, cpy;
vector<enemy> dielist;
vector<int> die;
bool cmp(const enemy &a, const enemy &b) {
	if (a.dist < b.dist) return true;
	else if (a.dist == b.dist) {
		return a.y < b.y;
	}
	else return false;
}

void simulate() {
	int cnt = 0, totalEnemyCnt = v.size();

	while (totalEnemyCnt!=0) {

		for (int i = 0; i < 3; i++) {
			int x = n, y = sel[i];
			
			for (int j = 0; j < v.size(); j++) {
				if (!v[j].isAlive) continue;
				int dist = abs(x - v[j].x) + abs(y - v[j].y);
				if(dist<=D) dielist.push_back({ dist,v[j].y,j });
			}
			sort(dielist.begin(), dielist.end(), cmp);
			if (!dielist.empty()) {
				die.push_back(dielist[0].idx);
			}
			dielist.clear();
		}

		for (int i = 0; i < die.size(); i++) {
			if (v[die[i]].isAlive) {
				v[die[i]].isAlive = false;
				cnt++;
				totalEnemyCnt--;
			}
		}
		die.clear();
		for (int j = 0; j < v.size(); j++) {
			if (!v[j].isAlive) continue;
			int nx = v[j].x + 1;
			if (nx == n) {
				totalEnemyCnt--;
				v[j].isAlive = false;
			}
			else v[j].x = nx;
		}
	}
	ans = max(ans, cnt);
}
void go(int index, int start) {
	if (index == 3) {
		simulate();
		v.clear();
		v = cpy;
		return;
	}
	for (int i = start; i < m; i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1, i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> D;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				v.push_back({ i,j,true });
				cpy.push_back({ i,j,true });
			}
		}
	}
	go(0, 0);
	cout << ans;
}