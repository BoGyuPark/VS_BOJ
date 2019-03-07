#include<iostream>
using namespace std;
int n, a[21][21], sel[5], cpy[21][21], ans = - 1;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void solve(int dir) {
	//0�̸� ���ʺ�, 1�̸� �����ʺ� ,2�̸� ��, 3�̸� �Ʒ�
	if (dir == 0) {
		//���� �������� ����δ�.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cpy[i][j] != 0) {
					int y = j;
					int ny = y+ dy[dir];
					while (ny >= 0 && cpy[i][ny] == 0) {
						cpy[i][ny] = cpy[i][y];
						cpy[i][y] = 0;
						y = ny;
						ny += dy[dir];
					}
				}
			}
		}
		//�ΰ��� ¦���� ��ģ��
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (cpy[i][j] == cpy[i][j + 1]) {
					cpy[i][j] *= 2;
					cpy[i][j + 1] = 0;
					j++;
				}
			}
		}
		//�ٽ� ����δ�.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cpy[i][j] != 0) {
					int y = j;
					int ny = y + dy[dir];
					while (ny >= 0 && cpy[i][ny] == 0) {
						cpy[i][ny] = cpy[i][y];
						cpy[i][y] = 0;
						y = ny;
						ny += dy[dir];
					}
				}
			}
		}
	}
	else if (dir == 1) {
		//���� ���������� ����δ�.
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (cpy[i][j] != 0) {
					int y = j;
					int ny = y + dy[dir];
					while (ny < n && cpy[i][ny] == 0) {
						cpy[i][ny] = cpy[i][y];
						cpy[i][y] = 0;
						y = ny;
						ny += dy[dir];
					}
				}
			}
		}
		//�ΰ��� ¦���� ��ģ��
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j > 0; j--) {
				if (cpy[i][j] == cpy[i][j - 1]) {
					cpy[i][j] *= 2;
					cpy[i][j - 1] = 0;
					j--;
				}
			}
		}
		//�ٽ� ���������� ����δ�.
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (cpy[i][j] != 0) {
					int y = j;
					int ny = y + dy[dir];
					while (ny < n && cpy[i][ny] == 0) {
						cpy[i][ny] = cpy[i][y];
						cpy[i][y] = 0;
						y = ny;
						ny += dy[dir];
					}
				}
			}
		}
	}
	else if (dir == 2) {
		//���� ���� ����δ�.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cpy[j][i] != 0) {
					int x = j;
					int nx = x + dx[dir];
					while (nx >= 0 && cpy[nx][i] == 0) {
						cpy[nx][i] = cpy[x][i];
						cpy[x][i] = 0;
						x = nx;
						nx += dx[dir];
					}
				}
			}
		}
		//�ΰ��� ¦���� ��ģ��
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (cpy[j][i] == cpy[j+1][i]) {
					cpy[j][i] *= 2;
					cpy[j + 1][i] = 0;
					j++;
				}
			}
		}
		//�ٽ� ���� ����δ�.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cpy[j][i] != 0) {
					int x = j;
					int nx = x + dx[dir];
					while (nx >= 0 && cpy[nx][i] == 0) {
						cpy[nx][i] = cpy[x][i];
						cpy[x][i] = 0;
						x = nx;
						nx += dx[dir];
					}
				}
			}
		}

	}
	else {
		//���� �Ʒ��� ����δ�.
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (cpy[j][i] != 0) {
					int x = j;
					int nx = x + dx[dir];
					while (nx <n && cpy[nx][i] == 0) {
						cpy[nx][i] = cpy[x][i];
						cpy[x][i] = 0;
						x = nx;
						nx += dx[dir];
					}
				}
			}
		}
		//�ΰ��� ¦���� ��ģ��
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j > 0; j--) {
				if (cpy[j][i] == cpy[j - 1][i]) {
					cpy[j][i] *= 2;
					cpy[j - 1][i] = 0;
					j--;
				}
			}
		}
		//�ٽ� �Ʒ��� ����δ�.
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (cpy[j][i] != 0) {
					int x = j;
					int nx = x + dx[dir];
					while (nx < n && cpy[nx][i] == 0) {
						cpy[nx][i] = cpy[x][i];
						cpy[x][i] = 0;
						x = nx;
						nx += dx[dir];
					}
				}
			}
		}
	}
}


void dfs(int index) {
	if (index == 5) {
		for (int j = 0; j < 5; j++) solve(sel[j]);

		int maxi = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maxi < cpy[i][j]) maxi = cpy[i][j];
			}
		}
		if (ans < maxi) ans = maxi;
		
		//����
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) cpy[j][z] = a[j][z];
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		sel[index] = i;
		dfs(index + 1);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			cpy[i][j] = a[i][j];
		}
	dfs(0);
	cout << ans;
}