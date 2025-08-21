2D Difference Array
Difficulty: MediumAccuracy: 70.93%Submissions: 5K+Points: 4Average Time: 14m
You are given a 2D integer matrix mat[][] of size n × m and a list of q operations opr[][]. Each operation is represented as an array [v, r1, c1, r2, c2], where:

v is the value to be added
(r1, c1) is the top-left cell of a submatrix
(r2, c2) is the bottom-right cell of the submatrix (inclusive)
For each of the q operations, add v to every element in the submatrix from (r1, c1) to (r2, c2). Return the final matrix after applying all operations.

Examples:

Input: mat[][] = [[1, 2, 3],  opr[][] = [[2, 0, 0, 1, 1], [-1, 1, 0, 2, 2]]
                [1, 1, 0],
                [4,-2, 2]]
Output: [[3, 4, 3],
        [2, 2, -1],
        [3, -3, 1]] 
Explanation: 
 class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,vector<vector<int>>& opr) 
    {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>a(n,vector<int>(m,0));
        for(auto op:opr)
        {
            int val = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            a[r1][c1]+=val;
            if(c2+1<m)
                a[r1][c2+1]-=val;
            if(r2+1<n)
                a[r2+1][c1]-=val;
            if(r2+1<n && c2+1<m)
                a[r2+1][c2+1]+=val;
        }
        //now calculate prifix sum row
         for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                a[i][j]+=a[i][j-1];
            }
        }
        //now calculate prifix sum col
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a[i][j]+=a[i-1][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j]+=a[i][j];
            }
        }
        return mat;
    }
};