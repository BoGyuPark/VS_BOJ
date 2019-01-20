//BOJ_4963_NumOfIsland
#include<iostream>
#include<cstring>
using namespace std;
int arr[52][52];
int d[52][52];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1, 0, 1,-1,1,-1,0,1 };
int w, h;

void dfs(int x, int y)
{
	d[x][y] = true;
	int nx, ny;
	for (int i = 0; i < 8; i++) {
		nx = x + dx[i]; ny = y + dy[i];
		if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
			if (d[nx][ny] == 0 && arr[nx][ny] == 1) {
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		cin >> h >> w;
		if (w == 0 && h == 0)
			break;
		int ans = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (arr[i][j] == 1 && d[i][j] == 0) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
		memset(arr, 0, sizeof(arr));
		memset(d, 0, sizeof(d));
	}
	return 0;
}