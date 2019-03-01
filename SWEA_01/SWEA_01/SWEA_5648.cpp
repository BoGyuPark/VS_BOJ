#include<iostream>
#include<vector>
using namespace std;
int T, TC, n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef struct atom {
	int xp, yp, d, e;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> TC;
	for (T = 1; T <= TC; T++) {
		cin >> n;
		vector<atom> v;
		for (int i = 0; i < n; i++) {
			int xpos, ypos, dir, k;
			cin >> xpos >> ypos >> dir >> k;
			xpos += 1000;
			ypos = -ypos; ypos += 1000;
			v.push_back({ ypos,xpos,dir,k });
		}
		int Limit = 2000, ans = 0;
		while (Limit--) {
			//한 번씩 이동을 시킨다. (좌표만)
			int cnt = 0;
			for (int i = 0; i < v.size(); i++) {
				int x = v[i].xp, y = v[i].yp, dir = v[i].d, energy = v[i].e;
				if (energy == 0) {cnt++; continue;}
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx > 2000 || ny > 2000) continue;
				v[i].xp = nx; v[i].yp = ny;
			}
			if (cnt == v.size()) break;
			//충돌검사
			int c[1001] = { 0, };
			for (int i = 0; i < v.size(); i++) {
				int temp = v[i].e;
				for (int j = i + 1; j < v.size(); j++) {
					//원자끼리 좌표가 같아 충돌한 경우.
					if (c[i] == true) continue;
					if (v[i].xp == v[j].xp && v[i].yp == v[j].yp) {
						temp += v[j].e;
						c[j] = true;
						//원자를 없애야한다.
						v[j].e = 0;
					}
				}
				//충돌한경우
				if (temp != v[i].e) {
					ans += temp;
					v[i].e = 0;
				}
			}
		}
		cout << '#' << T << ' ' << ans << '\n';
	}
}