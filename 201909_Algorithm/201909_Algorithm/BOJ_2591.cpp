/*BOJ 2591 ����ī��*/
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string n;
int arr[41], m, cnt;
void go(int index,int twoCnt) {
	if (index == m) {
		cnt++;
		return;
	}

	if (twoCnt <= m / 2) {
		//���ڸ��� �����ϸ� ���
		if (index + 1 < m && n[index] != '0' && n[index + 1] != '0') {
			string t = "";
			t += (n[index]); t += n[index + 1];
			int num = stoi(t);
			if (0 <= num && num <= 34) {
				go(index + 2, twoCnt + 1);
			}
		}

		//���ڸ��� �� ���
		if(n[index]!='0') go(index + 1, twoCnt);
	}
}

int main() {
	cin >> n;
	m = n.size();
	int maxTwoSize = m / 2;

	go(0,0);
	cout << cnt;
}