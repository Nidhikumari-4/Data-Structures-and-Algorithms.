## [Rat in a Maze-I - #GFG](https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#)
### NOTE - In a path, no cell can be visited more than one time
```cpp
class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        if(m[0][0] == 1) solve(0,0,m,n, ans, "", vis); 
        return ans; 
    }
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, 
    vector<vector<int>> &vis) {
        if(i==n-1 && j==n-1) {
            ans.push_back(move);
            return; 
        }
        // downward
         if(i+1<n && !vis[i+1][j] && a[i+1][j] == 1) {
             vis[i][j] = 1; 
             solve(i+1, j, a, n, ans, move + 'D', vis);
             vis[i][j] = 0; 
         }
        
         // left
         if(j-1>=0 && !vis[i][j-1] && a[i][j-1] == 1) {
             vis[i][j] = 1; 
             solve(i, j-1, a, n, ans, move + 'L', vis);
             vis[i][j] = 0; 
         }
        
         // right 
         if(j+1<n && !vis[i][j+1] && a[i][j+1] == 1) {
             vis[i][j] = 1; 
             solve(i, j+1, a, n, ans, move + 'R', vis);
             vis[i][j] = 0; 
         }
        
         // upward
         if(i-1>=0 && !vis[i-1][j] && a[i-1][j] == 1) {
             vis[i][j] = 1; 
             solve(i-1, j, a, n, ans, move + 'U', vis);
             vis[i][j] = 0; 
         }
    
    }
};

```

## [Rat in a Maze-I - #GFG](https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#)  **Optimized Sol**


```cpp
class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        int di[] = {+1, 0, 0, -1}; 
        int dj[] = {0, -1, 1, 0}; 
        if(m[0][0] == 1) 
         fun(0,0,m,n, ans, "", vis,di,dj); 
        return ans; 
    }
    void fun(int i, int j, vector<vector<int>> &arr, int n, vector<string> &ans, string s, vector<vector<int>> &vis,
    int di[], int dj[]) {
        if(i==n-1 && j==n-1) {
            ans.push_back(s);
            return; 
        }
        
       string dir = "DLRU"; 
        for(int ind = 0; ind<4;ind++) {
            int nexti = i + di[ind]; 
            int nextj = j + dj[ind]; 
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && arr[nexti][nextj] == 1) {
                vis[i][j] = 1; 
                fun(nexti, nextj, arr, n, ans, s + dir[ind], vis, di, dj);
                vis[i][j] = 0; 
            }
        }
    }
};
```
