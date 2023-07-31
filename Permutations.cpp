#include<bits/stdc++.h>
using namespace std;
 
 
class Solution {
public:
 	//printing beautiful permutations
	void beautifulPermutations(int n) {
		if (n <= 3 && n != 1) {
			cout << "NO SOLUTION\n";
			return;
		}
		//printing all even number first in order since diff bwn 
		//them will always be 2
		for (int i = 1; i <= n; i++) {
			if (!(i & 1)) {
				cout << i << " ";
			}
		}
		//print all odd numbers in order
		//since diff bwn last even and first odd will be > 2
		for (int i = 1; i <= n; i++) {
			if (i & 1) {
				cout << i << " ";
			}
		}
		cout << "\n";
		return;
	}
};
 
int main() {
	Solution test;
	int n;
	cin >> n;
	test.beautifulPermutations(n);
}