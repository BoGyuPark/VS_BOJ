#include<iostream>
using namespace std;
int n, s, a[21], sum = 0, cnt = 0, sel[21], c[21];
void dfs(int index, int sum) {
	if (index == n) {
		if (sum == s) { 	//���ϴ� ���� ���°��
			cnt++;
			return;
		}
		else return;					//�ƴѰ�� ������ ����
	}
	dfs(index + 1, sum + a[index]); 	//�κ����� �����Ѱ��
	dfs(index + 1, sum); 				//�κ����� �������� ���� ���

}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	dfs(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
}