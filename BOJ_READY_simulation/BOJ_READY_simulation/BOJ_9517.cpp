#include<iostream>
using namespace std;
int k, n, t, reTime = 210;
char ans;
int main() {
	cin >> k >> n;
	while (n--) {
		cin >> t >> ans;
		reTime -= t;
		//�ð��� ������ ������ ��ź�� ����.
		if (reTime <= 0) break;
		//������ ��� ��ź�� �ű��.
		if (ans == 'T') {
			k %= 8; k++;
		}
	}
	cout << k;
}