#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int tc = 1; tc <= 10; tc++) {
		int n; cin >> n; cin.ignore();
		int numflag = false;
		int ans = 1;
		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			char t[100] = { 0, };
			for (int z = 0; z < s.size(); z++) t[z] = s[z];
			char *ptr = strtok(t, " ");
			int num = 0, cnt = 0;
			//������ȣ ����
			ptr = strtok(NULL, " ");
			while (ptr != NULL) {
				string t = ptr;
				if (num == 0) {
					//ù��°�� �����̰� �ڿ� ���ڰ� �Ѱ��� ������ �ƿ�
					if (t == "-" || t == "+" || t == "*" || t == "/") {
						
					}
					else {
						numflag = true;
					}
					num++;
				}
				//cout << t;
				ptr = strtok(NULL, " ");
				cnt++;
			}
			if (numflag && (num < cnt)) {
				ans = 0;
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}