#include<iostream>
using namespace std;
int n, m, isused[20], arr[20];
void go(int k) {
	//���� ���� : ���̰� m�϶� ��� �� return
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		
		if (isused[i] == false) {
			//arr[k] = i + 1; ��������.
			arr[k] = i + 1;
			isused[i] = true;

			go(k + 1);
			//���� �Ŀ� false�� ���󺹱�
			isused[i] = false;
		}
	}

}
int main() {
	cin >> n >> m;
	go(0);
}