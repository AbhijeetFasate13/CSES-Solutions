#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	int n;

	//hash map to store frequency of char in the given string
	vector<int>alpha;

	//function to check whether if palindrome possible or not
	bool canPalindrome(string s) {
		n = s.size();
		for (int i = 0; i < n; i++) {
			alpha[s[i] - 'A']++;
		}
		int oddCount = 0;
		for (int i = 0; i < 26; i++) {
			if (alpha[i] & 1)oddCount++;
		}
		return oddCount <= 1;
	}
public:
	//constructor to delcare hashmap size
	Solution() : alpha(26) {};

	//function to create a palindromic string
	string makePalindrome(string s) {
		n = s.size();

		//checking if it can become a palindrome?
		if (!canPalindrome(s)) {
			return "NO SOLUTION";
		}

		//to store half of palindrome string
		string palOfS = "";

		//in case of a char which occurs once, to be place in middle
		char needed;
		//to answer if middle character exits;
		int flag = 0;
		for (int i = 0; i < 26; i++) {
			//retrieve the middle char (if any)
			if (alpha[i] & 1) {
				needed = 'A' + i;
				flag = 1;
				// continue;
				alpha[i]--;
			}

			int temp = alpha[i];

			char c = 'A' + i;
			//making first half of palindrome
			while (alpha[i] != temp / 2) {
				palOfS += c;
				alpha[i]--;
			}
		}

		//getting the second half
		string revPalOfS = palOfS;
		reverse(revPalOfS.begin(), revPalOfS.end());
		//to check if middle char exists, if so then appended and returned
		if (flag)
			return palOfS + needed + revPalOfS;
		return palOfS + revPalOfS;
	}

};

int main() {

	Solution test;

	string s;
	cin >> s;

	cout << test.makePalindrome(s) << "\n";
}