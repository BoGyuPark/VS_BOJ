#include<iostream>
#include<vector>
using namespace std;
int n, s[20][20], i, j;
vector<int> first, second;
int go(int index) {
	//정답인 경우
	if (index == n) {
		if (first.size() != n / 2) return -1;
		if (second.size() != n / 2) return -1;
		int starsum = 0, linksum = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				starsum += s[first[i]][first[j]];
				linksum += s[second[i]][second[j]];
			}
		}
		int dif = starsum - linksum;
		if (dif < 0)	dif = -dif;
		return dif;
	}
	//다음을 호출할때
	int ans = -1;
	first.push_back(index);
	int t1 = go(index + 1);
	if (ans == -1 || t1 != -1 && ans > t1)	ans = t1;
	first.pop_back();

	second.push_back(index);
	int t2 = go(index + 1);
	if (ans == -1 || t2 != -1 && ans > t2)	ans = t2;
	second.pop_back();
	return ans;
}

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	cout<<go(0);
}