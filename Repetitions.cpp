#include<bits/stdc++.h>
using namespace std;


class Solution {
	int n;
public:
	//finding longest substring length with same char
	int findRepetitions(string s) {
		n = s.size();

		//edge case if string is made up of only 1 char eg: A,G,C,T etc;
		if (n == 1) {
			return n;
		}
		int length = 0, maxLength = -1;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) {
				length++;
			}
			//resetting substring length as char no longer same
			else {
				length = 0;
			}
			//updating max length
			if (maxLength < length) {
				maxLength = length;
			}
		}
		return maxLength + 1;
	}
};

int main() {
	Solution test;
	string s;
	cin >> s;
	int maxLength = test.findRepetitions(s);
	cout << maxLength << "\n";
}