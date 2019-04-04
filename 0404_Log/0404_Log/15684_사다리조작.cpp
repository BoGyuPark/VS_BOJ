#include<iostream>
#include<vector>
using namespace std;
int n, m, h, x, y, a[31][30], info[31][30], ans, c[271], sel[4], found;
vector<pair<int, int>> lL;
bool simulation() {
	// 1��° ��ٸ����� �����Ͽ� i��° ��ٸ��� �ȳ����� �ٷ� return
	for (int i = 1; i < n * 2; i += 2) {
		int row = 0, col = i;
		while (row != h) {
			if (a[row][col + 1] == 1) col += 2;
			else if (a[row][col - 1] == 1) col -= 2;
			row++;
		}
		if (col != i) return false;
	}
	return true;
}

void dfs(int index, int start, int dest){
	if (found) return;
	if (index == dest) {
		found = false;
		for (int j = 0; j < dest; j++) a[lL[sel[j]].first][lL[sel[j]].second] = 1;
		bool t = simulation();
		if (t) { found = true;	return; }
		/*for (int j = 0; j < dest; j++) cout << sel[j] << ' ';
		cout << '\n';*/
		for (int j = 0; j < dest; j++) 	a[lL[sel[j]].first][lL[sel[j]].second] = 0;
		return;
	}
	for (int i = start; i < lL.size(); i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = i;
		dfs(index + 1, i, dest);
		c[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// n: ��, h: ��
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x - 1][y * 2] = 1;
		//������ ���μ��� ��ġ���� �ʱ� ����
		info[x - 1][y * 2 + 2] = info[x - 1][y * 2 - 2] = info[x - 1][y * 2] = 1;
	}
	//���μ��� ���� �� �ִ� ��ġ�� ����
	for (int i = 0; i < h; i++) 
		for (int j = 2; j < n * 2; j += 2) 
			if (info[i][j] != 1) lL.push_back({ i,j });
		
	// �߰� ���Ͽ��� ���
	ans = -1;
	int tt = simulation();
	if (!tt) {
		for (int i = 1; i <= 3; i++) {
			dfs(0, 0, i);
			if (found) { ans = i; break; }
			//memset(c, 0, sizeof(c));
			//cout << '\n';
		}
	}
	else ans = 0;
	cout << ans;
	/*int found = false;
	if (!tt) {
		for (int i = 1; i <= 3; i++) {
			int temp[270] = { 0, };
			for (int j = 0; j < i; j++) temp[j] = 1;
			do {
				for (int z = 0; z < lL.size(); z++) {
					if (temp[z] == 1) a[lL[z].first][lL[z].second] = 1;
				}

				bool t = simulation();
				if (t) {found = true;	break;	}

				for (int z = 0; z < lL.size(); z++) {
					if (temp[z] == 1) a[lL[z].first][lL[z].second] = 0;
				}
			} while (prev_permutation(temp, temp + lL.size()));
			if (found) {	ans = i;	break;	}
		}
	}*/
}