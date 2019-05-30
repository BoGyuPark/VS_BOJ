#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, sharkCnt;
//          상 하 우 좌
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int transDir[] = { 1,0,3,2 };
typedef struct info {
	int live = 1, id, r, c, moveCnt, dir, Size;
};
vector<int> map[100][100];
vector<info> shark;
void printCheck() {
	//해당 물고기 죽이기
	for (int z = 0; z < shark.size(); z++) {
		if (shark[z].live == 1) {
			cout << z << ' ' << shark[z].r << ' ' << shark[z].c << ' ' << shark[z].Size << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> sharkCnt;
	for (int i = 0; i < sharkCnt; i++) {
		info t;
		cin >> t.r >> t.c >> t.moveCnt >> t.dir >> t.Size;
		t.r--; t.c--; t.dir--;
		t.id = i;
		shark.push_back(t);
		map[t.r][t.c].push_back(t.Size);
	}
	int ans = 0;
	//먼저 물고기부터 잡는다.
	for (int i = 0; i < m; i++) {
		/*if (i == 4)
			cout << 'a';*/
		for (int j = 0; j < n; j++) {
			if (map[j][i].size() > 0) {
				for (int z = 0; z < shark.size(); z++) {
					if (shark[z].r == j && shark[z].c == i && shark[z].live==1) {
						shark[z].live = 0;
						ans += shark[z].Size;
						break;
					}
				}
				break;
			}
		}
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				map[r][c].clear();
			}
		}
		//cout << i << "번째" << '\n';
		//물고기 이동
		for (int z = 0; z < shark.size(); z++) {
			if (shark[z].live == 0) continue;			
			
			//한칸씩 이동
			int x = shark[z].r, y = shark[z].c;
			int dir = shark[z].dir;
			int nx = x, ny = y;
			for (int w = 0; w < shark[z].moveCnt; w++) {
				nx = x + dx[dir];
				ny = y + dy[dir];
				//방향 바꿔줌
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
					dir = transDir[dir];
					nx = x + dx[dir];
					ny = y + dy[dir];
				}
				x += dx[dir]; y += dy[dir];
			}

			shark[z].r = nx;
			shark[z].c = ny;
			shark[z].dir = dir;
			map[nx][ny].push_back(shark[z].Size);
			//cout <<z<<' '<< nx << ' ' << ny << ' ' << shark[z].Size << '\n';
		}

		//물고기 합치기
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				int BigSize;
				if (map[r][c].size() > 1) {
					sort(map[r][c].begin(), map[r][c].end());
					//가장 큰 물고기의 크기 찾기
					BigSize = map[r][c][map[r][c].size() - 1];

					//해당 물고기 죽이기
					for (int z = 0; z < shark.size(); z++) {
						if (shark[z].r == r && shark[z].c == c && shark[z].Size != BigSize) {
							shark[z].live = 0;
						}
					}
				}
			}
		}
		
	}
	
	cout << ans;
}