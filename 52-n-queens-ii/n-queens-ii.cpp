class Solution {
public:
    int count = 0;

    void solve(int col, int n,
               vector<int> &leftRow,
               vector<int> &upperDiag,
               vector<int> &lowerDiag) {

        if (col == n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {

            if (leftRow[row] == 0 &&
                lowerDiag[row + col] == 0 &&
                upperDiag[n - 1 + col - row] == 0) {

                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;

                solve(col + 1, n, leftRow, upperDiag, lowerDiag);

                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
            }
        }
    }

    int totalNQueens(int n) {

        vector<int> leftRow(n, 0);
        vector<int> upperDiag(2 * n - 1, 0);
        vector<int> lowerDiag(2 * n - 1, 0);

        solve(0, n, leftRow, upperDiag, lowerDiag);

        return count;
    }
};
