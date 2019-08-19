/*BOJ 16968 차량 번호판 1*/
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
						check[i + 1] = 1;		//cc인경우 1
						i++;
					}
					else {
						ans *= (26 * 25);
						check[i + 1] = 1;		//cc인경우 1
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
			//끝이 c
			else {
				//dc인 경우
				if (check[i - 1] == 4 || check[i - 1] == 1) ans *= 25;
				else ans *= 26;
			}
		}
		// 'd' 일때
		else {
			if (i + 1 < s.size()) {
				// dd인경우
				if (s[i + 1] == 'd') {
					if (check[i - 1] == 3 || check[i - 1] == 2) {
						ans *= (9 * 9);
						check[i + 1] = 3;	//dd인 경우 3
						i++;
					}
					else {
						ans *= (10 * 9);
						check[i + 1] = 3;	//dd인 경우 3
						i++;
					}

				}
				//dc인 경우
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
			//끝이 d인 경우
			else {
				//cd인 경우
				if (check[i - 1] == 2 || check[i - 1] == 3) ans *= 9;
				else ans *= 10;
			}
		}
	}
	cout << ans;
}