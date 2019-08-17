/*BOJ 16922 로마 숫자 만들기*/
#include<iostream>
#include<set>
using namespace std;
int n, arr[] = { 1,5,10,50 };
int sel[21];
set<int> s;
int cnt;
void go(int index,int sum) {
	if (index == 4) {
		if (sum == n) {
			int temp = 0;
			for (int j = 0; j < 4; j++) temp += arr[j] * sel[j];
			if (temp != 0) s.insert(temp);
		}
		return;
	}

	for (int i = 0; i <= n; i++) {
		sel[index] = i;
		go(index + 1, sum + i);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	go(0,0);
	cout << s.size();
}