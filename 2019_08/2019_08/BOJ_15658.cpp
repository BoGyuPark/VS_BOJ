/*BOJ 15658 연산자 끼워넣기 (2)*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, num[12], op[4], sel[12];	//0 : +, 1: - , 2: *, 3: /
int mini = 2147483647, maxi = -2147483647;
void go(int index) {
	if (index == n - 1) {
		int sum = num[0];
		for (int j = 0; j < n - 1; j++) {
			if (sel[j] == 0) sum += num[j + 1];
			else if (sel[j] == 1) sum -= num[j + 1];
			else if (sel[j] == 2) sum *= num[j + 1];
			else sum /= num[j + 1];
		}
		mini = min(mini, sum);
		maxi = max(maxi, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			sel[index] = i;
			op[i]--;
			go(index + 1);
			op[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> op[i];
	go(0);
	cout << maxi << '\n' << mini;
}