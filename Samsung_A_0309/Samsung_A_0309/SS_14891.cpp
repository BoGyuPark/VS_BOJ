#include<iostream>
#include<string>
#include<vector>
using namespace std;
int k, info[5][8], wheelnum, dir;
void ro(int num) {
	int t = info[num][7];
	for (int i = 7; i > 0; i--) info[num][i] = info[num][i - 1];
	info[num][0] = t;
}
void rero(int num) {
	int t = info[num][0];
	for (int i = 0; i < 7; i++) info[num][i] = info[num][i + 1];
	info[num][7] = t;
}
int main() {
	for (int i = 1; i <= 4; i++) {
		string s; cin >> s;
		for (int j = 0; j < 8; j++) info[i][j] = s[j] - '0';
	}
	cin >> k;
	while (k--) {
		cin >> wheelnum >> dir;
		//1����2��, 2���� 3��, 3���� 4���� ���ư����ִ���
		int rotatePo[4] = { 0, };
		for (int i = 1; i < 4; i++) {
			if (info[i][2] != info[i + 1][6]) rotatePo[i] = 1;
		}
		int dirs[5] = { 0,1,1,1,1 };

		//�� ��Ϲ����� ȸ�������� �����ش�
		if (wheelnum % 2 == 1) {
			if (dir == 1) dirs[2] = dirs[4] = -1;
			else dirs[1] = dirs[3] = -1;
		}
		else{
			if (dir == 1) dirs[1] = dirs[3] = -1;
			else dirs[2] = dirs[4] = -1;
		}

		//������ wheelnum�� ��Ϲ����� dir�������� ���� ȸ���Ѵ�.
		if (dir == 1) ro(wheelnum);
		else rero(wheelnum);

		//wheelnum�������� ���� ���������� ȸ��
		for (int i = 1; i <= 3; i++) {
			if (wheelnum - i < 1) break;
			if (rotatePo[wheelnum - i] == 1) {
				if (dirs[wheelnum - i] == 1) ro(wheelnum - i);
				else rero(wheelnum - i);
			}
			else break;
		}
	
		//wheelnum�������� ������ ���������� ȸ��
		for (int i = 0; i < 3; i++) {
			if (wheelnum + i > 3) break;
			if (rotatePo[wheelnum + i] == 1) {
				if (dirs[wheelnum + i + 1 ] == 1) ro(wheelnum + i + 1);
				else rero(wheelnum + i + 1);
			}
			else break;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		if (info[i][0] == 1)	ans += (1 << (i - 1));
	}
	cout << ans;
}