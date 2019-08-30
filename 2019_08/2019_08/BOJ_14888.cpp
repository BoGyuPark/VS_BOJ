/* BOJ 14888 ¿¬»êÀÚ ³¢¿ö³Ö±â*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, num[12], op[4], sel[12];	//0 : µ¡¼À, 1: »¬¼À, 2:°ö¼À, 3: ³ª´°¼À
int maxi = -2147483647, mini = 2147483647;
int cal(int t1,int t2, int oper) {
	if (oper == 0) return t1 + t2;
	else if (oper == 1) return t1 - t2;
	else if (oper == 2) return t1 * t2;
	else return t1 / t2;
}
void solve() {
	int result = num[0];
	for (int i = 0; i < n - 1; i++) {
		result = cal(result, num[i + 1], sel[i]);
	}

	maxi = max(maxi, result);
	mini = min(mini, result);
}

void go(int index) {
	if (index == n - 1) {
		solve();
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			sel[index] = i;
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