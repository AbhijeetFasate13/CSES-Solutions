#include<bits/stdc++.h>
using namespace std;


class Solution {
	//hashmap
	vector<int>hash;
public:
	//constructor to declare hashmap size
	Solution(): hash(2e5 + 10) {};

	//finding missing number
	int findMissingNumber(int n, vector<int>&given) {
		//stored numbers in the form of indices in hashmap
		for (int i = 0; i < given.size(); i++) {
			hash[given[i]]++;
		}
		//whichever number will have 0 frequency is our missing number
		int missing;
		for (int i = 1; i <= n; i++) {
			if (hash[i] == 0) {
				missing = i;
				break;
			}
		}
		return missing;
	}
};

int main() {
	Solution test;
	int n;
	cin >> n;
	vector<int>given(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> given[i];
	}
	int missingNumber = test.findMissingNumber(n, given);
	cout << missingNumber << "\n";
}