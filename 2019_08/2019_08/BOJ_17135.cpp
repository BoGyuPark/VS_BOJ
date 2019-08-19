/*BOJ 17135 캐슬 디펜스*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
int n, m, d, map[17][17], sel[17], c[17], check[16][16], ans;
typedef struct {
	int dist, col, idx;
}info;

struct cmp {
	bool operator()(info a, info b) {
		if (a.dist > b.dist) {
			return true;
		}
		else if (a.dist == b.dist) {
			return a.col > b.col;
		}
		else {
			return false;
		}
	}
};

//			열 행
vector<pair<int, int>> enemy, cpy, temp;
priority_queue < info, vector<info>, cmp > pq;
queue<pair<int, int>> q;		//최종적으로 죽일 적

int findEnemy() {
	memset(check, 0, sizeof(check));
	int cnt = 0;
	//아처마다 죽일 적을 선택.
	int dist = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < enemy.size(); j++) {
			dist = abs(n - enemy[j].second) + abs(sel[i] - enemy[j].first);
			if (dist <= d) {
				pq.push({ dist,enemy[j].first,j });
			}
		}
		//행, 열
		if (pq.size() > 0) {
			q.push({ enemy[pq.top().idx].second,enemy[pq.top().idx].first });
			while (!pq.empty()) pq.pop();
		}
	}

	//remove enemey
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (check[x][y] == false) {
			cnt++;
			check[x][y] = true;
		}
	}
	
	//new enemylist
	for (int j = 0; j < enemy.size(); j++) {
		if (check[enemy[j].second][enemy[j].first] == false) {
			int x = enemy[j].second, y = enemy[j].first;
			if (x + 1 == n) continue;
			temp.push_back({ y,x + 1 });
		}
	}
	enemy.clear();
	enemy = temp; 
	temp.clear();
	return cnt;
}

int simulate() {
	int sum = 0;
	while (enemy.size() > 0) {
		//제거
		sum += findEnemy();
	}
	return sum;
}

void go(int index,int start) {
	if (index == 3) {
		int s = simulate();
		if (ans < s) ans = s;
		enemy.clear(); temp.clear();
		enemy = cpy;
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
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				cpy.push_back({ j,i });
				enemy.push_back({ j,i });
				map[i][j] = 0;
			}
		}
	}
	go(0,0);
	cout << ans;
}