#include<iostream>
#include<cstring>
using namespace std;
int n, t, x, row[30][30], col[30][30], rowcheck[30][30], colcheck[30][30];
//왼쪽에 하나크고 기준의 오른쪽에 x개가 기준값과 같지않으면 return false.
bool FindLeft(int i, int j, int pivot, int map[30][30], int check[30][30]) {
	int ld = 1;
	if (j - 1 < 0) return true;
	//기준왼쪽이 하나큰경우
	if (map[i][j - 1] == pivot + 1) {
		for (int l = 1; l < x; l++) {
			//범위 안에 들어오고 기준점보다 낮은 경우
			if (map[i][j + l] == pivot) ld++;
			else return false;
		}
		if (ld == x) {
			//활주로가 가능하다면 check한다.
			for (int e = 0; e < x; e++) {
				if(check[i][j + e]==false)
					check[i][j + e] = true;
				else return false;
			}
		}
	}
	else if (map[i][j - 1] > pivot + 1)	return false;

	if (ld!=1 && ld != x) return false;
	else return true;
}
bool FindRight(int i, int j, int pivot, int map[30][30], int check[30][30]) {
	int rd = 1;
	if (j + 1 >=n) return true;
	//기준오른쪽이 하나큰경우
	if (map[i][j + 1] == pivot + 1) {
		for (int r = 1; r < x; r++) {
			//범위 안에 들어오고 기준점보다 낮은 경우
			if (map[i][j - r] == pivot) rd++;
			else return false;
		}
		if (rd == x) {
			//활주로가 가능하다면 check한다.
			for (int e = 0; e < x; e++) {
				if (check[i][j - e] == false)
					check[i][j - e] = true;
				else return false;
			}
		}
	}
	else if (map[i][j + 1] > pivot + 1)	return false;
	if (rd!=1 && rd != x) return false;
	else return true;
}

int main() {
	cin >> t;
	for (int w = 1; w <= t; w++) {
		cin >> n >> x;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) {
				cin >> row[i][j];
				col[j][i] = row[i][j];
			}
		int total = 0;
		int rowvalue, colvalue;
		for (int i = 0; i < n; i++) {
			bool flag = true, colflag = true;
			for (int j = 0; j < n; j++) {
				rowvalue = row[i][j];
				flag *= FindLeft(i, j, rowvalue, row,rowcheck);
				flag *= FindRight(i, j, rowvalue, row,rowcheck);
				colvalue = col[i][j];
				colflag *= FindLeft(i, j, colvalue, col, colcheck);
				colflag *= FindRight(i, j, colvalue, col, colcheck);
			}
			if (flag) total++;
			if (colflag) total++;
		}
		cout << '#' << w << ' ' << total << '\n';
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(rowcheck, 0, sizeof(rowcheck));
		memset(colcheck, 0, sizeof(colcheck));
	}
}