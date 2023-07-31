#include<bits/stdc++.h>
using namespace std;


//hint : use long long 
class Solution {
public:
	void weirdAlgoSimulator(long long n) {
		cout << n << " ";
		if (n == 1) {
			return;
		}
		while (n != 1) {
			if (n & 1) {
				n = 3 * n + 1;
			}
			else {
				n /= 2;
			}
			cout << n << " ";
		}
		return;
	}
};

int main() {
	Solution test;
	long long n;
	cin >> n;
	test.weirdAlgoSimulator(n);
}