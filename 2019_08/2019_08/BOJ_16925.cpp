/*BOJ 16925 ���ڿ� ����*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n, check[202];
vector<string> v, li,ansli;
string s, t;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2 * n - 2; i++) {
		cin >> t;
		v.push_back(t);
	}

	if (v.size() == 2) {
		s = v[0] + v[1];
		cout << s << '\n' << "PS";
	}
	else {
		//���λ� n-1���ڿ� �ΰ��� ������ ã�ƺ���
		for (int i = 0; i < v.size(); i++) {
			if (v[i].size() == n - 1) li.push_back(v[i]);
		}

		//P�� 1~end, S�� 0~end-1 ��
		ansli.push_back(li[0] + li[1][li[1].size() - 1]);
		ansli.push_back(li[1] + li[0][li[0].size() - 1]);

		//find origin
		int cnt = 0;
		for (int i = 0; i < ansli.size(); i++) {
			cnt = 0;
			for (int j = 0; j < v.size(); j++) {
				if (ansli[i].substr(0, v[j].size()) == v[j] || 
					ansli[i].substr(n - v[j].size()) == v[j]) {
					cnt++;
				}
			}
			if (cnt == 2 * n - 2) {
				s = ansli[i];
				break;
			}
		}

		cout << s << '\n';
		//find prefic, suffix
		for (int i = 0; i < v.size(); i++) {
			string temp = v[i];
			//prefix
			if (s.substr(0, temp.size()) == temp) {
				if (!check[temp.size()]) {
					cout << "P";
					check[temp.size()] = true;
				}
				else cout << "S";
			}
			else cout << "S";
		}
	}
}