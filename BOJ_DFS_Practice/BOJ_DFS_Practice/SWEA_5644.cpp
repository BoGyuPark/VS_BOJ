#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int Tc, T, m, a, map[9][11][11];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ddx[] = { 0,-1,0,1,0 };
int ddy[] = { 0,0,1,0,-1 };
typedef struct info {
	int x, y, dist, power, order;
};
void bfs(info ex) {
	int nowx = ex.x, nowy = ex.y, d = ex.dist, p = ex.power, lay = ex.order;
	int c[11][11] = { 0, };
	c[nowx][nowy] = true;
	map[lay][nowx][nowy] = p;
	queue<pair<int, int>> q;
	q.push({ nowx,nowy });
	while (d--) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 1 || ny < 1 || nx >= 11 || ny >= 11) continue;
				if (c[nx][ny] == true) continue;
				c[nx][ny] = true;
				q.push({ nx,ny });
				map[lay][nx][ny] = p;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> Tc;
	for (T = 1; T <= Tc; T++) {
		int amove[105] = { 0, }, bmove[105] = { 0, };
		cin >> m >> a;
		for (int i = 1; i <= m; i++) cin >> amove[i];
		for (int i = 1; i <= m; i++) cin >> bmove[i];
		int t1, t2, t3, t4;
		queue<info> bcinfo;
		for (int i = 0; i < a; i++) {
			cin >> t1 >> t2 >> t3 >> t4;
			bcinfo.push({ t2,t1,t3,t4,i + 1 });
		}
		//BC의 범위를 구한다.
		while (!bcinfo.empty()) {
			bfs(bcinfo.front());
			bcinfo.pop();
		}
		
		//A는 0,0부터 ,B는 10,10부터 시작한다.
		int ax = 1, ay = 1, bx = 10, by = 10;
		int ASum = 0, BSum = 0;
		for (int t = 0; t <= m; t++) {
			//t초일때 A와 B의 좌표를 구한다.
			ax += ddx[amove[t]], ay += ddy[amove[t]];
			bx += ddx[bmove[t]], by += ddy[bmove[t]];
			//A,B의 좌표에서 BC의 범위인지를 체크한다.
			//          BC번호, 값
			vector<pair<int,int>> ar, br;
			for (int i = 1; i <= a; i++) {
				if (map[i][ax][ay] != 0) ar.push_back({ i, map[i][ax][ay] });
				if (map[i][bx][by] != 0) br.push_back({ i, map[i][bx][by] });
			}
			
			//A와 B에 해당하는 갯수에 따라 값을 다르게 정한다.
			if (ar.size() == 1 && br.size() == 1) {
				//같은 BC인 경우
				if (ar[0].first == br[0].first) {
					ASum += ar[0].second / 2;
					BSum += br[0].second / 2;
				}
				else {
					ASum += ar[0].second;
					BSum += br[0].second;
				}
			}
			else {
				int maxi = 0, am = 0, bm = 0;
				if (ar.size() == 0 && br.size() == 0) continue;
				if (ar.size() == 0) {
					for (int i = 0; i < br.size(); i++) {
						if (maxi < br[i].second) maxi = br[i].second;
					}
					BSum += maxi;
				}
				else if (br.size() == 0) {
					for (int i = 0; i < ar.size(); i++) {
						if (maxi < ar[i].second) maxi = ar[i].second;						
					}
					ASum += maxi;
				}
				else {
					for (int i = 0; i < ar.size(); i++) {
						for (int j = 0; j < br.size(); j++) {
							int tar = ar[i].second, tbr = br[j].second;
							int temp = tar + tbr;
							if (tar == tbr && ar[i].first == br[j].first)
								temp /= 2;
							if (maxi < temp) {
								am = i; bm = j;
								maxi = temp;
							}
						}
					}
					ASum += ar[am].second;
					BSum += br[bm].second;
				}
			}
			//cout << ASum << ' ' << BSum << '\n';
		}
		cout << '#' << T << ' ' << ASum + BSum << '\n';
		memset(map, 0, sizeof(map));
	}
}