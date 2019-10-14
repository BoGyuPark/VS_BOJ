/*BOJ 16637 괄호 추가하기*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, sel[20], c[20], ans = -2147483647;
int Num[20], cpyNum[20];
char op[20], cpyOp[20];
int cal(char oper, int idx, int value) {
	if (oper == '+') return value + Num[idx + 1];
	else if(oper=='-') return value - Num[idx + 1];
	else if(oper=='*') return value * Num[idx + 1];
}

void go(int depth) {
	if (depth == n / 2) {
		for (int j = 0; j < depth; j++) {
			if (sel[j] == 1) {
				Num[j] = cal(op[j], j, Num[j]);
				Num[j+1] = 0;
				op[j] = '+';
			}
		}
		for (int j = 0; j < depth; j++) {
			int temp = cal(op[j], j, Num[j]);
			Num[j+1] = temp;
		}
		int sum = Num[depth];
		ans = max(ans, sum);

		for (int j = 0; j < depth + 1; j++) {
			Num[j] = cpyNum[j];
			op[j] = cpyOp[j];
		}
		return;
	}

	for (int i = 0; i < 2; i++) {
		if (depth == 0 || sel[depth - 1] == 0) {
			sel[depth] = i;
			go(depth + 1);
		}
		else if (sel[depth - 1] == 1) {
			if (i == 0) {
				sel[depth] = i;
				go(depth + 1);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int numIdx = 0, opIdx = 0;
	for (int i = 0; i < n; i++) {
		char t; cin >> t;
		if (isdigit(t)) {
			Num[numIdx] = cpyNum[numIdx] = t - '0';
			numIdx++;
		}
		else {
			op[opIdx] = cpyOp[opIdx] = t;
			opIdx++;
		}
	}
	go(0);
	cout << ans;
}