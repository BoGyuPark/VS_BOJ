#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//          좌 우 상
int dx[] = { 0,0,-1 };
int dy[] = { -1,1,0 };
int n, m, a[16][16], cpy[16][16], D;
int c[15], sel[3], check[16][16], ans;
typedef struct info {
	int dist, y, x;
};
//           거리    열   행
//vector<pair<int, pair<int, int> > > removeList;
vector<info> removeList;
vector<pair<int, int>> rmList;
queue<pair<int, int>> q;
bool cmp(const info &a, const info &b) {
	if (a.dist < b.dist) {
		return true;
	}
	else if (a.dist == b.dist) {
		return a.y < b.y;
	}
	else return false;
}

void simulation(int num) {
	int row = n, col = sel[num];
	q.push({ row - 1,col });
	check[row - 1][col] = true;
	int temp = D;
	while (temp--) {
		int Qsize = q.size();
		while (Qsize--) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			//num위치에있는 궁수가 제거 가능한 적들의 거리와 좌표를 저장.
			if (cpy[x][y] == 1) {
				int dist = abs(x - row) + abs(y - col);
				removeList.push_back({ dist,y,x });
			}
			for (int i = 0; i < 3; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (check[nx][ny] == true) continue;
				q.push({ nx,ny });
				check[nx][ny] = true;
			}
		}
	}
	while (!q.empty()) q.pop();
	//제거할 적이 없을 경우
	/*if (pq.size() == 0) return;
	else {
		int nowx = pq.top().second.second;
		int nowy = pq.top().second.first;
		rmList.push_back({ nowx,nowy });
		while (!pq.empty()) pq.pop();
	}*/
	if (removeList.size() == 0) return;
	else {
		if (removeList.size() > 1) sort(removeList.begin(), removeList.end(),cmp);
		int nowx = removeList[0].x;
		int nowy = removeList[0].y;
		rmList.push_back({ nowx,nowy });
		removeList.clear();
	}
}
void dfs(int index, int start) {
	if (index == 3) {
		int cnt = 0;
		while (true) {
			//bfs를 통해 사거리 D 이내에 있는 적리스트 생성하여
			//완전히 제거할 제거리스트를 만든다.
			for (int j = 0; j < 3; j++) {
				simulation(j);
				memset(check, 0, sizeof(check));
			}
			//제거리스트를 통해 맵에서 제거한다.
			if (rmList.size() > 0) {
				for (int x = 0; x < rmList.size(); x++) {
					if (cpy[rmList[x].first][rmList[x].second] == 1) {
						cpy[rmList[x].first][rmList[x].second] = 0;
						cnt++;
					}
				}
				rmList.clear();
			}
			int enemyCnt = 0;
			//적들을 한칸씩 내린다.
			for (int x = n - 1; x >= 0; x--) for (int y = 0; y < m; y++) cpy[x][y] = cpy[x - 1][y];
			for (int x = 0; x < m; x++) cpy[0][x] = 0;

			//적들이 아예없는지 체크해서 탈출한다.
			int remainEn = 0;
			for (int x = 0; x < n; x++) {for (int y = 0; y < m; y++) {if (cpy[x][y] == 1) remainEn++;}}
			if (remainEn == 0) break;
		}
		if (ans < cnt) ans = cnt;

		//이전 맵으로 복귀시킨다.
		for (int x = 0; x < n; x++) for (int y = 0; y < m; y++) cpy[x][y] = a[x][y];
		return;
	}
	for (int i = start; i < m; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = i;
		dfs(index + 1, i);
		c[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> D;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			cpy[i][j] = a[i][j];
		}
	}
	ans = 0;
	dfs(0, 0);
	cout << ans;
}