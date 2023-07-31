#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countDistinct(int n, vector<int>&given) {
		sort(begin(given), end(given));
		int count = 0;
		for (int i = 0; i < n - 1; i++) {
			if (given[i] != given[i + 1])count++;
		}
		return count + 1;
	}
};

int main() {
	Solution test;
	int n;
	cin >> n;
	vector<int>given(n);
	for (int i = 0; i < n; i++) {
		cin >> given[i];
	}
	int distinctCount = test.countDistinct(n, given);
	cout << distinctCount << "\n";
}