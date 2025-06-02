// Unique Paths in a Grid
// You are given a 2d list grid[][] of size n x m consisting of values 0 and 1.
// A value of 0 means that you can enter that cell and 1 implies that entry to that cell is not allowed.
// You start at the upper-left corner of the grid (1, 1) and you have to reach the bottom-right corner (n, m) such that you can only move in the right or down direction from every cell.
// Your task is to calculate the total number of ways of reaching the target.

// Note: The first (1, 1) and last (n, m) cell of the grid can also be 1.
// It is guaranteed that the total number of ways will fit within a 32-bit integer.

// Examples:

// Input: n = 3, m = 3,
// grid[][] = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
// Output: 2
// Explanation: There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
class Solution {
  public:
    int ctr(vector<vector<int>> &g,int r,int c,int n,int m,vector<vector<int>> &dp)
    {
        if(r>=n ||c>=m)
            return 0;
        if(r==n-1 && c==m-1)
            return 1;
        if(g[r][c]==1)
            return 0;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int dow=ctr(g,r+1,c,n,m,dp);
        int right=ctr(g,r,c+1,n,m,dp);
        dp[r][c]=dow+right;
        return dp[r][c];
        
    }
    int uniquePaths(vector<vector<int>> &g) 
    {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        if(n==1 && m==1)
        {
            return g[0][0]?0:1;
        }
        ctr(g,0,0,n,m,dp);
        return dp[0][0];
        
    }
};