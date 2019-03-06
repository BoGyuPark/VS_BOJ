#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k, a[11][11], ad[11][11];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
typedef struct info {
	int x, y;
	vector<int> ages;
};

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> ad[i][j];
	vector<info> v;
	int tx, ty, ta;
	for (int i = 0; i < m; i++) {
		cin >> tx >> ty >> ta;
		info tr; tr.x = tx - 1; tr.y = ty - 1; tr.ages.push_back(ta);
		v.push_back(tr);
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] = 5;

	//봄,여름,가을,겨울
	while (k--) {
		if (k == 1)
			cout << 'a';
		//v는 나무가 있는 각 좌표와 나무들의 나이를 갖는다.
		int Vsize = v.size();
		for (int i = 0; i < Vsize; i++) {
			int treecnt = v[i].ages.size();
			vector<int> deadtree;
			for (int j = 0; j < treecnt; j++) {
				//양분이 나무의 나이를 빼도 괜찮을때
				if (v[i].ages[j] == 0) continue;
				if (a[v[i].x][v[i].y] - v[i].ages[j] >= 0) {
					a[v[i].x][v[i].y] -= v[i].ages[j];
					v[i].ages[j]++;
				}
				else {
					deadtree.push_back(v[i].ages[j]);
					v[i].ages[j] = 0;
				}
			}
			//죽은 나무의 절반을 양분으로 추가
			for (int z = 0; z < deadtree.size(); z++)
				a[v[i].x][v[i].y] += deadtree[z];
			//나무 나이가 5의 배수이면 8자리에 나무 증식
			for (int j = 0; j < treecnt; j++) {
				if (v[i].ages[j] == 0) continue;
				if (v[i].ages[j] % 5 == 0) {
					for (int z = 0; z < 8; z++) {
						bool found = false;
						int nx = v[i].x + dx[z], ny = v[i].y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						for (int b = 0; b < Vsize; b++) {
							//나무좌표에 중복된다면
							if (nx == v[b].x && ny == v[b].y) {
								v[b].ages.push_back(1);
								found = true;
								sort(v[b].ages.begin(), v[b].ages.end());
							}
						}
						if (!found) {
							info tr;
							tr.x = nx; tr.y = ny; tr.ages.push_back(1);
							v.push_back(tr);
						}
					}
				}
			}
		}
		//겨울 처음받은 양분 다시 넣는다.
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] += ad[i][j];
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].ages.size(); j++) 
			if (v[i].ages[j] != 0) ans++;
	}
	cout << ans;
}