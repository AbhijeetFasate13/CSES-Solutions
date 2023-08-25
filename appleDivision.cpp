#include<bits/stdc++.h>
using namespace std;
#define int long long

class Solution {
	//calculating total sum first!
	int sum = 0;

	int min_diff = 1e9 + 7;

	//helper function
	void minSubSeqSum(vector<int>&given, int i, int carrySum) {
		//when reach final index update minimum sum difference
		if (i == given.size()) {

			//1.sum will contain all values picked
			//2.In order to make two division we find such subseq
			//such that sum - 2*carrySum is minimum
			//because if carrySum is one possible division
			//since, sum has already included whatever
			//carrySum has included we deduct it first
			//now the Sum will be our second division
			//now we calculate the abs difference of Sum - carrySum
			//if its minimum then previously obtained minimum
			//then we update
			//hence the below formula
			min_diff = min(abs(sum - 2 * carrySum), min_diff);
			return;
		}

		//generating all subseq possible by either PICKING
		minSubSeqSum(given, i + 1, carrySum + given[i]);

		//and by NOT PICKING
		minSubSeqSum(given, i + 1, carrySum);
	}
public:
	int appleDivison(vector<int>&given) {
		for (auto i : given)sum += i;
		minSubSeqSum(given, 0, 0);
		return min_diff;
	}
};

int32_t main() {
	Solution test;

	//accepting the input
	int n;
	cin >> n;
	vector<int>given(n);
	for (int i = 0; i < n; i++) {
		cin >> given[i];
	}

	//calculating the answer
	int min_diff = test.appleDivison(given);
	cout << min_diff << "\n";
}