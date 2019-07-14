/*BOJ 17103 골드바흐 파티션*/
#include<iostream>
using namespace std;
int T, value;
int arr[1'000'002];
void make_prime() {
	int n = 1'000'000;
	for (int i = 0; i <= n; i++) arr[i] = i;
	arr[1] = 0;

	for (int i = 2; i*i <= n; i++) {
		//체크한것은 패스
		if (arr[i] == 0) continue;
		//i는 피벗으로 i간격만큼 이동하면서 체크
		for (int j = i + i; j <= n; j += i) {
			arr[j] = 0;
		}
	}
}

int find_partition(int find_num) {
	int cnt = 0;
	for (int i = 2; i < find_num / 2 + 1; i++) {
		if (arr[i] != 0 && arr[find_num - arr[i]] != 0) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	make_prime();
	for (int i = 0; i < T; i++) {
		cin >> value;
		cout << find_partition(value) << '\n';
	}
}