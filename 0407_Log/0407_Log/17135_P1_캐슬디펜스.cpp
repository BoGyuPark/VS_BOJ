#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//          �� �� ��
int dx[] = { 0,0,-1 };
int dy[] = { -1,1,0 };
int n, m, a[16][16], cpy[16][16], D;
int c[15], sel[3], check[16][16], ans;
typedef struct info {
	int dist, y, x;
};
//           �Ÿ�    ��   ��
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
			//num��ġ���ִ� �ü��� ���� ������ ������ �Ÿ��� ��ǥ�� ����.
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
	//������ ���� ���� ���
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
			//bfs�� ���� ��Ÿ� D �̳��� �ִ� ������Ʈ �����Ͽ�
			//������ ������ ���Ÿ���Ʈ�� �����.
			for (int j = 0; j < 3; j++) {
				simulation(j);
				memset(check, 0, sizeof(check));
			}
			//���Ÿ���Ʈ�� ���� �ʿ��� �����Ѵ�.
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
			//������ ��ĭ�� ������.
			for (int x = n - 1; x >= 0; x--) for (int y = 0; y < m; y++) cpy[x][y] = cpy[x - 1][y];
			for (int x = 0; x < m; x++) cpy[0][x] = 0;

			//������ �ƿ������� üũ�ؼ� Ż���Ѵ�.
			int remainEn = 0;
			for (int x = 0; x < n; x++) {for (int y = 0; y < m; y++) {if (cpy[x][y] == 1) remainEn++;}}
			if (remainEn == 0) break;
		}
		if (ans < cnt) ans = cnt;

		//���� ������ ���ͽ�Ų��.
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