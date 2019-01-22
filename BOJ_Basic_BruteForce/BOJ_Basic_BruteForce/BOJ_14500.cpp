//BOJ_14500
#include<iostream>
using namespace std;
int arr[501][501];
int test[19][3][2] = {
	{{0,1}, {0,2}, {0,3}},
{{1,0}, {2,0}, {3,0}},
{{1,0}, {1,1}, {1,2}},
{{0,1}, {1,0}, {2,0}},
{{0,1}, {0,2}, {1,2}},
{{1,0}, {2,0}, {2,-1}},
{{0,1}, {0,2}, {-1,2}},
{{1,0}, {2,0}, {2,1}},
{{0,1}, {0,2}, {1,0}},
{{0,1}, {1,1}, {2,1}},
{{0,1}, {1,0}, {1,1}},
{{0,1}, {-1,1}, {-1,2}},
{{1,0}, {1,1}, {2,1}},
{{0,1}, {1,1}, {1,2}},
{{1,0}, {1,-1}, {2,-1}},
{{0,1}, {0,2}, {-1,1}},
{{0,1}, {0,2}, {1,1}},
{{1,0}, {2,0}, {1,1}},
{{1,0}, {2,0}, {1,-1}},
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	int Max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int flag = 0, x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				int temp = arr[i][j];
				flag = 0;
				for (int z = 0; z < 3; z++) {
					x = i + test[k][z][0];
					y = j + test[k][z][1];
					if (x >= 0 && x < n && y >= 0 && y < m) {
						temp += arr[x][y];
					}
					else {
						flag = 1;
						break;
					}
				}
				if (flag == 0 && Max < temp)
					Max = temp;
			}
		}
	}
	cout << Max;
	return 0;
}