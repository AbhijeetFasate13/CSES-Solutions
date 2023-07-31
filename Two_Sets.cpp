#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool isSumPossible(long long n) {
		long long sum = n * 1ll * (n + 1);
		sum /= 2;
		return !(sum & 1);
	}
public:
	void distributeSum(long long n) {
		if (!isSumPossible(n)) {
			cout << "NO\n";
			return ;
		}
		vector<int>a, b;
		cout << "YES\n";
		long long halfSum = (n * (n + 1)) / 4;
		for (int i = n; i > 0; i--) {
			if (i <= halfSum) {
				a.push_back(i);
				halfSum -= i;
			}
			else {
				b.push_back(i);
			}
		}
		cout << a.size() << "\n";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " ";
		}
		cout << "\n" << b.size() << "\n";
		for (int i = 0; i < b.size(); i++) {
			cout << b[i] << " ";
		}
		cout << "\n";
		return;
	}


};

int main() {
	Solution test;
	long long n;
	cin >> n;
	test.distributeSum(n);
}