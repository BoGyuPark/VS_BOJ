#include<iostream>
using namespace std;
int n, m, isused[20], arr[20];
void go(int k) {
	//종료 조건 : 길이가 m일때 출력 후 return
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		
		if (isused[i] == false) {
			//arr[k] = i + 1; 주의하자.
			arr[k] = i + 1;
			isused[i] = true;

			go(k + 1);
			//종료 후에 false로 원상복귀
			isused[i] = false;
		}
	}

}
int main() {
	cin >> n >> m;
	go(0);
}