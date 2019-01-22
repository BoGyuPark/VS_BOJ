//BOJ_1476
#include<iostream>
using namespace std;
int main()
{
	int E, S, M; cin >> E >> S >> M;
	int e, s, m;
	e = s = m = 1;
	for (int i = 1; ; i++) {
		if (e == E && s == S && m == M) {
			cout << i;
			break;
		}
		e++; s++; m++;
		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m = 1;
	}
	return 0;
}