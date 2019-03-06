#include<iostream>
#include<vector>
using namespace std;
int Test, T, n, map[4010][4010];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };
typedef struct info {
	int x, y, dir, k;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> n;
		int t1, t2, t3, t4;
		vector<info> v, temp;
		for (int i = 0; i < n; i++) {
			cin >> t1 >> t2 >> t3 >> t4;
			v.push_back({ (t1 + 1000) * 2,(t2 + 1000) * 2,t3,t4 });
		}

		int ans = 0, t = 2000;
		while (!v.empty()) {
			//각 좌표를 새로운 좌표로 이동 (한번씩 이동)
			int Vsize = v.size();
			for (int i = 0; i < Vsize; i++) {
				int x = v[i].x, y = v[i].y, d = v[i].dir;
				map[y][x] = 0;
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {
					v[i].k = 0;
					continue;
				}
				v[i].x = nx;
				v[i].y = ny;
				map[ny][nx] += v[i].k;
			}
			//충돌인 지역 확인
			for (int i = 0; i < Vsize; i++) {
				if (v[i].k == 0) continue;
				//충돌이 일어난 경우
				if (map[v[i].y][v[i].x] != v[i].k) {
					ans += map[v[i].y][v[i].x];
					map[v[i].y][v[i].x] = 0;
					v[i].k = 0;
				}
			}
			temp = v;
			v.clear();
			for (int i = 0; i < temp.size(); i++)
				if (temp[i].k != 0) v.push_back(temp[i]);
		}
		cout << '#' << T << ' ' << ans << '\n';
	}
}
