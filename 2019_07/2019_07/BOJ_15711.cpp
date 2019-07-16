/*BOJ 15711 ȯ����¦�� _ �ؾǳ��̵�*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int MAX = 2'000'001;
int T;
ll A, B, sum;
bool check[MAX];
vector<int> prime;
bool isPrime(long long n) {
	for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; ++i) {
		if (n%prime[i] == 0) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//�����佺�׳׽� ü
	check[0] = check[1] = true;
	for (int i = 2; i < MAX; i++) {
		if (check[i] == true) continue;
		prime.push_back(i);
		for (int j = i + i; j < MAX; j += i) {
			check[j] = true;
		}
	}
	//cout << prime.size() << '\n';

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		sum = A + B;
		if (sum < 4) {
			cout << "NO" << "\n";
			continue;
		}
		//�������� ��Ģ
		if (sum % 2 == 0) {
			cout << "YES" << '\n';
		}
		else {
			// ���� 4����ū Ȧ���� ���
			bool flag = isPrime(sum - 2);
			if (flag == true) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}