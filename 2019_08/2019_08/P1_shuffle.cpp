/*shuffle BFS ����*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T, tc, n, ans;
int card[13];

bool isSorted(int arr[13]) {
	int dif = abs(arr[0] - arr[1]);
	if (dif != 1) return false;

	for (int i = 2; i < n; i++) {
		if (dif != abs(arr[i] - arr[i - 1])) return false;
	}
	return true;
}

void bfs(int arr[13]) {
	queue<int *> q;
	int depth = 0;
	q.push(arr);

	while (!q.empty()) {

		// 5�� �̻� ���� ���
		if (depth > 5) return;

		int Qsize = q.size();

		while (Qsize--) {
			int *tempArr = q.front();
			int cpy[13] = { 0, };
			for (int i = 0; i < n; i++) cpy[i] = tempArr[i];
			q.pop();
			
			//���� ����
			int dirs[13] = { 0, };
			for (int i = 0; i < n; i++) if (i >= n / 2) dirs[i] = 1;
			
			//swap�� �ϸ鼭 �����Ͽ� push�Ѵ�.
			for (int i = 1; i < n; i++) {
				
				//0�� -> ����, 1�� <- ����, -> <- �� ���� swap
				for (int j = 0; j < n - 1; j++) {
					if (dirs[j] == 0 && dirs[j + 1] == 1) {
						swap(cpy[j], cpy[j + 1]);
						swap(dirs[j], dirs[j + 1]);
						j++;
					}
				}
				//���õ� ī��� push
				int *temp = (int *)malloc(sizeof(int)*n);
				for (int j = 0; j < n; j++) temp[j] = cpy[j];

				//���ĵǾ��ٸ� ����
				if (isSorted(temp)) {
					ans = depth;
					return;
				}
				q.push(temp);
			}
		}
		depth++;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> card[i];
		
		ans = 2147483647;

		if (isSorted(card)) ans = 0;
		else bfs(card);
		
		if (ans == 2147483647) ans = -1;
		cout << '#' << tc << ' ' << ans << '\n';
	}
}