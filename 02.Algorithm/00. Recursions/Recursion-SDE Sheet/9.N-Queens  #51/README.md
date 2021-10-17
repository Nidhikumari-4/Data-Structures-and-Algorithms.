## [51. N-Queens](https://leetcode.com/problems/n-queens/submissions/) - Approach 1
- ### [Video Reference](https://youtu.be/i05Ju7AftcM)
```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
        nQueen(0,board, ans, n); 
        return ans;  
    }
    // Placing queen
    void nQueen(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
        for(int row = 0;row<n;row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q'; 
                nQueen(col+1, board, ans, n); 
                board[row][col] = '.'; 
            }
        }
    }
   // checking if safe or not to place Q
    bool isSafe(int row, int col, vector<string> board, int n) { 
    //up digonal i--,j--
     for(int i=row,j=col;i>=0 && j>=0; i--,j--){
        if(board[i][j]=='Q') return false;
    }
    // left i,j--
    for(int i=row,j=col;i>=0 && j>=0; j--){
         if(board[i][j]=='Q') return false;
    }
    // down digonal i++, j-- 
    for(int i=row,j=col;i<n && j>=0; i++,j--){
        if(board[i][j]=='Q') return false;
    }
     return true;
    }
};
```
## [51. N-Queens](https://leetcode.com/problems/n-queens/submissions/) - Approach 2
- ### [Video Reference](https://youtu.be/i05Ju7AftcM)
 ### Here we have optimised isSafe() method instead of ittirating.We made 3 arrays to hash left, upLeftDigonal, downLeftDigonal so TC of isSafe() turns to O(1).
```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
        // create hash for 3 directions.
        vector<int> leftRow(n, 0); 
        vector<int> upperDiagonal(2 * n - 1, 0); 
        vector<int> lowerDiagonal(2 * n - 1, 0); 
        nQueen(0,board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
        return ans; 
    }
    
    void nQueen(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow,  vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(leftRow[row]==0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n-1 + col - row] == 0) {
                
                board[row][col] = 'Q'; 
                leftRow[row] = 1; 
                lowerDiagonal[row+col] = 1; 
                upperDiagonal[n-1 + col - row] =1;
                nQueen(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
                board[row][col] = '.'; 
                leftRow[row] = 0; 
                lowerDiagonal[row+col] = 0; 
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }
};
```
