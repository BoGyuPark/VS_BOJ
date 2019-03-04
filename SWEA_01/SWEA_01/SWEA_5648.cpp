#include<iostream>
#include<vector>
using namespace std;
int Test, T, n;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };
typedef struct info {
	int x, y, dir, k;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> n;
		int t1, t2, t3, t4;
		vector<info> now(n), prev(n);
		for (int i = 0; i < n; i++) {
			cin >> t1 >> t2 >> t3 >> t4;
			now[i] = { t1,t2,t3,t4 };
		}
		int ans = 0, t = 4003;
		while (t--) {
			//현재의 좌표를 prev로 복사
			prev = now;
			//각 좌표를 새로운 좌표로 이동 (한번씩 이동)
			for (int i = 0; i < n; i++) {
				if (now[i].k == -1) continue;
				now[i].x += dx[now[i].dir];
				now[i].y += dy[now[i].dir];
			}

			//1.5초 후 충돌하였는지 체크한다.
			for (int i = 0; i < n; i++) {
				if (now[i].k == -1) continue;
				//기준이 i번째에 있는 좌표
				int x = now[i].x, y = now[i].y;
				int collision = now[i].k;
				bool col = false;
				for (int j = 0; j < n; j++) {
					if (i == j || now[j].k == -1) continue;
					//1.5초 후에 충돌하는 경우
					if (x == prev[j].x && y == prev[j].y) {
						if (now[j].x == prev[i].x && now[j].y == prev[i].y) {
							collision += now[j].k;
							now[j].k = -1;
							col = true;
						}
					}
				}
				//해당좌표에서 충돌이 일어난경우 원자를 없앤다.
				if (col) {
					now[i].k = -1;
					ans += collision;
				}
			}
			//충돌하였는지 체크한다.
			for (int i = 0; i < n; i++) {
				if (now[i].k == -1) continue;
				//기준이 i번째에 있는 좌표
				int x = now[i].x, y = now[i].y;
				int collision = now[i].k;
				bool col = false;
				for (int j = 0; j < n; j++) {
					if (i == j || now[j].k == -1) continue;
					//충돌했다!
					if (x == now[j].x && y == now[j].y) {
						collision += now[j].k;
						//충돌당한 좌표의 원자는 -1로 변경
						now[j].k = -1;
						col = true;
					}
				}
				//해당좌표에서 충돌이 일어난경우 원자를 없앤다.
				if (col) {
					now[i].k = -1;
					ans += collision;
				}
			}

		}
		cout << '#' << T << ' ' << ans << '\n';
	}
}

