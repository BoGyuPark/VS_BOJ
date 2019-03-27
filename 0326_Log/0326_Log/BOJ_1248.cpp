#include<iostream>
#include<string>
using namespace std;
int n, sel[11];
char a[10][10];
string s;
int found = false;
bool poss(int idx) {
	int sum = 0;
	for (int y = idx; y >= 0; y--) {
		sum += sel[y];
		char t = a[y][idx];
		if (t == '-') {
			if (sum >= 0) return false;
		}
		else if (t == '+') {
			if (sum <= 0) return false;
		}
		else if (t == '0') {
			if (sum != 0) return false;
		}
	}
	return true;
}

void dfs(int index) {
	if (found) return;
	if (index == n) {
		for (int j = 0; j < n; j++) cout << sel[j] << ' ';
		found = true;
		return;
	}
	for (int i = 0; i <= 20; i++) {
		sel[index] = i - 10;
		if (poss(index)) dfs(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; cin >> s;
	int z = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			a[i][j] = s[z];		z++;
		}
	}
	dfs(0);
}