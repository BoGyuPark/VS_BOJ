#include<iostream>
#include<cstring>
using namespace std;
//       ��°, ȸ��, x,y
int n, val[10][4][4][4];
char color[10][4][4][4];
int valMap[5][5];
char colMap[5][5];
int dx[] = { 0,0,1,1 };
int dy[] = { 0,1,0,1 };
int check[10], sel[3], ans;
int st[3];
void simulate(int start[3]) {
	//�� ���������� ȸ���� ������ ��� �õ��Ѵ�.
	// 0~3
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			for (int c = 0; c < 4; c++) {
				int dirs[3];
				dirs[0] = a; dirs[1] = b; dirs[2] = c;
				//��ġ��Ų��.
				for (int z = 0; z < 3; z++) {
					for (int x = dx[start[z]], nx = 0; x < dx[start[z]] + 4; x++, nx++) {
						for (int y = dy[start[z]], ny = 0; y < dy[start[z]] + 4; y++, ny++) {
							//��� ȿ�ɺ���
							int nextSum = valMap[x][y] + val[sel[z]][dirs[z]][nx][ny];
							if (nextSum > 9) nextSum = 9;
							else if (nextSum < 0) nextSum = 0;
							valMap[x][y] = nextSum;
							
							//��� �� ����
							if (color[sel[z]][dirs[z]][nx][ny] != 'W') 
								colMap[x][y] = color[sel[z]][dirs[z]][nx][ny];
						}
					}
					//cout << 'd';
				}
				int sum = 0;
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						if (colMap[i][j] == 'R') sum += valMap[i][j] * 7;
						else if(colMap[i][j]=='B') sum += valMap[i][j] * 5;
						else if (colMap[i][j] == 'G') sum += valMap[i][j] * 3;
						else if (colMap[i][j] == 'Y') sum += valMap[i][j] * 2;
					}
				}
				if (ans < sum) ans = sum;
				//�� ����
				for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) colMap[i][j] = 'W';
				memset(valMap, 0, sizeof(valMap));
			}
		}
	}
}

void dfs(int index) {
	//10�� �߿� 3���� ��
	if (index == 3) {
		//�� ����� ������ ��ġ�� 4���߿� 1ĭ�� �����Ѵ�.
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				for (int c = 0; c < 4; c++) {
					//�� ��°�� �������� �Ѱ��ش�.
					st[0] = a;
					st[1] = b;
					st[2] = c;
					simulate(st);
				}
			}
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i] == true) continue;
		check[i] = true;
		sel[index] = i;
		dfs(index + 1);
		check[i] = false;
	}
	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) 
			for (int z = 0; z < 4; z++) cin >> val[i][0][j][z];
		
		for (int j = 0; j < 4; j++) 
			for (int z = 0; z < 4; z++) cin >> color[i][0][j][z];
	}
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) colMap[i][j] = 'W';
	
	//�̸� ȸ�����Ѽ� ��������
	for (int i = 0; i < n; i++) {
		for (int dir = 1; dir < 4; dir++) {
			for (int j = 0; j < 4; j++) {
				for (int z = 0; z < 4; z++) {
					val[i][dir][j][z] = val[i][dir - 1][z][3 - j];
					color[i][dir][j][z] = color[i][dir - 1][z][3 - j];
				}
			}	
		}
	}
	ans = -2147483647;
	dfs(0);
	cout << ans;
}