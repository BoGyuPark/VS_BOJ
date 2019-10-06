/* BOJ 2503 숫자 야구*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct info {
	string num;
	int strike, ball;
};
int n, s, b, sel[4], c[10], ans;
string arr;
vector<info> v;
bool isPossbile() {
	bool checkNum[10] = { 0, };

	for (int i = 0; i < 3; i++) checkNum[sel[i]] = true;
	
	for (int i = 0; i < v.size(); i++) {
		int sCnt = 0, bCnt = 0;
		string pivot = v[i].num;
		for (int j = 0; j < 3; j++) {
			if ((pivot[j] - '0') == sel[j]) sCnt++;
			else {
				if (checkNum[pivot[j] - '0']) bCnt++;
			}
		}
		if (sCnt != v[i].strike || bCnt != v[i].ball) return false;
	}
	return true;
}

void go(int index) {
	if (index == 3) {
		if (isPossbile()) ans++;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1);
		c[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr >> s >> b;
		v.push_back({ arr,s,b });
	}
	go(0);
	cout << ans;
}