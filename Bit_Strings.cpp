#include<bits/stdc++.h>
using namespace std;


class Solution {
	long long MOD = 1e9 + 7;
	//function calculate power using (modular exponentiation)
	long long binpow(int n, int x) {
		if (x == 0) {
			return 1;
		}
		long long res = binpow(n, x / 2);
		res *= res % MOD;
		if (x & 1) {
			res *= n % MOD;
		}
		return res % MOD;
	}
public:
	//each bit either can be 0 or 1 so for every place 2 possibilities
	int countBitStrings(int n) {
		return binpow(2, n);
	}

};

int main() {
	Solution test;
	int n;
	cin >> n;
	int totalStrings = test.countBitStrings(n);
	cout << totalStrings << "\n";
}