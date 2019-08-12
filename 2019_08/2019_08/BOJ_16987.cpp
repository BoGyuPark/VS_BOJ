/*BOJ 16987 ������� ���ġ��*/
#include<iostream>
using namespace std;
int n, s[9], w[9], ts[9], ans = -1;
int sel[8];
void simulate() {
	/*if (sel[0] == 3 && sel[1] == 2 && sel[2] == 1 && sel[3] == 1 && sel[4] == 4)
		cout << 'a';*/


	int pickEgg = 0;
	int cnt = 0;
	int nextIdx = 0;
	int nextEgg = sel[nextIdx];

	for (int i = 0; i < n; i++) {
		//�� ����� ���Ѵ�.
		int flag = false;
		while (s[nextEgg] <= 0) {
			if (nextIdx + 1 >= n) {
				flag = true;
				break;
			}
			nextIdx++;
			nextEgg = sel[nextIdx];
		}
		if (flag) continue;
		
		pickEgg = i;
		if (i == nextEgg) continue;
		if (s[pickEgg] <= 0) continue;

		

		s[pickEgg] -= w[nextEgg];
		s[nextEgg] -= w[pickEgg];

		if (s[pickEgg] <= 0) cnt++;
		if (s[nextEgg] <= 0) cnt++;
		//nextEgg = sel[++nextIdx];
	}
	if (ans < cnt) ans = cnt;
	//if (cnt == 7) 
		//cout << 'a';
}

//��� �� ���� ���ϱ� (1~n������)
void go(int index) {

	if (index == n - 1) {
		/*for (int j = 0; j < index; j++) {
			cout << sel[j] << ' ';
		}
		cout << '\n';*/
		simulate();
		//������ ���� ����
		for (int j = 0; j < n; j++) s[j] = ts[j];
		return;
	}
	for (int i = 0; i < n; i++) {
		sel[index] = i;
		go(index + 1);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> w[i];
		ts[i] = s[i];
	}
	go(0);
	cout << ans;
	return 0;
}