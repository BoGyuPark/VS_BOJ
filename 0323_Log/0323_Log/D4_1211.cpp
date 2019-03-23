#include<iostream>
#include<cstring>
using namespace std;
//       ��, ��, ��
int dx[] = { 0,0,1 };
int dy[] = { -1,1,0 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int T = 1; T <= 10; T++) {
		int g; cin >> g;
		int map[101][101] = { 0, };
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++) cin >> map[i][j];
		
		int miniDis = 2141483647, ans = -1;
		for (int i = 0; i < 100; i++) {
			//��ٸ� ����
			if (map[0][i] == 1) {
				int c[101][101] = { 0, };
				int dist = 1;
				int row = 0, col = i;
				int dir = 2;
				while (true) {
					bool change = false;
					int LeftCol = col - 1, RightCol = col + 1;
					if (LeftCol >= 0) {
						if (c[row][LeftCol] == false && map[row][LeftCol] == 1) {
							dir = 0;
							change = true;
						}
					}
					if (RightCol < 100) {
						if (c[row][RightCol] == false && map[row][RightCol] == 1) {
							dir = 1;
							change = true;
						}
					}
					if (change == false) dir = 2;
					row += dx[dir], col += dy[dir];
					//cout << row << ", " << col << '\n';
					c[row][col] = true;
					dist++;
					if (row == 99) {
						//�������� ��� ���� ū x��ǥ�� ��ȯ
						if (miniDis >= dist) {
							ans = i;
							miniDis = dist;
						}
						//cout << i << ": , ���� :" << col << " �Ÿ�: " << dist << '\n';
						break;
					}
				}
			}
		}
		cout << '#' << T << ' ' << ans << '\n';
	}
}