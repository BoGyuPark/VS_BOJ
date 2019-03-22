#include<iostream>
#include<vector>
using namespace std;
int tc, T, n;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int TranDir[5][4] = {{2,0,3,1},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,3,0,1}};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	for (T = 1; T <= tc; T++) {
		vector<pair<int, int>> emp;
		vector<pair<int, int>> hole[11];
		cin >> n;
		int a[102][102] = { 0, };
		//5¶ó´Â º®¸¸µë
		for (int i = 0; i <= n + 1; i++) {
			a[0][i] = 5;
			a[i][0] = 5;
			a[i][n + 1] = 5;
			a[n + 1][i] = 5;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 0) emp.push_back({ i,j });
				else if (a[i][j] >= 6 && a[i][j] <= 10) 
					hole[a[i][j]].push_back({ i,j });
			}
		}
		//cout << 'a';
		//½Ã¹Ä·¹ÀÌ¼Ç
		int hits = 0;
		int found = false;
		/*int i = 17;
		if(i==17){*/
		int ans = -1;
		for (int i = 0; i < emp.size(); i++) {
			int x = emp[i].first, y = emp[i].second;
			for (int j = 0; j < 4; j++) {
				hits = 0;
				//¹æÇâ±×´ë·Î Âß ÁøÇà
				int nx = x + dx[j], ny = y + dy[j];
				int dir = j;
				//cout << "start" << x << ',' << y << '\n';
				while (true) {
					//cout << nx << ',' << ny << '\n';
					//´Ù½Ã µ¹¾Æ¿Â°æ¿ì °ÔÀÓ³¡
					//ºí·¢È¦¸¸³²
					if ((nx == x && ny == y) || a[nx][ny] == -1) {
						//cout << hits << "\n\n";
						if (ans < hits) ans = hits;
						//cout << hits << '\n';
						break;
					}
					//ºóÄ­ ÀÌµ¿
					if (a[nx][ny] == 0) {
						nx += dx[dir];
						ny += dy[dir];
					}
					//º®¿¡ ºÎµúÈû
					else if(a[nx][ny]>=1 && a[nx][ny]<=5){
						dir = TranDir[a[nx][ny] - 1][dir];
						nx += dx[dir];
						ny += dy[dir];
						hits++;
					}
					//¿úÈ¦ÀÎ °æ¿ì
					else {
						int holenum = a[nx][ny];
						int NHx, NHy;
						//¹Ý´ëÆí ¿úÈ¦ÀÇ À§Ä¡ °¡Á®¿À±â
						for (int z = 0; z < 2; z++) {
							int t1, t2;
							t1 = hole[holenum][z].first;
							t2 = hole[holenum][z].second;
							if (nx == t1 && ny == t2) continue;
							NHx = t1; NHy = t2;
						}
						nx = NHx;
						ny = NHy;
						nx += dx[dir];
						ny += dy[dir];
					}
				}
			}
		}
		/*for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= n + 1; j++) cout << a[i][j] << ' ';
			cout << '\n';
		}

		for (int i = 6; i <= 10; i++) {
			if (hole[i].size() == 0) continue;
			for (int j = 0; j < 2; j++) {
				cout << i << ' ' << hole[i][j].first << ',' << hole[i][j].second << '\n';
			}
		}*/
		cout << '#' << T << ' ' << ans << '\n';
	}
}