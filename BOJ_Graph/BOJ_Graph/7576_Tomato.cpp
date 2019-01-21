//BOJ_7576_Tomato
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int box[1001][1001];
int check[1001][1001];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int> > v;
void bfs()
{
	queue<pair<int, int> > q;
	for (int i = 0; i < v.size(); i++) {
		q.push(make_pair(v[i].first, v[i].second));
		check[v[i].first][v[i].second] = true;
	}
	int nx, ny, befx, befy;
	while (!q.empty()) {
		befx = q.front().first; befy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = befx + dx[i]; ny = befy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (check[nx][ny] == 0 && box[nx][ny] == 0) {
					check[nx][ny] = check[befx][befy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	int ripecnt = 0, emptycnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				ripecnt++;
				v.push_back(make_pair(i, j));
			}
			else if (box[i][j] == -1)
			{
				emptycnt++;
				check[i][j] = -1;
			}
		}
	}
	if (ripecnt == 0)
		cout << -1;
	else if (m*n - ripecnt - emptycnt == 0)
		cout << 0;
	else {
		bfs();
		int flag = 0, max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[i][j] == 0) {
					flag = 1;
					break;
				}
				else if (check[i][j] != 1) {
					if (max < check[i][j])
						max = check[i][j];
				}
			}
		}
		cout << (flag == 1 ? -1 : max - 1);
	}
	return 0;
}