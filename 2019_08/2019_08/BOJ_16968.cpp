/*BOJ 16968 ���� ��ȣ�� 1*/
#include<iostream>
#include<string>
using namespace std;
string s;
int ans = 1, check[4];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == 'c') {
			if (i + 1 < s.size()) {
				//cc
				if (s[i + 1] == 'c') {
					if (check[i - 1] == 1 || check[i - 1] == 4) {
						ans *= (25 * 25);
						check[i + 1] = 1;		//cc�ΰ�� 1
						i++;
					}
					else {
						ans *= (26 * 25);
						check[i + 1] = 1;		//cc�ΰ�� 1
						i++;
					}
				}
				// cd
				else {
					if (check[i - 1] == 4 || check[i - 1] == 1) {
						ans *= (25 * 10);
						check[i + 1] = 2;		//cd : 2
						i++;
					}
					else {
						ans *= (26 * 10);
						check[i + 1] = 2;		//cd : 2
						i++;
					}
				}
			}
			//���� c
			else {
				//dc�� ���
				if (check[i - 1] == 4 || check[i - 1] == 1) ans *= 25;
				else ans *= 26;
			}
		}
		// 'd' �϶�
		else {
			if (i + 1 < s.size()) {
				// dd�ΰ��
				if (s[i + 1] == 'd') {
					if (check[i - 1] == 3 || check[i - 1] == 2) {
						ans *= (9 * 9);
						check[i + 1] = 3;	//dd�� ��� 3
						i++;
					}
					else {
						ans *= (10 * 9);
						check[i + 1] = 3;	//dd�� ��� 3
						i++;
					}

				}
				//dc�� ���
				else {
					if (check[i - 1] == 2 || check[i - 1] == 3) {
						ans *= (9 * 26);
						check[i + 1] = 4;
						i++;
					}
					else {
						ans *= (10 * 26);
						check[i + 1] = 4;
						i++;
					}

				}
			}
			//���� d�� ���
			else {
				//cd�� ���
				if (check[i - 1] == 2 || check[i - 1] == 3) ans *= 9;
				else ans *= 10;
			}
		}
	}
	cout << ans;
}