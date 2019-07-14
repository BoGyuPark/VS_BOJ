/*BOJ 15668 방 번호*/
#include<iostream>
#include<string>
using namespace std;
int n, A, B;
string s;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= 98765; i++) {
		int tempB = n - i;
		if (tempB <= 0) continue;
		int tempA = i;
		int overlap[11] = { 0, };
		bool A_flag = false, B_flag = false;
		while (tempA != 0) {
			if (overlap[tempA % 10] == false) {
				overlap[tempA % 10] = true;
			}
			else {
				A_flag = true;
				break;
			}
			tempA /= 10;
		}
		//A는 중복없음
		if (A_flag == false) {
			while (tempB != 0) {
				if (overlap[tempB % 10] == false) {
					overlap[tempB % 10] = true;
				}
				else {
					B_flag = true;
					break;
				}
				tempB /= 10;
			}
			if (B_flag == false) {
				A = i;
				B = n - i;
				break;
			}
		}
	}
	if (A == 0 && B == 0) cout << -1;
	else cout << A << " + " << B;
}