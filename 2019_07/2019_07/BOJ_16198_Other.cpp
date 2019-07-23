/*BOJ 16198 에너지모으기 남극 탈출*/
#include<iostream>
using namespace std;
int n, w[11], ans, sel[11], cpy[11];
void go(int index) {
	if (index == n - 2) {
		int sum = 0;
		for (int j = 0; j < index; j++) {
			sum += w[sel[j] - 1] * w[sel[j] + 1];
			//한칸 옮기기
			for (int z = sel[j]; z < n - 1; z++) w[z] = w[z + 1];
		}
		for (int i = 0; i < n; i++) w[i] = cpy[i];
		if (ans < sum) ans = sum;
		return;
	}
	for (int i = 1; i < n - 1 - index; i++) {
		sel[index] = i;
		go(index + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		cpy[i] = w[i];
	}
	go(0);
	cout << ans;
}
