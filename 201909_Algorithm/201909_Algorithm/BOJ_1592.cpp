/*BOJ 1592 �����̿� ģ����*/
#include<iostream>
using namespace std;
int n, m, l, map[1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> l;
	int s = 0; map[s]++;
	int cnt = 1;
	while (true) {
		//¦��
		if (map[s] % 2 == 0) s = (s - l + n) % n;
		//Ȧ��
		else s = (s + l) % n;	
		map[s]++;
		if (map[s] == m) break;
		cnt++;
	}
	cout << cnt;
}