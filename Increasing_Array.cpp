#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	//to calculate number of moves required to make array sorted
	long long makeSorted(int n, vector<long long>&given) {

		long long totalMoves = 0, temp;

		for (int i = 1; i < n; i++) {
			//if already sorted then jump to next iteration
			if (given[i] >= given[i - 1])continue;

			//else calculating gap, which is to be filled
			temp = given[i - 1] - given[i];

			//filling the gap
			given[i] += temp;

			//updating moves;
			totalMoves += temp;
		}
		return totalMoves;
	}
};

int main() {
	Solution test;
	int n;
	cin >> n;
	vector<long long>given(n);
	for (int i = 0; i < n; i++) {
		cin >> given[i];
	}
	long long movesNeeded = test.makeSorted(n, given);
	cout << movesNeeded << "\n";
}