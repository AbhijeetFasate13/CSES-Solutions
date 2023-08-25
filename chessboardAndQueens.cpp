#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void solve(vector<vector<string>>&ans, vector<string>&board, int col, vector<int>&lowerDiag, vector<int>&upperDiag, vector<int>&leftRow) {
		//if reached to end column without
		//attacking any other previously placed
		//queen we include it in our answer
		if (col == board.size()) {
			ans.push_back(board);
			return;
		}
		for (int row = 0; row < board.size(); row++) {

			//if the place is reserved we continue
			if (board[row][col] == '*')continue;

			//check if a other queen is placed in its attack range
			if (leftRow[row] == 0 and lowerDiag[row + col] == 0 and upperDiag[board.size() - 1 + col - row] == 0) {
				//updating the vectors to store info
				//about placing a queen in row,col coordinates
				leftRow[row] = 1;
				lowerDiag[row + col] = 1;
				upperDiag[board.size() - 1 + col - row] = 1;

				//updating the board
				board[row][col] = 'Q';

				//calling recursive function
				solve(ans, board, col + 1, lowerDiag, upperDiag, leftRow);


				//backtracking and undoing the previously taken step
				leftRow[row] = 0;
				lowerDiag[row + col] = 0;
				upperDiag[board.size() - 1 + col - row] = 0;
				board[row][col] = '.';
			}
		}
	}
	vector<vector<string>>nQueens(vector<string>&board) {
		int n = board.size();
		vector<vector<string>>ans;

		//to check if the either of diagonals or 
		//the corresponding row has already a queen place
		vector<int>lowerDiag(2 * n - 1), upperDiag(2 * n - 1), leftRow(n);

		//calling the backtrack function
		solve(ans, board, 0, lowerDiag, upperDiag, leftRow);
		return ans;
	}
};

int main() {
	Solution test;

	//accepting the input
	vector<string>board(8);
	for (int i = 0; i < 8; i++) {
		cin >> board[i];
	}

	//storing all possible answers in a DS
	//and returning the size of calculated DS
	//as the final answer
	vector<vector<string>>ans = test.nQueens(board);
	cout << ans.size() << "\n";
}